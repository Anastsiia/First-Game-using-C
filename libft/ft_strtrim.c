#include "libft.h"

int	ft_check(char a, const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == a)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	int		len;
	int		start;

	start = 0;
	if (!s1 || !set)
		return (NULL);
	len = ft_strlen(s1);
	while ((ft_check(s1[start], set)) == 1)
		start++;
	while (((ft_check(s1[len - 1], set)) == 1) && len >= start)
		len--;
	res = ft_substr((char *)s1, start, ((len - start)));
	return (res);
}
