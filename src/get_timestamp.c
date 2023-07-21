#include "output.h"

u_int64_t	get_timestamp(void)
{
	struct timeval	b;

	gettimeofday(&b, NULL);
	return (b.tv_sec * 1000 + b.tv_usec / 1000);
}