#include "log_level.h"

const std::string LogLevelHelper::string(LogLevel level) {
	switch(level) {
	case LogLevel::DEBUG:
		return "DEBUG";
	case LogLevel::INFO:
			return "INFO";
	case LogLevel::WARNING:
			return "WARN";
	case LogLevel::ERROR:
			return "ERROR";
	default:
		return "";
	}
}
