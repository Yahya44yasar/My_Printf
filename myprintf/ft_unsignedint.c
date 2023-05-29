/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsignedint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyasar <yyasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 23:06:11 by yyasar            #+#    #+#             */
/*   Updated: 2022/12/16 09:07:21 by yyasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ubas(unsigned int n)
{
	int	i;

	i = 0;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_uitoa(unsigned int n)
{
	char	*s;
	int		i;

	i = ft_ubas(n);
	s = (char *)malloc(sizeof(char) * (i + 1));
	if (!s)
		return (0);
	s[i] = '\0';
	while (n != 0)
	{
		s[--i] = (n % 10) + 48;
		n = n / 10;
	}
	return (s);
}

int	ft_unsignedint(unsigned int n)
{
	int		i;
	char	*s;

	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	s = ft_uitoa(n);
	i = ft_putstr(s);
	free(s);
	return (i);
}
