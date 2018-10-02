/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   afficher_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 13:24:06 by apelissi          #+#    #+#             */
/*   Updated: 2018/09/17 17:58:15 by apelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	field_ptr(t_specif s)
{
	int t;

	t = 0;
	while (s.field - t > 14)
		t += write(1, " ", 1);
}

int		afficher_ptr(void *p, t_specif s)
{
	unsigned char	t[sizeof(p)];
	int				i;

	if (p == NULL)
		return (write(1, "0x0", 3));
	i = sizeof(p) - 3;
	ft_memcpy(t, &p, sizeof(p));
	if (s.flags % 5)
		field_ptr(s);
	write(1, "0x", 2);
	while (i >= 0)
	{
		if (t[i] < 16)
			write(1, "0", 1);
		afficher_nb((int)t[i], 16, 'a');
		i--;
	}
	if (!(s.flags % 5))
		field_ptr(s);
	if (s.field > 14)
		return (s.field);
	else
		return (14);
}
