/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptrhexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edi-maio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 19:32:19 by edi-maio          #+#    #+#             */
/*   Updated: 2025/10/22 15:05:33 by edi-maio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_putptrhexa(unsigned long s, int prefix, int total)
{
	const char	hex[] = "0123456789abcdef";

	if (!s)
	{
		total = ft_putstr("(nil)");
		return (total);
	}
	if (prefix)
	{
		ft_putstr("0x");
		total += 2;
	}
	if (s >= 16)
		total = ft_putptrhexa(s / 16, 0, total);
	ft_putchar(hex[s % 16]);
	return (total + 1);
}
