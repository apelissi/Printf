/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   afficher_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 13:22:00 by apelissi          #+#    #+#             */
/*   Updated: 2018/08/20 16:11:38 by apelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	afficher_int(int nb, char c, t_specif s)
{
	unsigned char r;

	if (s.flags < 0)
		error();
	if (c == 'c')
	{
		r = (unsigned char)nb;
		write(1, &r, 1);
		return (1);
	}
	else
	{
		afficher_nb(nb, 10, 'a');
		return (taille_nb(nb, 10));
	}
}
