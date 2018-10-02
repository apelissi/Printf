/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   taille_unsigned.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 13:43:40 by apelissi          #+#    #+#             */
/*   Updated: 2018/09/20 22:29:29 by apelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	taille_unsigned(uintmax_t nb, int base)
{
	int			taille;
	intmax_t	div;

	taille = 1;
	//if (nb < 1 && nb != 0)
	//	nb = 4294967296 + nb;
	div = 1;
	while (nb / div >= (uintmax_t)base)
	{
		taille++;
		div = div * base;
	}
	return (taille);
}
