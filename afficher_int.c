/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   afficher_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 13:22:00 by apelissi          #+#    #+#             */
/*   Updated: 2018/08/23 16:43:35 by apelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putchar(int i)
{
	unsigned char	c;

	c = (unsigned char)i;
	write(1, &c, 1);
	return (1);
}

void	fill(t_specif s, int t)
{
	char	c;

	c = ' ';
	if (s.flags % 3 == 0)
		c = '0';
	while (s.field > t + 2)
	{
		write(1, &c, 1);
		s.field--;
	}
}

int		number(int nb, t_specif s)
{
	int		t;
	char	c;
	int		u;

	t = 0;
	u = 0;
	c = '\0';
	if (s.flags % 11 == 0 && nb >= 0)
	{
		c = ' ';
		t++;
	}
	if (s.flags % 7 == 0 && nb >= 0)
	{
		c = '+';
		t++;
	}
	write(1, &c, 1);
	while (s.preci - u > taille_nb(nb, 10))
		u += write(1, "0", 1);
	afficher_nb(nb, 10, 'a');
	return (taille_nb(nb, 10) + u + t);
}

void	ft_field(int nb, t_specif s)
{
	char	c;
	int		t;
	int		u;

	t = 0;
	c = ' ';
	if (s.flags % 3 == 0 && s.flags % 7 && s.flags % 5)
		c = '0';
	if (s.flags % 7 == 0 || s.flags % 11 == 0)
		t++;
	u = taille_nb(nb, 10);
	if (u < s.preci)
		u = s.preci;
	while (s.field > u + t)
	{
		t++;
		write(1, &c, 1);
	}
}

int		afficher_int(int nb, char c, t_specif s)
{
	unsigned char	r;
	int				i;

	i = 0;
	if (s.flags < 0)
		error();
	if (c == 'c')
		return (ft_putchar(nb));
	else
	{
		if (s.flags % 5 == 0)
		{
			i = number(nb, s);
			ft_field(nb, s);
		}
		else
		{
			ft_field(nb, s);
			i = number(nb, s);
		}
		if (i > s.field)
			return (i);
		return (s.field);
	}
}
