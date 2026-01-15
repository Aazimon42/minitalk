/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edi-maio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 17:33:59 by edi-maio          #+#    #+#             */
/*   Updated: 2026/01/15 18:57:03 by edi-maio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	int	i;
	int	len;

	if (!s)
	{
		len = ft_putstr("(null)");
		return (len);
	}
	len = ft_slen(s);
	i = write(1, s, len);
	if (i == -1)
		return (0);
	else
		return (len);
}
