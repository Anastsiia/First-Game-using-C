#include "libft.h"

void	*ft_memchr(const void *str1, int c, size_t n)
{
	char	*str;
	size_t	a;

	str = (char *)str1;
	a = 0;
	while (a < n)
	{
		if ((unsigned char)str[a] == (unsigned char)c)
			return ((char *)str + a);
		a++;
	}
	return (NULL);
}
