/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrito-s <cbrito-s>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:14:52 by cbrito-s          #+#    #+#             */
/*   Updated: 2024/11/25 19:04:18 by cbrito-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printnbr(int n)
{
	unsigned int	nb;
	int				len;

	len = 0;
	if (n < 0)
	{
		len += ft_printchar('-');
		nb = -n;
	}
	else
		nb = n;
	if (nb >= 10)
		len += ft_printnbr(nb / 10);
	nb = nb % 10 + '0';
	len += ft_printchar(nb);
	return (len);
}

int	ft_printunbr(unsigned int n)
{
	unsigned int	nb;
	int				len;

	len = 0;
	nb = n;
	if (nb >= 10)
		len += ft_printnbr(nb / 10);
	nb = nb % 10 + '0';
	len += ft_printchar(nb);
	return (len);
}
