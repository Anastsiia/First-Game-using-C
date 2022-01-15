#include "so_long.h"

char	*get_next_line(int fd)
{
	int			read_byte;
	static char	*balance;
	char		*point;
	char		*res;

	res = NULL;
	read_byte = 1;
	point = NULL;
	if (fd < 0)
		return (NULL);
	if (balance)
		ft_find_n(&point, &balance, &res);
	if (point == NULL)
		read_byte = ft_read_file(&point, &balance, &res, fd);
	if (read_byte == 0)
	{
		if (balance && *balance != '\0')
		{
			res = ft_strdup_new(balance, 1);
			free(balance);
			balance = NULL;
		}
	}
	return (res);
}

int	ft_count_lines(char *argv)
{
	int		fd;
	int		count;
	int		out;
	char	c;

	fd = open(argv, O_RDONLY);
	if (!fd)
		return (-1);
	count = 1;
	out = 1;
	while (out != 0)
	{
		out = read(fd, &c, 1);
		if (out == -1)
			return (-1);
		if (c == '\n')
			count++;
	}
	close(fd);
	return (count);
}

int	ft_memory_allocate(char *argv, t_game *game)
{
	game->map_line = ft_count_lines(argv);
	game->map = malloc(sizeof(char *) * game->map_line + 1);
	if (game->map == NULL)
		return (1);
	return (0);
}

int	ft_read_map(char *argv, t_game *game)
{
	int		fd;
	int		i;

	i = 0;
	ft_memory_allocate(argv, game);
	if (game->map == NULL)
		return (1);
	fd = open(argv, O_RDONLY);
	if (!fd)
		return (1);
	game->map[i] = get_next_line(fd);
	while (game->map[i++])
		game->map[i] = get_next_line(fd);
	game->map[i] = NULL;
	return (0);
}
