/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 13:03:25 by apelissi          #+#    #+#             */
/*   Updated: 2018/09/20 21:53:05 by apelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		taille(const char *str)
{
	int i;

	i = 0;
	while (str[i] && !(is_identifieur(str[i])))
		i++;
	return (i + 1);
}

char	identification(const char *str)
{
	while (*str && !(is_identifieur(*str)))
		str++;
	return ((char)*str);
}

int		select_type(va_list ap, char c, const char *str)
{
	t_specif	s;

	s = check_spe(str, 0);
	if (c == 'o' || c == 'O' || c == 'u' || c == 'U' || c == 'x' || c == 'X')
		return (afficher_unsigned(get_uintmax(ap, s), c, s));
	else if (c == 'd' || c == 'D' || c == 'c' || c == 'i')
		return (afficher_int(get_intmax(ap, s), c, s));
	else if (c == 's')
		return (afficher_constchar(va_arg(ap, const char *), s));
	else if (c == 'p')
		return (afficher_ptr(va_arg(ap, void *), s));
	else if (c == 'S')
		return (afficher_ws(va_arg(ap, wchar_t *), s));
	else if (c == 'C')
		return (0);
	else if (c == '%')
		return (afficher_percent(s));
	else if (c == 'Z')
		return (write(1, "Z", 1));
	else
		return (-1);
}

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		tot;
	char	c;

	if (format == NULL)
		return (-1);
	va_start(ap, format);
	i = -1;
	tot = 0;
	while (format[++i])
	{
		if (format[i] != '%')
			tot += write(1, &format[i], 1);
		else if ((c = identification(&format[i + 1])))
		{
			tot += select_type(ap, c, &format[i + 1]);
			i += taille(&format[i + 1]);
		}
	}
	va_end(ap);
	return (tot);
}
