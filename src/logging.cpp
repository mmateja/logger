#include "logging.h"

Logger Logging::get_logger(const char *logger_name) {
	static Worker worker;
	return Logger(worker, logger_name);
}
