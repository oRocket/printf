#include "main.h"

int _write(int fd, const void *buf, size_t count) 
{
	return (write(fd, buf, count));
}
