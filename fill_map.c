#include "so_long.h"

void	ft_print_str(t_game *game, int x, int y)
{
	char	*str;

	str = ft_itoa(game->moves);
	mlx_string_put(game->mlx, game->win, x, y, 0x0000FF00, str);
	free(str);
}

void	ft_print_img(t_game *game, int x, int y, void *img)
{
	mlx_put_image_to_window(game->mlx, game->win, img, 64 * x, 64 * y);
}

int	ft_print_10p(t_game *game, int x, int y)
{
	if (ft_cmpch(game->map[y][x], "10P") == 0)
	{
		if (game->map[y][x] == '1')
			ft_print_img(game, x, y, game->wall.img);
		if (game->map[y][x] == '0')
			ft_print_img(game, x, y, game->grass.img);
		if (game->map[y][x] == 'P')
			ft_print_img(game, x, y, game->player.img);
		return (0);
	}
	return (1);
}

int	ft_print_cerb(t_game *game, int x, int y)
{
	if (ft_cmpch(game->map[y][x], "CERB") == 0)
	{
		if (game->map[y][x] == 'C')
			ft_print_img(game, x, y, game->collectable.img);
		if (game->map[y][x] == 'E')
			ft_print_img(game, x, y, game->exit.img);
		if (game->map[y][x] == 'R')
			ft_print_img(game, x, y, game->player_exit.img);
		if (game->map[y][x] == 'B')
			ft_print_img(game, x, y, game->enemy.img);
		return (0);
	}
	return (1);
}

void	ft_fill_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map_line)
	{
		x = 0;
		while (x < game->map_width)
		{
			if (ft_print_10p(game, x, y) == 1)
				ft_print_cerb(game, x, y);
			x++;
		}
		y++;
	}
	ft_print_str(game, (game->map_width - 1) * 64, game->map_line);
}
