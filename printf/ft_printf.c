/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edi-maio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 17:10:47 by edi-maio          #+#    #+#             */
/*   Updated: 2025/10/23 13:33:16 by edi-maio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_printbytype(va_list args, const char *str)
{
	int	result;

	if (!ft_strncmp(str, "%c", 2))
		result = ft_putchar(va_arg(args, int));
	else if (!ft_strncmp(str, "%s", 2))
		result = ft_putstr(va_arg(args, char *));
	else if (!ft_strncmp(str, "%p", 2))
		result = ft_putptrhexa(va_arg(args, unsigned long), 1, 0);
	else if (!ft_strncmp(str, "%d", 2))
		result = ft_putnbr_base(va_arg(args, int), "0123456789");
	else if (!ft_strncmp(str, "%i", 2))
		result = ft_putnbr_base(va_arg(args, int), "0123456789");
	else if (!ft_strncmp(str, "%u", 2))
		result = ft_putunbr(va_arg(args, unsigned int), 0);
	else if (!ft_strncmp(str, "%x", 2))
		result = ft_putnbr_base(va_arg(args, unsigned int), "0123456789abcdef");
	else if (!ft_strncmp(str, "%X", 2))
		result = ft_putnbr_base(va_arg(args, unsigned int), "0123456789ABCDEF");
	else if (!ft_strncmp(str, "%%", 2))
		result = ft_putchar('%');
	else
		result = 0;
	return (result);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		total;

	if (!str)
		return (-1);
	va_start(args, str);
	i = 0;
	total = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			total += ft_printbytype(args, &str[i]);
			i++;
		}
		else
			total += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (total);
}
