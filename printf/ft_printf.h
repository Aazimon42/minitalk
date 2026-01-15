/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edi-maio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 17:08:03 by edi-maio          #+#    #+#             */
/*   Updated: 2026/01/15 18:25:02 by edi-maio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *str, ...) __attribute__((format(printf, 1, 2)));
int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_putnbr_base(long n, const char *base);
int	ft_putunbr(unsigned int n, int total);
int	ft_putptrhexa(unsigned long s, int prefix, int total);
int	ft_slen(char const *str);
int	ft_strncmp(const char *s1, const char *s2, size_t n);

#endif
