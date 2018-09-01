/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   afficher_constchar.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 13:23:16 by apelissi          #+#    #+#             */
/*   Updated: 2018/08/20 13:23:33 by apelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_const_field(const char *str, t_specif s)
{
	int	i;
	int	t;

	t = 0;
	i = 0;
	while (str[i])
		i++;
	if (s.preci < i && s.preci != -1)
		i = s.preci;
	while (s.field - t > i)
		t += write(1, " ", 1);
}

int	afficher_constchar(const char *str, t_specif s)
{
	int i;

	i = 0;
	if (s.flags % 5)
		ft_const_field(str, s);
	while (str[i] && (s.preci - i || s.preci < 0))
	{
		write(1, &str[i], 1);
		i++;
	}
	if (!(s.flags % 5))
		ft_const_field(str, s);
	if (i > s.field)
		return (i);
	return (s.field);
}
