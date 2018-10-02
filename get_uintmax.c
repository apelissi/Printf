/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_uintmax.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 16:39:24 by apelissi          #+#    #+#             */
/*   Updated: 2018/09/20 21:51:00 by apelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

uintmax_t	get_uintmax(va_list ap, t_specif s)
{
	uintmax_t	nb;

	if (!(s.len_mod % 4))
		nb = (unsigned char)(va_arg(ap, unsigned int));
	else if (!(s.len_mod % 2))
		nb = (unsigned short)(va_arg(ap, unsigned int));
	else if (!(s.len_mod % 9))
		nb = (unsigned long long)(va_arg(ap, unsigned long long int));
	else if (!(s.len_mod % 3))
		nb = (unsigned long)(va_arg(ap, unsigned long int));
	else if (!(s.len_mod % 5))
		nb = (uintmax_t)(va_arg(ap, uintmax_t));
	else if (!(s.len_mod % 7))
		nb = (size_t)(va_arg(ap, size_t));
	else
		nb = (unsigned int)(va_arg(ap, unsigned int));
	nb = (uintmax_t)nb;
	return (nb);
}
