#include "logging.h"

std::shared_ptr<Logger> Logging::get_logger(const char *logger_name) {
	static Worker worker;
	return std::make_shared<Logger>(worker, logger_name);
}
