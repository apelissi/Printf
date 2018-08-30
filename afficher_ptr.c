/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   afficher_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 13:24:06 by apelissi          #+#    #+#             */
/*   Updated: 2018/08/20 13:26:14 by apelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	afficher_ptr(void *p, t_specif s)
{
	unsigned char	t[sizeof(p)];
	int				i;

	s.flags = 0;
	i = sizeof(p) - 3;
	ft_memcpy(t, &p, sizeof(p));
	write(1, "0x", 2);
	while (i >= 0)
	{
		if (t[i] < 16)
			write(1, "0", 1);
		afficher_nb((int)t[i], 16, 'a');
		i--;
	}
	return (14);
}
