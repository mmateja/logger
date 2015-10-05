#ifndef LOGGING_H
#define LOGGING_H

#include "logger.h"

class Logging {
public:
	static Logger get_logger(const char *logger_name = "main");
};

#endif /* LOGGING_H */
