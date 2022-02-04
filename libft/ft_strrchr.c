/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plebiez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 12:26:55 by plebiez           #+#    #+#             */
/*   Updated: 2020/11/23 06:17:08 by plebiez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*save;

	save = (char *)s + ft_strlen(s);
	while (*save != c)
	{
		if (save == s)
		{
			return (NULL);
		}
		save--;
	}
	return (save);
}
