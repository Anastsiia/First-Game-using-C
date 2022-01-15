#include "libft.h"

char	*ft_strchr(const char *str1, int c)
{
	char	*res;
	int		i;

	i = 0;
	while (str1[i] != (char)c && str1[i] != '\0')
		i++;
	if (str1[i] == (char)c || str1[i] != '\0' || !str1)
		res = (char *)str1 + i;
	else
		res = NULL;
	return (res);
}
