/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_spe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 13:03:01 by apelissi          #+#    #+#             */
/*   Updated: 2018/09/20 21:59:58 by apelissi         ###   ########.fr       */
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

int			is_len_mod(char c)
{
	if (c == 'h')
		return (2);
	else if (c == 'l')
		return (3);
	else if (c == 'j')
		return (5);
	else if (c == 'z')
		return (7);
	return (0);
}

int			get_len_mod(const char *str, t_specif *s)
{
	int	d;
	int	t_lm;
	int	i;

	i = 0;
	d = 2;
	if (str[i] && (t_lm = is_len_mod(str[i])) > 1)
	{
		s->len_mod = s->len_mod * t_lm;
		i++;
	}
	if (str[i] && (t_lm = is_len_mod(str[i])) > 1)
	{
		if (s->len_mod != t_lm)
			return (-1);
		s->len_mod = s->len_mod * t_lm;
		return (2);
	}
	if (s->len_mod > 1)
		return (1);
	return (0);
}

t_specif	init(void)
{
	t_specif	s;

	s.flags = 1;
	s.field = -1;
	s.preci = -1;
	s.len_mod = 1;
	return (s);
}

t_specif	check_spe(const char *str, int i)
{
	t_specif	s;

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
	if (str[i] && str[i] == '.')
	{
		s.preci = ft_atoi(&str[i + 1]);
		while (str[i + 1] >= '0' && str[i + 1] <= '9')
			i++;
		i++;
	}
	i += get_len_mod(&str[i], &s);
	if (!is_identifieur(str[i]))
		s.flags = -1;
	return (s);
}
