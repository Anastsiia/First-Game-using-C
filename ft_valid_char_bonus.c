/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_char_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctifany <ctifany@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 22:58:42 by ctifany           #+#    #+#             */
/*   Updated: 2022/01/14 22:33:00 by ctifany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_cmpch(char c, char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (c == str[i])
			return (0);
		i++;
	}
	return (1);
}

int	ft_valid_char(char c)
{
	char	*str;
	int		i;

	i = 0;
	str = "10PECB";
	while (str[i] != '\0')
	{
		if (c == str[i])
			return (0);
		i++;
	}
	return (1);
}
