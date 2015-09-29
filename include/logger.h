#ifndef LOGGER_H
#define LOGGER_H

#include "log_level.h"
#include "worker.h"
#include "logging_content.h"

#include "format.h"

#include<memory>
#include<iostream>
#include<iomanip>
#include<chrono>

class Logger {
	const char *name;
	Worker& worker;

	template <typename... Args>
	inline std::string format_message(LogLevel level, const char *pattern, const Args&... args) {
		std::string message = fmt::format(pattern, args...);
		return fmt::format("{}\t{}\t{}\t{}", time_string(), LogLevelHelper::string(level), name, message);
	}

	template <typename... Args>
	inline void log(LogLevel level, const char *pattern, const Args&... args) {
		LoggingContent content;
		content.message = format_message(level, pattern, args...);
		worker.log(content);
	}

	std::string time_string();

public:
	Logger(Worker &worker, const char *name);

	template <typename... Args>
	inline void debug(const char *pattern, const Args&... args) {
		log(LogLevel::DEBUG, pattern, args...);
	}

	template <typename... Args>
	inline void info(const char *pattern, const Args&... args) {
		log(LogLevel::INFO, pattern, args...);
	}

	template <typename... Args>
	inline void warning(const char *pattern, const Args&... args) {
		log(LogLevel::WARNING, pattern, args...);
	}

	template <typename... Args>
	inline void error(const char *pattern, const Args&... args) {
		log(LogLevel::ERROR, pattern, args...);
	}
};

#endif /* LOGGER_H */
