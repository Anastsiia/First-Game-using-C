#include "so_long.h"

char	*ft_strchr_new(const char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		return ((char *)str + i);
	else
		return (NULL);
}

char	*ft_strdup_new(const char *str, int flag)
{
	char	*str1;
	int		len;
	int		a;

	len = ft_strlen(str);
	a = 0;
	str1 = (char *)malloc(sizeof(char) * (len + flag));
	if (!str1)
		return (NULL);
	while (a < len)
	{
		str1[a] = str[a];
		a++;
	}
	if (flag == 2)
		str1[a++] = '\n';
	str1[a] = '\0';
	return (str1);
}

static void	ft_unit(char **balance, char *buffer)
{
	char	*tmp;

	tmp = *balance;
	*balance = ft_strjoin(*balance, buffer);
	free (tmp);
}

void	ft_find_n(char **point, char **balance, char **res)
{
	char	*tmp;

	*point = ft_strchr_new(*balance);
	if (*point)
	{
		tmp = *balance;
		**point = '\0';
		(*point)++;
		*res = ft_strdup_new(*balance, 2);
		*balance = ft_strdup_new(*point, 1);
		free(tmp);
	}
}

int	ft_read_file(char **point, char **balance, char **res, int fd)
{
	char	*buffer;
	int		read_byte;

	read_byte = 1;
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (-1);
	while (read_byte && *point == NULL )
	{
		read_byte = read(fd, buffer, BUFFER_SIZE);
		if (read_byte == 0)
		{
			free(buffer);
			return (0);
		}
		buffer[read_byte] = '\0';
		if (*balance)
			ft_unit(balance, buffer);
		else
			*balance = ft_strdup_new(buffer, 1);
		ft_find_n(point, balance, res);
	}	
	free (buffer);
	return (read_byte);
}
