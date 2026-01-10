/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edi-maio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 17:40:12 by edi-maio          #+#    #+#             */
/*   Updated: 2025/10/21 21:00:47 by edi-maio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_putunbr(unsigned int n, int total)
{
	char	val;

	if (n >= 10)
		total = ft_putunbr(n / 10, total);
	val = n % 10 + '0';
	ft_putchar(val);
	return (total + 1);
}
