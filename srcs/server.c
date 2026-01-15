/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edi-maio <edi-maio@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 18:28:04 by edi-maio          #+#    #+#             */
/*   Updated: 2026/01/15 20:05:36 by edi-maio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

char	*ft_realloc(char *s1, char c)
{
	char	*s2;
	int		i;

	if (!s1)
	{
		s2 = ft_calloc(sizeof(char), 2);
		s2[0] = c;
	}
	else
	{
		s2 = ft_calloc(sizeof(char), ft_strlen(s1) + 2);
		i = 0;
		while (s1[i])
		{
			s2[i] = s1[i];
			i++;
		}
		s2[i] = c;
		free(s1);
	}
	return (s2);
}

void	signal_handler(int signal)
{
	static char	*str;
	static char	c = 0;
	static int	bit = 0;

	if (signal == SIGUSR1)
		c = (c << 1) | 1;
	else
		c = (c << 1) | 0;
	bit++;
	if (bit == 8)
	{
		if (c == 0)
		{
			ft_printf("%s\n", str);
			free(str);
			str = NULL;
		}
		else
			str = ft_realloc(str, c);
		c = 0;
		bit = 0;
	}
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_printf("%d\n", pid);
	while (1)
	{
		signal(SIGUSR1, signal_handler);
		signal(SIGUSR2, signal_handler);
		pause();
	}
}
