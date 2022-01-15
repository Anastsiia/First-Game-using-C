#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <fcntl.h>
# include "libft/libft.h"

# define ENEMY "./img/Enemy.xpm"
# define PLAYER "./img/Player.xpm"
# define WALL "./img/Wall.xpm"
# define APPLE "./img/Apple.xpm"
# define APPLE_2 "./img/Apple_2.xpm"
# define EXIT "./img/Exit.xpm"
# define GRASS "./img/Grass.xpm"
# define PLAYER_EXIT "./img/Player+exit.xpm"
# define ENEMY_2 "./img/Enemy_2.xpm"
# define BUFFER_SIZE 1
# define BONUS 0

typedef struct s_xy
{
	int		x;
	int		y;
}				t_xy;

typedef struct s_img
{
	void		*img;
	struct s_xy	size;
	char		*path;
}				t_img;

typedef struct s_valid
{
	int	player;
	int	exit;
}				t_valid;

typedef struct s_game
{
	void			*mlx;
	void			*win;
	char			**map;
	char			back;
	int				map_line;
	int				map_width;
	int				apples;
	int				moves;
	int				animation;
	struct s_valid	valid;
	struct s_xy		player_place;
	struct s_img	wall;
	struct s_img	grass;
	struct s_img	player;
	struct s_img	exit;
	struct s_img	collectable;
	struct s_img	enemy;
	struct s_img	player_exit;
}					t_game;

int		ft_check_args(int argc, char **argv);
int		ft_check_format(char *file);
int		ft_read_map(char *argv, t_game *game);
int		ft_memory_allocate(char *argv, t_game *game);
int		ft_count_lines(char *argv);
int		ft_get_next_line(int fd, char *res);
int		ft_check_valid(t_game *game);
int		ft_check_rectangular(t_game *game);
int		ft_check_characters(t_game *game);
int		ft_valid_char(char c);
void	ft_count_characters(t_game *game);
int		ft_check_walls(t_game *game);
int		ft_cmpch(char c, char *str);
void	ft_init_win(t_game *game);
void	ft_init_img(t_game *game);
void	ft_fill_map(t_game *game);
void	ft_find_n(char **point, char **balance, char **res);
void	ft_print_img(t_game *game, int x, int y, void *img);
void	ft_print_str(t_game *game, int x, int y);
int		ft_end(t_game *game, int end);
int		ft_end_msg(t_game *game, char *str);
int		ft_key(int key, t_game *game);
int		ft_press_w(t_game *game);
int		ft_press_s(t_game *game);
int		ft_press_a(t_game *game);
int		ft_press_d(t_game *game);
void	ft_move_down(t_game *game);
void	ft_move_left(t_game *game);
void	ft_move_right(t_game *game);
void	ft_move_up(t_game *game);
void	ft_move_down_r(t_game *game);
void	ft_move_left_r(t_game *game);
void	ft_move_right_r(t_game *game);
void	ft_move_up_r(t_game *game);
char	*ft_strdup_new(const char *str, int flag);
int		ft_read_file(char **point, char **balance, char **res, int fd);
char	*ft_strchr_new(const char *str);
int		ft_print_msg(char *msg, int flag, int f);
int		ft_update(t_game *game);
int		ft_valid_char(char c);
#endif
