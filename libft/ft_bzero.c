#include "libft.h"

void	ft_bzero(void *arr, size_t i)
{
	int		x;
	char	*p;

	x = 0;
	p = (char *)arr;
	while (i > 0)
	{
		*p = 0;
		i--;
		p++;
	}
}
