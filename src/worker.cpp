#include "worker.h"

Worker::Worker() :
	thread(&Worker::thread_main, this),
	file_writer("log.txt") {
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
		write_message(content);
	}
}

void Worker::write_message(LoggingContent &message) {
	console_writer.write(message);
	file_writer.write(message);
}

void Worker::thread_main() {
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
		write_message(content);
	}
}

Worker::~Worker() {
	{
		std::lock_guard<std::mutex> lock(run_mutex);
		run_worker_thread = false;
	}
	thread.join();
}
