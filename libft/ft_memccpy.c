/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plebiez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 12:10:21 by plebiez           #+#    #+#             */
/*   Updated: 2020/11/23 05:33:09 by plebiez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*dest;
	unsigned char	*source;

	dest = (unsigned char *)dst;
	source = (unsigned char *)src;
	i = 0;
	while (i < n && source[i] != (unsigned char)c)
	{
		dest[i] = source[i];
		i++;
	}
	if (i == n)
		return (NULL);
	else
	{
		dest[i] = source[i];
		i++;
		return (&dest[i]);
	}
}
