NAME		= so_long

SRC			= main.c	check_args.c	read_map.c	get_next_line.c		map_validation.c	events.c	init_error.c		moves.c		moves_r.c	ft_valid_char.c		fill_map.c

OBJ			= $(SRC:.c=.o) 

HEADER		= so_long.h
LIBFT 		= ./libft/libft.a

LIBFT_MAKE	= make -C ./libft

CC			= cc
RM			= rm -f
CFLAGS		= -Wall -Wextra -Werror
MINILIBX 	= -I /usr/X11/include -g -L /usr/X11/lib -l mlx -framework OpenGL -framework AppKit

all:		libft so_long

libft:		
			@$(LIBFT_MAKE)

so_long:	$(OBJ) $(HEADER) $(LIBFT)
			$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MINILIBX) -o $(NAME)

bonus:
			@make -f Makebonus all

clean:		
			@$(RM) $(OBJ)
			@make -f Makebonus clean
			@$(LIBFT_MAKE) clean

fclean:		clean
			@$(RM) $(NAME)
			@make -f Makebonus fclean
			@$(LIBFT_MAKE) fclean

re:			fclean all
			
.PHONY:		all clean fclean re bonus libft