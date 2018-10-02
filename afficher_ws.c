/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   afficher_ws.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 12:18:54 by apelissi          #+#    #+#             */
/*   Updated: 2018/09/18 13:24:00 by apelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		oct_4(wint_t c)
{
	unsigned char put[4];

	put[0] = (c >> 18) + 240;
	put[1] = ((c >> 12) & 63) + 128;
	put[2] = ((c >> 6) & 63) + 128;
	put[3] = ((c & 63) + 128);
	return (write(1, put, 4));
}

int		oct_3(wint_t c)
{
	unsigned char put[3];

	put[0] = (c >> 12) + 224;
	put[1] = ((c >> 6) & 63) + 128;
	put[2] = ((c & 63) + 128);
	return (write(1, put, 3));
}

int		oct_2(wint_t c)
{
	unsigned char put[2];

	put[0] = (c >> 6) + 192;
	put[1] = ((c & 63) + 128);
	return (write(1, put, 2));
}

int		afficher_wchar(wint_t c)
{
	if (c <= 127)
		return (write(1, &c, 1));
	else if (c >= 128 && c <= 2047)
		return (oct_2(c));
	else if (c >= 2048 && c <= 65535)
		return (oct_3(c));
	else if (c >= 65536 && c <= 2097151)
		return (oct_4(c));
	return (0);
}

int		afficher_ws(wchar_t *obj, t_specif s)
{
	int tot;
	int i;

	if (obj == NULL)
		return (write(1, "(null)", 6));
	s.preci = 0;
	i = 0;
	tot = 0;
	while (obj[i])
	{
		tot += afficher_wchar(obj[i]);
		i++;
	}
	return (tot);
}
