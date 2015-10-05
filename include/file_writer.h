#ifndef FILE_WRITER_H
#define FILE_WRITER_H

#include "writer.h"
#include "logging_content.h"

#include <fstream>

class FileWriter: public Writer {
	std::ofstream stream;
public:
	FileWriter(const char *file_path);
	void write(LoggingContent &message);
	~FileWriter();
};

#endif /* FILE_WRITER_H */
