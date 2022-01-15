#include "so_long.h"

int	ft_end(t_game *game, int end)
{
	int	i;

	i = 0;
	while (game->map[i])
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
	if (end == 1)
		ft_print_msg("GAME OVER", 1, 0);
	exit(0);
}

int	ft_end_msg(t_game *game, char *str)
{
	ft_print_msg(str, 0, 0);
	ft_end(game, 0);
	exit(0);
}

int	ft_key(int key, t_game *game)
{
	if (key == 53)
		ft_end(game, 0);
	if (key == 13)
		ft_press_w(game);
	if (key == 0)
		ft_press_a(game);
	if (key == 1)
		ft_press_s(game);
	if (key == 2)
		ft_press_d(game);
	return (0);
}

void	ft_init_img(t_game *game)
{
	game->wall.img = mlx_xpm_file_to_image(game->mlx,
			WALL, &game->wall.size.x, &game->wall.size.y);
	game->grass.img = mlx_xpm_file_to_image(game->mlx,
			GRASS, &game->grass.size.x, &game->grass.size.y);
	game->player.img = mlx_xpm_file_to_image(game->mlx,
			PLAYER, &game->player.size.x, &game->player.size.y);
	game->exit.img = mlx_xpm_file_to_image(game->mlx,
			EXIT, &game->exit.size.x, &game->exit.size.y);
	game->collectable.img = mlx_xpm_file_to_image(game->mlx,
			APPLE, &game->collectable.size.x, &game->collectable.size.y);
	game->player_exit.img = mlx_xpm_file_to_image(game->mlx,
			PLAYER_EXIT, &game->player_exit.size.x, &game->player_exit.size.y);
	game->enemy.img = mlx_xpm_file_to_image(game->mlx,
			ENEMY, &game->enemy.size.x, &game->enemy.size.y);
}

void	ft_init_win(t_game *game)
{
	int	w;
	int	l;

	l = game->map_line;
	w = game->map_width;
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, 64 * w, 64 * l, "So long!");
	ft_init_img(game);
	ft_fill_map(game);
	mlx_hook(game->win, 17, 0, ft_end, game);
	mlx_hook(game->win, 2, 0, ft_key, (void *)game);
}
