#include "so_long.h"

int	ft_check_walls(t_game *game)
{
	int	a;

	a = 0;
	while (a < game->map_width)
	{
		if (ft_cmpch(game->map[0][a], "1E") == 1 ||
				ft_cmpch(game->map[game->map_line - 1][a], "1E") == 1)
			return (1);
		a++;
	}
	a = 0;
	while (a < game->map_line)
	{
		if (ft_cmpch(game->map[a][0], "1E") ||
				ft_cmpch(game->map[a][game->map_width - 1], "1E"))
			return (1);
		a++;
	}
	return (0);
}

void	ft_count_characters(t_game *game)
{
	int	i;
	int	a;

	i = 0;
	while (i < game->map_line)
	{
		a = 0;
		while (a < game->map_width)
		{
			if (game->map[i][a] == 'P')
			{
				game->valid.player++;
				game->player_place.x = i;
				game->player_place.y = a;
			}
			else if (game->map[i][a] == 'E')
				game->valid.exit++;
			else if (game->map[i][a] == 'C')
				(game->apples)++;
			a++;
		}
		i++;
	}
	if (game->valid.player != 1 || game->valid.exit < 1 || game->apples == 0)
		ft_end_msg(game, "Map must have at least one 'E','C', and one 'P'.\n");
}

int	ft_check_characters(t_game *game)
{
	int	i;
	int	a;

	i = 0;
	while (i < game->map_line)
	{
		a = 0;
		while (a < game->map_width)
		{
			if (ft_valid_char(game->map[i][a]) == 1)
				ft_end_msg(game, "Invalid characters\n");
			a++;
		}
		i++;
	}
	return (0);
}

int	ft_check_rectangular(t_game *game)
{
	int	l;
	int	a;

	l = 1;
	game->map_width = 0;
	while (game->map[0][game->map_width] != '\n')
		game->map_width++;
	while (l < game->map_line)
	{
		a = 0;
		while (game->map[l][a] != '\n' && game->map[l][a] != '\0')
				a++;
		if ((a) != game->map_width && (game->map[l][a] != '\n' && a != 0))
			ft_end_msg(game, "The map must be rectangular\n");
		l++;
	}
	return (0);
}

int	ft_check_valid(t_game *game)
{
	if (ft_check_rectangular(game) == 1 || ft_check_characters(game) == 1)
		return (1);
	ft_count_characters(game);
	if (ft_check_walls(game) == 1)
	{
		ft_print_msg("The map must be closed/surrounded by walls.\n", 0, 0);
		return (1);
	}
	return (0);
}
