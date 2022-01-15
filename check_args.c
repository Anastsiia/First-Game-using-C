/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctifany <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 22:58:07 by ctifany           #+#    #+#             */
/*   Updated: 2022/01/13 22:58:09 by ctifany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_format(char *file)
{
	int		len;
	char	*format;

	format = ".ber";
	len = ft_strlen(file);
	if (len <= 4)
		return (1);
	file = file + len - 4;
	if (ft_strncmp(file, format, 4) != 0)
		return (1);
	return (0);
}

int	ft_check_args(int argc, char **argv)
{
	if (argc < 2)
	{
		ft_print_msg("no map\n", 0, 0);
		return (1);
	}
	if (argc > 2)
		ft_print_msg("you'll play only first map\n", 0, 0);
	if (ft_check_format(argv[1]) == 1)
	{
		ft_print_msg("map should be .ber\n", 0, 0);
		return (1);
	}
	return (0);
}
