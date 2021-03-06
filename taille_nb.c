/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   taille_nb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 13:11:01 by apelissi          #+#    #+#             */
/*   Updated: 2018/09/20 22:02:14 by apelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	taille_nb(intmax_t nb, int base)
{
	int			taille;
	intmax_t	div;

	taille = 1;
	if (nb < 0)
		nb = -nb;
	div = 1;
	while (nb / div >= base)
	{
		taille++;
		div = div * base;
	}
	return (taille);
}
