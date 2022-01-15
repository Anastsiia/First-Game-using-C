#include "so_long.h"

int	ft_press_w(t_game *game)
{
	if (game->map[game->player_place.x - 1][game->player_place.y] == '1')
		return (1);
	else if (game->map[game->player_place.x - 1][game->player_place.y] == '0')
		ft_move_up(game);
	else if (game->map[game->player_place.x - 1][game->player_place.y] == 'C')
	{
		ft_move_up(game);
		game->apples--;
	}
	else if (game->map[game->player_place.x - 1][game->player_place.y] == 'B')
		ft_end(game, 1);
	else
	{
		if (game->apples == 0)
		{
			ft_print_msg(ft_itoa(++game->moves), 1, 1);
			ft_end_msg(game, "WIN");
		}
		else
			ft_move_up_r(game);
	}
	return (0);
}

int	ft_press_s(t_game *game)
{
	if (game->map[game->player_place.x + 1][game->player_place.y] == '1')
		return (1);
	else if (game->map[game->player_place.x + 1][game->player_place.y] == '0')
		ft_move_down(game);
	else if (game->map[game->player_place.x + 1][game->player_place.y] == 'C')
	{
		ft_move_down(game);
		game->apples--;
	}
	else if (game->map[game->player_place.x + 1][game->player_place.y] == 'B')
		ft_end(game, 1);
	else
	{
		if (game->apples == 0)
		{
			ft_print_msg(ft_itoa(++game->moves), 1, 1);
			ft_end_msg(game, "WIN");
		}
		else
			ft_move_down_r(game);
	}
	return (0);
}

int	ft_press_a(t_game *game)
{
	if (game->map[game->player_place.x][game->player_place.y - 1] == '1')
		return (1);
	else if (game->map[game->player_place.x][game->player_place.y - 1] == '0')
		ft_move_left(game);
	else if (game->map[game->player_place.x][game->player_place.y - 1] == 'C')
	{
		ft_move_left(game);
		game->apples--;
	}
	else if (game->map[game->player_place.x][game->player_place.y - 1] == 'B')
		ft_end(game, 1);
	else
	{
		if (game->apples == 0)
		{
			ft_print_msg(ft_itoa(++game->moves), 1, 1);
			ft_end_msg(game, "WIN");
		}
		else
			ft_move_left_r(game);
	}
	return (0);
}

int	ft_press_d(t_game *game)
{
	if (game->map[game->player_place.x][game->player_place.y + 1] == '1')
		return (1);
	else if (game->map[game->player_place.x][game->player_place.y + 1] == '0')
		ft_move_right(game);
	else if (game->map[game->player_place.x][game->player_place.y + 1] == 'C')
	{
		ft_move_right(game);
		game->apples--;
	}
	else if (game->map[game->player_place.x][game->player_place.y + 1] == 'B')
		ft_end(game, 1);
	else
	{
		if (game->apples == 0)
		{
			ft_print_msg(ft_itoa(++game->moves), 1, 1);
			ft_end_msg(game, "WIN");
		}
		else
			ft_move_right_r(game);
	}
	return (0);
}
