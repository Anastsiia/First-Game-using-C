/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctifany <ctifany@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 21:45:17 by ctifany           #+#    #+#             */
/*   Updated: 2022/01/14 21:45:18 by ctifany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	res;
	size_t	i;
	int		a;

	i = ft_strlen(dst);
	res = i;
	a = 0;
	if (i >= dstsize)
		return (ft_strlen(src) + dstsize);
	while (src[a] != '\0' && i < (dstsize - 1))
	{
		dst[i] = src[a];
		i++;
		a++;
	}
	dst[i] = '\0';
	res = res + ft_strlen(src);
	return (res);
}
