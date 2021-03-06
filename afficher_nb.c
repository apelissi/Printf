/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   afficher_nb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 13:12:38 by apelissi          #+#    #+#             */
/*   Updated: 2018/09/20 18:53:28 by apelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		check_zero(long nb)
{
	if (nb == 0)
	{
		write(1, "0", 1);
		return (0);
	}
	return (1);
}

void	afficher_nb(intmax_t nb, int base, char casse)
{
	intmax_t	div;
	char		c;

	if (check_zero(nb))
	{
		div = 1;
		while (nb / div >= base)
			div = div * base;
		while (div != 0)
		{
			if (nb / div < 10)
				c = '0' + nb / div;
			else
			{
				if (casse >= 'a' && casse <= 'z')
					c = 'a' + nb / div - 10;
				else
					c = 'A' + nb / div - 10;
			}
			write(1, &c, 1);
			nb = nb % div;
			div = div / base;
		}
	}
}
