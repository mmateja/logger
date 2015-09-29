#ifndef WRITER_H
#define WRITER_H

#include "logging_content.h"

class Writer {
public:
	virtual void write(LoggingContent &message) = 0;
	virtual ~Writer() {};
};

#endif /* WRITER_H */
