#ifndef LOG_LEVEL_H
#define LOG_LEVEL_H

#include<string>

enum LogLevel {
	DEBUG,
	INFO,
	WARNING,
	ERROR
};

class LogLevelHelper {
public:
	static const std::string string(LogLevel level);
};

#endif /* LOG_LEVEL_H */
