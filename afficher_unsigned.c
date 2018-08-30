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

int	afficher_unsigned(unsigned int nb, char c, t_specif s)
{
	int base;

	s.flags = 0;
	base = 2;
	if (c == 'x' || c == 'X')
		base = 16;
	else if (c == 'O' || c == 'o')
		base = 8;
	else if (c == 'u' || c == 'U')
		base = 10;
	afficher_nb((int)nb, base, c);
	return (taille_nb((int)nb, base));
}
