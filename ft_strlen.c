#include "ft_minitalk.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*s++ != 0)
		len++;
	return (len);
}
