#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t	res;
	size_t	i;

	if (!dest || !src)
		return ((size_t) NULL);
	res = ft_strlen(src);
	i = 0;
	while (i < (n - 1) && src[i] != '\0' && n != 0)
	{
		dest[i] = src[i];
		i++;
	}
	if (n != 0)
		dest[i] = '\0';
	return (res);
}
