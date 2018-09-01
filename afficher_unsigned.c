/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   afficher_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 13:21:11 by apelissi          #+#    #+#             */
/*   Updated: 2018/08/20 13:21:27 by apelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	sharp(t_specif s, char c, int nb)
{
	if (s.flags % 2)
		return (0);
	else if (c == 'o' || c == 'O')
		return(taille_nb(nb, 8) + 1);
	else if (c == 'x')
		return (write(1, "ox", 2));
	else if (c == 'X')
		return (write(1, "OX", 2));
	else
		return (0);
}

int 	find_base(char c)
{
	if (c == 'o' || c == 'O')
		return (8);
	else if (c == 'x' || c == 'X')
		return (16);
	else if (c == 'u')
		return (10);
	else
		return (0);
}

void	ft_un_field(int nb, t_specif s, int base)
{
	char	c;
	int	t;
	int	u;

	t = 0;
	c = ' ';
	if (s.flags % 3 == 0 && s.flags % 5 && s.preci == -1)
		c = '0';
	u = taille_nb(nb, base);
	if (u < s.preci)
		u = s.preci;
	while (s.field > u + t)
	{
		t++;
		write(1, &c, 1);
	}
}

void	unsigned_number(int nb, t_specif s, int base, char casse)
{
	int	u;

	u = 0;
	while (s.preci - u > taille_nb(nb, base))
		u += write(1, "0", 1);
	afficher_nb(nb, base, casse);
}

int	afficher_unsigned(unsigned int nb, char c, t_specif s)
{
	int base;
	int sh;

	sh = 0;
	base = find_base(c);
	if (s.flags % 5)
		ft_un_field(nb, s, base);
	if (!(s.flags % 2) && (c == 'o' || c == 'O'))
		s.preci = sharp(s, c, nb);
	else
		sh = sharp(s, c, nb);
	unsigned_number(nb, s, base, c);
	if (!(s.flags % 5))
		ft_un_field(nb, s, base);
	if (s.field > taille_nb(nb, base) + sh && s.field > s.preci)
		return(s.field);
	else if (taille_nb(nb, 10)  + sh > s.preci)
		return (taille_nb(nb, base) + sh);
	else
		return (s.preci);
}
