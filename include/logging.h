#ifndef LOGGING_H
#define LOGGING_H

#include "logger.h"

#include<memory>

class Logging {
public:
	static std::shared_ptr<Logger> get_logger(const char *logger_name = "main");
};

#endif /* LOGGING_H */
