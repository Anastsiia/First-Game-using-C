/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctifany <ctifany@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 21:45:43 by ctifany           #+#    #+#             */
/*   Updated: 2022/01/14 21:45:45 by ctifany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str1, int c)
{
	char	*res;
	int		i;

	res = NULL;
	i = 0;
	while (str1[i] != '\0')
	{
		if (str1[i] == (char)c)
			res = (char *)&str1[i];
		i++;
	}
	if (c == '\0')
		res = (char *)&str1[i];
	return (res);
}
