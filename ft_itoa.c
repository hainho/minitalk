#include "ft_minitalk.h"

static int	ft_itoasize(int n)
{
	int	size;

	if (n == 0)
		return (1);
	size = 0;
	if (n < 0)
		size++;
	while (n)
	{
		n /= 10;
		size++;
	}
	return (size);
}

static char	*ft_rec_itoa(long long n, char *dst)
{
	if (n == 0)
		return (dst);
	if (n > 0)
	{
		dst = ft_rec_itoa(n / 10, dst);
		*dst = n % 10 + '0';
	}
	return (dst + 1);
}

char		*ft_itoa(int n)
{
	char		*dst;
	char		*temp;
	int			size;
	long long	m;

	m = n;
	size = ft_itoasize(n);
	if (n < 0)
		m *= -1;
	dst = malloc(size + 1);
	if (dst == NULL)
		return (NULL);
	temp = dst;
	if (n < 0)
		*dst++ = '-';
	if (n == 0)
		*dst++ = '0';
	dst = ft_rec_itoa(m, dst);
	*dst = 0;
	return (temp);
}