#include "so_long.h"

int	ft_print_msg(char *msg, int flag, int f)
{
	int		i;

	i = 0;
	while (msg[i] != '\0')
	{
		write(1, &msg[i], 1);
		i++;
	}
	if (f == 1)
		free(msg);
	if (flag == 1)
		write(1, "\n", 1);
	return (0);
}

int	ft_update(t_game *game)
{
	if (game->animation < 32 || (game->animation > 64 && game->animation < 98))
	{
		game->collectable.img = mlx_xpm_file_to_image(game->mlx,
				APPLE, &game->collectable.size.x, &game->collectable.size.y);
	}
	else
	{
		game->collectable.img = mlx_xpm_file_to_image(game->mlx,
				APPLE_2, &game->collectable.size.x, &game->collectable.size.y);
	}
	game->animation++;
	if (game->animation % 64 == 0)
	{
		game->enemy.img = mlx_xpm_file_to_image(game->mlx,
				ENEMY_2, &game->collectable.size.x, &game->collectable.size.y);
	}	
	mlx_clear_window(game->mlx, game->win);
	ft_fill_map(game);
	if (game->animation == 128)
			game->animation = 0;
	game->enemy.img = mlx_xpm_file_to_image(game->mlx,
			ENEMY, &game->collectable.size.x, &game->collectable.size.y);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (0);
	game.animation = 0;
	game.moves = 0;
	game.apples = 0;
	game.back = '0';
	game.valid.exit = 0;
	game.valid.player = 0;
	if (ft_check_args(argc, argv) == 1 || ft_read_map(argv[1], &game) == 1)
		return (0);
	if (ft_check_valid(&game) == 1)
		return (0);
	ft_init_win(&game);
	mlx_loop_hook(game.mlx, ft_update, (void *)&game);
	mlx_loop(game.mlx);
	return (0);
}
