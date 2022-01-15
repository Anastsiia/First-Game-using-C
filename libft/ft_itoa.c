#include "libft.h"

int	ft_lenint(int n)
{
	int	len;

	len = 0;
	if (n < 0)
		len = 1;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		len;
	int		sign;

	sign = 0;
	len = ft_lenint(n);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (res == NULL)
		return (NULL);
	res[len] = '\0';
	if (n < 0)
		res[sign++] = '-';
	while (len > sign)
	{
		if (n < 0)
			res[(len--) - 1] = -(n % 10) + '0';
		else
			res[(len--) - 1] = (n % 10) + '0';
		n = n / 10;
	}
	return (res);
}
