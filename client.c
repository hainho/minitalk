#include "ft_minitalk.h"

static void	send_signal(int pid, char c){
	int	temp;

	temp = 0;
	while (temp < 8)
	{
		if (c < 0)
		{
			if (kill(pid, SIGUSR1) == -1)
				write(1, "siguser1err\n", 12);
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				write(1, "siguser2err\n", 12);
		}
		temp++;
		c = c << 1;
		usleep(600);
	}
}

int			main(int argc, const char **argv)
{
	int		pid;
	int		ptr;
	char	c;

	if (argc != 3)
		return 0;
	pid = ft_atoi(argv[1]);
	ptr = 0;
	while (argv[2][ptr])
	{
		c = argv[2][ptr++];
		send_signal(pid, c);
	}
	return 0;
}