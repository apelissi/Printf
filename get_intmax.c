/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_intmax.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 21:47:06 by apelissi          #+#    #+#             */
/*   Updated: 2018/09/20 21:50:21 by apelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

intmax_t	get_intmax(va_list ap, t_specif s)
{
	uintmax_t	nb;

	if (!(s.len_mod % 4))
		nb = (signed char)(va_arg(ap, int));
	else if (!(s.len_mod % 2))
		nb = (short)(va_arg(ap, int));
	else if (!(s.len_mod % 9))
		nb = (long long)(va_arg(ap, long long int));
	else if (!(s.len_mod % 3))
		nb = (long)(va_arg(ap, long int));
	else if (!(s.len_mod % 5))
		nb = (intmax_t)(va_arg(ap, intmax_t));
	else if (!(s.len_mod % 7))
		nb = (size_t)(va_arg(ap, size_t));
	else
		nb = (int)(va_arg(ap, int));
	nb = (intmax_t)nb;
	return (nb);
}
