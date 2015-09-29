#include "console_writer.h"

#include<iostream>

void ConsoleWriter::write(LoggingContent &message) {
	std::cout << message.message << std::endl;
}
