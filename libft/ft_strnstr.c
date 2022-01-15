#include "libft.h"

char	*ft_strnstr(const char *str, const char *src, size_t len)
{
	char	*d;
	char	*s;
	char	*res;
	size_t	i;
	int		a;

	i = 0;
	a = 0;
	d = (char *)str;
	s = (char *)src;
	res = NULL;
	if (d == s || ft_strlen(s) == 0)
		return (d);
	while (d[i] != '\0' && i < len)
	{
		a = 0;
		while (d[i + a] == s[a] && (i + a) < len && s[a] != '\0')
		{
			a++;
		}
		if (s[a] == '\0')
			return (&d[i]);
		i++;
	}
	return (res);
}
