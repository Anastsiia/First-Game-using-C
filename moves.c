#include "so_long.h"

void	ft_move_down(t_game *game)
{
	game->map[game->player_place.x][game->player_place.y] = game->back;
	game->player_place.x = game->player_place.x + 1;
	game->map[game->player_place.x][game->player_place.y] = 'P';
	ft_print_msg(ft_itoa(++game->moves), 1, 1);
	game->back = '0';
}

void	ft_move_left(t_game *game)
{
	game->map[game->player_place.x][game->player_place.y] = game->back;
	game->player_place.y = game->player_place.y - 1;
	game->map[game->player_place.x][game->player_place.y] = 'P';
	ft_print_msg(ft_itoa(++game->moves), 1, 1);
	game->back = '0';
}

void	ft_move_right(t_game *game)
{
	game->map[game->player_place.x][game->player_place.y] = game->back;
	game->player_place.y = game->player_place.y + 1;
	game->map[game->player_place.x][game->player_place.y] = 'P';
	ft_print_msg(ft_itoa(++game->moves), 1, 1);
	game->back = '0';
}

void	ft_move_up(t_game *game)
{
	game->map[game->player_place.x][game->player_place.y] = game->back;
	game->player_place.x = game->player_place.x - 1;
	game->map[game->player_place.x][game->player_place.y] = 'P';
	ft_print_msg(ft_itoa(++game->moves), 1, 1);
	game->back = '0';
}
