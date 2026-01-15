/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edi-maio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 19:38:42 by edi-maio          #+#    #+#             */
/*   Updated: 2025/10/22 17:42:24 by edi-maio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printnbr_base(long nbr, const char *base, int b_size, int total)
{
	int	tmp;

	if (nbr >= b_size)
		total = ft_printnbr_base(nbr / b_size, base, b_size, total);
	tmp = ft_putchar(base[nbr % b_size]);
	return (total + tmp);
}

static int	ft_is_base_valid(const char *base)
{
	int	i;
	int	j;
	int	is_valid;

	i = 0;
	is_valid = 1;
	while (base[i] && is_valid)
	{
		if (base[i] == '+' || base[i] == '-')
			is_valid = 0;
		else
		{
			j = 0;
			while (base[j] && is_valid)
			{
				if (i != j && base[i] == base[j])
					is_valid = 0;
				j++;
			}
		}
		i++;
	}
	if (i < 1)
		is_valid = 0;
	return (is_valid);
}

int	ft_putnbr_base(long nbr, const char *base)
{
	int		i;
	int		total;

	if (ft_is_base_valid(base))
	{
		i = 0;
		total = 0;
		while (base[i])
			i++;
		if (nbr < 0)
		{
			write(1, "-", 1);
			total = 1;
			nbr = -nbr;
		}
		total = ft_printnbr_base(nbr, base, i, total);
		return (total);
	}
	return (0);
}
