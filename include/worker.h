#ifndef WORKER_H
#define WORKER_H

#include "logging_content.h"
#include "console_writer.h"
#include "file_writer.h"

#include<thread>
#include<mutex>
#include<condition_variable>
#include<queue>

class Worker {
	bool run_worker_thread = true;
	std::thread thread;
	std::mutex run_mutex;
	std::mutex queue_mutex;
	std::condition_variable queue_condition;
	std::queue<LoggingContent> queue;
	ConsoleWriter console_writer;
	FileWriter file_writer;

	void flush();
	void write_message(LoggingContent &message);
	void thread_main();
public:
	Worker();
	void log(LoggingContent &message);
	~Worker();
};

#endif /* WORKER_H */
