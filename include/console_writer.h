#ifndef CONSOLE_WRITER_H
#define CONSOLE_WRITER_H

#include "writer.h"

class ConsoleWriter : public Writer {
public:
	void write(LoggingContent &message) override;
};

#endif /* CONSOLE_WRITER_H */
