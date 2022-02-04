/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plebiez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 17:09:39 by plebiez           #+#    #+#             */
/*   Updated: 2022/01/18 17:09:40 by plebiez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_unsigned(unsigned int n)
{
	long	nb;
	int		i;

	i = 0;
	nb = n;
	if (nb > 9)
		ft_putnbr_unsigned(nb / 10);
	i += ft_putchar_fd_return((nb % 10) + '0', 1);
	return (i);
}
