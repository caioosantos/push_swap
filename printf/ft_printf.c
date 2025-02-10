/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrito-s <cbrito-s>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:50:06 by cbrito-s          #+#    #+#             */
/*   Updated: 2024/11/26 16:06:56 by cbrito-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_type(va_list args, char str)
{
	int	len;

	len = 0;
	if (str == 'c')
		len += ft_printchar(va_arg(args, int));
	if (str == 's')
		len += ft_printstr(va_arg(args, char *));
	if (str == 'p')
		len += ft_printptr(va_arg(args, unsigned long));
	if (str == 'd' || str == 'i')
		len += ft_printnbr(va_arg(args, int));
	if (str == 'u')
		len += ft_printunbr(va_arg(args, int));
	if (str == 'x')
		len += ft_printhex_lower(va_arg(args, unsigned int));
	if (str == 'X')
		len += ft_printhex_upper(va_arg(args, unsigned int));
	if (str == '%')
		len += ft_printchar('%');
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;

	i = 0;
	if (!str)
		return (-1);
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
			i += printf_type(args, *++str);
		else
			i += ft_printchar(*str);
		str++;
	}
	va_end(args);
	return (i);
}
