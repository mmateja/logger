#include <chrono>
#include <thread>
#include "logging.h"

int main() {
	auto logger = Logging::get_logger("logger no. 1");
	auto logger2 = Logging::get_logger("logger no. 2");

	for (int i = 0; i < 10; ++i) {
		logger->info("Message number {} by first logger", i);
		logger2->error("Second logger");
		std::this_thread::sleep_for(std::chrono::milliseconds(200));
	}
	return 0;
}
