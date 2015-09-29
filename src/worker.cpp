#include "worker.h"

Worker::Worker() : thread(&Worker::threadMain, this) {
}

void Worker::log(LoggingContent &content) {
	std::lock_guard<std::mutex> lock(queue_mutex);
	queue.push(content);
	queue_condition.notify_one();
}

void Worker::flush() {
	LoggingContent content;
	while(!queue.empty()) {
		content = queue.front();
		queue.pop();
		console_writer.write(content);
	}
}

void Worker::threadMain() {
	LoggingContent content;
	while(true) {
		{
			std::lock_guard<std::mutex> lock(run_mutex);
			if(!run_worker_thread) {
				flush();
				break;
			}
		}

		{
			std::unique_lock<std::mutex> lock(queue_mutex);
			queue_condition.wait_for(lock, std::chrono::seconds(1), [this]{ return !queue.empty(); });
			if(queue.empty()) {
				continue;
			}
			content = queue.front();
			queue.pop();
		}
		console_writer.write(content);
	}
}

Worker::~Worker() {
	{
		std::lock_guard<std::mutex> lock(run_mutex);
		run_worker_thread = false;
	}
	thread.join();
}
