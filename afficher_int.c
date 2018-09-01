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

int		ft_signe(int nb, t_specif s)
{
	if (nb < 0)
		return (write (1, "-", 1));
	else if (!(s.flags % 7))
		return (write (1, "+", 1));
	else if (!(s.flags % 11))
		return (write (1, " ", 1));
	return (0);
}

int		number(int nb, t_specif s)
{
	int	u;

	u = 0;
	if (nb == -2147483648)
	{
		while (s.preci - u > 10)
			u += write(1, "0", 1);
		write(1, "2147483648", 10);
		return (10 + u);
	}
	if (nb < 0)
		nb = -nb;
	while (s.preci - u > taille_nb(nb, 10))
		u += write(1, "0", 1);
	afficher_nb(nb, 10, 'a');
	return (taille_nb(nb, 10) + u);
}

void	ft_field(int nb, t_specif s)
{
	char	c;
	int	t;
	int	u;

	t = 0;
	c = ' ';
	if (s.flags % 3 == 0 && s.flags % 5 && s.preci == -1)
		c = '0';
	if (((s.flags % 7 == 0 || s.flags % 11 == 0) && nb >= 0) || nb < 0)
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

int		ft_putchar(int i, t_specif s)
{
	unsigned char	c;

	c = (unsigned char)i;
	if (s.flags % 5)
		ft_field(1, s);
	write(1, &c, 1);
	if (!(s.flags % 5))
		ft_field(1, s);
	if (s.field > 0)
		return (s.field);
	return (1);
}

int		afficher_int(int nb, char c, t_specif s)
{
	int	i;

	if (s.flags < 0)
		error();
	if (c == 'c')
		return (ft_putchar(nb, s));
	else
	{
		if ((s.flags % 3 || s.preci > 0) && s.flags % 5)
			ft_field(nb, s);
		i = ft_signe(nb, s);
		if (s.flags % 5 && !(s.flags % 3) && (s.preci == -1))
			ft_field(nb, s);
		number(nb, s);
		if (!(s.flags % 5))
			ft_field(nb, s);
		if (s.field > taille_nb(nb, 10) && s.field > s.preci)
			return(s.field);
		else if (taille_nb(nb, 10)  > s.preci)
			return (taille_nb(nb, 10) + i);
		else
			return (s.preci + i);
	}
}
