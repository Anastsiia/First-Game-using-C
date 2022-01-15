#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*res;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(s);
	res = (char *)malloc((len + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
