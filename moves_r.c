#include "so_long.h"

void	ft_move_up_r(t_game *game)
{
	game->map[game->player_place.x][game->player_place.y] = '0';
	game->player_place.x = game->player_place.x - 1;
	game->map[game->player_place.x][game->player_place.y] = 'R';
	ft_print_msg(ft_itoa(++game->moves), 1, 1);
	game->back = 'E';
}

void	ft_move_right_r(t_game *game)
{
	game->map[game->player_place.x][game->player_place.y] = '0';
	game->player_place.y = game->player_place.y + 1;
	game->map[game->player_place.x][game->player_place.y] = 'R';
	ft_print_msg(ft_itoa(++game->moves), 1, 1);
	game->back = 'E';
}

void	ft_move_left_r(t_game *game)
{
	game->map[game->player_place.x][game->player_place.y] = '0';
	game->player_place.y = game->player_place.y - 1;
	game->map[game->player_place.x][game->player_place.y] = 'R';
	ft_print_msg(ft_itoa(++game->moves), 1, 1);
	game->back = 'E';
}

void	ft_move_down_r(t_game *game)
{
	game->map[game->player_place.x][game->player_place.y] = '0';
	game->player_place.x = game->player_place.x + 1;
	game->map[game->player_place.x][game->player_place.y] = 'R';
	ft_print_msg(ft_itoa(++game->moves), 1, 1);
	game->back = 'E';
}
