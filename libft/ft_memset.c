#include "libft.h"

void	*ft_memset(void *arr, int c, size_t i)
{
	int		x;
	char	*p;

	x = 0;
	p = (char *)arr;
	while (i > 0)
	{
		p[x] = c;
		i--;
		x++;
	}
	return (arr);
}
