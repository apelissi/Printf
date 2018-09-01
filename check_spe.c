/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_spe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 13:03:01 by apelissi          #+#    #+#             */
/*   Updated: 2018/08/20 14:56:39 by apelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			is_flag(char c)
{
	if (c == '#')
		return (2);
	else if (c == '0')
		return (3);
	else if (c == '-')
		return (5);
	else if (c == '+')
		return (7);
	else if (c == ' ')
		return (11);
	return (0);
}

t_specif	init(void)
{
	t_specif	s;

	s.flags = 1;
	s.field = -1;
	s.preci = -1;
	return (s);
}

t_specif	check_spe(const char *str)
{
	int			i;
	t_specif	s;

	i = 0;
	s = init();
	while (str[i] && is_flag(str[i]))
	{
		s.flags = s.flags * is_flag(str[i]);
		i++;
	}
	if (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		s.field = ft_atoi(&str[i]);
		i += taille_nb(s.field, 10);
	}
	if (str[i] && str[i] == '.' && str[i + 1] >= '0' && str[i + 1] <= '9')
	{
		s.preci = ft_atoi(&str[i + 1]);
		i += taille_nb(s.preci, 10) + 1;
	}
	if (!is_identifieur(str[i]))
		s.flags = -1;
	return (s);
}
