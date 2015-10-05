#include "file_writer.h"

FileWriter::FileWriter(const char *file_path) :
	stream(file_path, std::ios_base::app | std::ios_base::out) {
	stream << std::endl << std::endl;
}

void FileWriter::write(LoggingContent &message) {
	stream << message.message << std::endl;
}

FileWriter::~FileWriter() {
	stream.flush();
	stream.close();
}
