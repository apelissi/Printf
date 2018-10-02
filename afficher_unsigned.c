/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   afficher_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 13:21:11 by apelissi          #+#    #+#             */
/*   Updated: 2018/09/20 22:27:25 by apelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		sharp(t_specif s, char c, uintmax_t nb)
{
	if (s.flags % 2 || nb == 0)
		return (0);
	else if (c == 'o' || c == 'O')
		return (taille_nb(nb, 8) + 1);
	else if (c == 'x')
		return (write(1, "0x", 2));
	else if (c == 'X')
		return (write(1, "0X", 2));
	else
		return (0);
}

int		find_base(char c)
{
	if (c == 'o' || c == 'O')
		return (8);
	else if (c == 'x' || c == 'X')
		return (16);
	else if (c == 'u' || c == 'U')
		return (10);
	else
		return (0);
}

void	ft_un_field(uintmax_t nb, t_specif s, int base)
{
	char	c;
	int		t;
	int		u;
	int		sh;

	sh = 0;
	if (base > 10 && s.flags % 2 == 0)
		sh = 2;
	t = 0;
	c = ' ';
	if (s.flags % 3 == 0 && s.flags % 5 && s.preci == -1)
		c = '0';
	u = taille_unsigned(nb, base);
	if (u < s.preci)
		u = s.preci;
	while (s.field > u + t + sh)
	{
		t++;
		write(1, &c, 1);
	}
}

void	unsigned_number(uintmax_t nb, t_specif s, int base, char casse)
{
	int	u;

	u = 0;
	while (s.preci - u > taille_unsigned(nb, base))
		u += write(1, "0", 1);
	if (nb || s.preci || (base == 8 && !(s.flags % 2)))
		afficher_nb(nb, base, casse);
	else if (s.field >= 0)
		write(1, " ", 1);
}

int		afficher_unsigned(uintmax_t nb, char c, t_specif s)
{
	int base;
	int sh;

	sh = 0;
	base = find_base(c);
	if (!(s.flags % 2) && (c == 'o' || c == 'O'))
		s.preci = sharp(s, c, nb);
	else if (!(s.flags % 2) && !(s.flags % 3))
		sh = sharp(s, c, nb);
	if (s.flags % 5)
		ft_un_field(nb, s, base);
	if (!(s.flags % 2) && s.flags % 3 && base == 16)
		sh = sharp(s, c, nb);
	unsigned_number(nb, s, base, c);
	if (!(s.flags % 5))
		ft_un_field(nb, s, base);
	if (s.field > taille_unsigned(nb, base) + sh && s.field > s.preci)
		return (s.field);
	else if (taille_nb(nb, 10) + sh > s.preci &&
			(nb || s.preci || (base == 8 && !(s.flags % 2))))
		return (taille_unsigned(nb, base) + sh);
	else
		return (s.preci);
}
