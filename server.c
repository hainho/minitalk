#include "ft_minitalk.h"

static void	sig_handler(int signo)
{
	static int	count;
	static char	c;

	c = c << 1;
	count++;
	if (signo == SIGUSR1)
		c += 1;
	if (count == 8)
	{
		count = 0;
		write(1, &c, 1);
		c = 0;
	}
}

int	main(void)
{
	int		p;
	char	*pid;

	signal(SIGUSR1, sig_handler);
	signal(SIGUSR2, sig_handler);
	p = getpid();
	pid = ft_itoa(p);
	write(1, "pid : ", 6);
	write(1, pid, ft_strlen(pid));
	write(1, "\n", 1);
	free(pid);
	while (1)
		sleep(1000);
	return (0);
}
