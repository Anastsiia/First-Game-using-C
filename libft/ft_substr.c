/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctifany <ctifany@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 21:45:51 by ctifany           #+#    #+#             */
/*   Updated: 2022/01/14 21:45:53 by ctifany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*res;
	size_t			i;
	unsigned int	a;

	i = 0;
	a = ft_strlen(s);
	if (start > a)
		res = (char *)malloc(sizeof(char));
	else
	{
		if (len <= a)
			res = (char *)malloc(sizeof(char) * (len + 1));
		else
			res = (char *)malloc(sizeof(char) * (a - start + 1));
	}
	if (!s || res == NULL)
		return (NULL);
	while (i < len && start <= a)
	{
		res[i] = s[start];
		i++;
		start++;
	}
	res[i] = '\0';
	return (res);
}
