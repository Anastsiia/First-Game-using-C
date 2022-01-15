#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		i;
	int		a;
	int		len1;
	int		len2;

	i = 0;
	a = 0;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	res = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (res == NULL)
		return (NULL);
	while (i < len1)
	{
		res[i] = s1[i];
		i++;
	}
	while (i < (len1 + len2))
	{
		res[i++] = s2[a++];
	}
	res[i] = '\0';
	return (res);
}
