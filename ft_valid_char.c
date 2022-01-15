#include "so_long.h"

int	ft_cmpch(char c, char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (c == str[i])
			return (0);
		i++;
	}
	return (1);
}

int	ft_valid_char(char c)
{
	char	*str;
	int		i;

	i = 0;
	str = "10PEC";
	while (str[i] != '\0')
	{
		if (c == str[i])
			return (0);
		i++;
	}
	return (1);
}
