#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	minus;

	minus = '-';
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
	}
	else if (n >= 0 && n <= 9)
	{
		n = n + '0';
		write(fd, &n, 1);
	}
	else if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else
	{
		n = -n;
		write(fd, &minus, 1);
		ft_putnbr_fd(n, fd);
	}
}
