/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plebiez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 12:12:11 by plebiez           #+#    #+#             */
/*   Updated: 2020/11/23 05:39:24 by plebiez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char	*save;

	if (s == NULL)
		return (NULL);
	save = s;
	while (n)
	{
		*save = c;
		save++;
		n--;
	}
	return (s);
}
