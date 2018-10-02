/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   afficher_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 17:17:13 by apelissi          #+#    #+#             */
/*   Updated: 2018/09/17 17:50:17 by apelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_percent_field(t_specif s)
{
	char	c;

	c = ' ';
	if (!(s.flags % 3) && s.flags % 5)
		c = '0';
	while (s.field > 1)
		s.field -= write(1, " ", 1);
}

int		afficher_percent(t_specif s)
{
	if (s.flags % 5)
		ft_percent_field(s);
	write(1, "%", 1);
	if (!(s.flags % 5))
		ft_percent_field(s);
	if (s.field > 0)
		return (s.field);
	return (1);
}
