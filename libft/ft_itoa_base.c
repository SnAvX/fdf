/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plebiez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 17:11:46 by plebiez           #+#    #+#             */
/*   Updated: 2022/01/18 17:16:43 by plebiez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base(unsigned int n, char *base)
{
	char	*str;

	str = (char *)ft_calloc(sizeof(char), 2);
	if (str == NULL)
		return (NULL);
	else if (n >= (unsigned int)ft_strlen(base))
	{
		free(str);
		str = ft_strjoin_f12(ft_itoa_base(n / ft_strlen(base), base),
				ft_itoa_base(n % ft_strlen(base), base));
	}
	else if (n < (unsigned int)ft_strlen(base))
	{
		str[0] = base[n];
		str[1] = '\0';
	}
	return (str);
}
