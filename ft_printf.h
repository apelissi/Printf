/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 13:03:07 by apelissi          #+#    #+#             */
/*   Updated: 2018/09/27 21:12:54 by apelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef FT_PRINTF_H
#	define FT_PRINTF_H
#	include "unistd.h"
#	include "string.h"
#	include "stdarg.h"
#	include "wchar.h"
#	include "stddef.h"
#	include "inttypes.h"

typedef struct	s_specif
{
	int	flags;
	int	field;
	int	preci;
	int	len_mod;
}				t_specif;
int				ft_printf(const char *format, ...);
int				afficher_unsigned(uintmax_t nb, char c, t_specif s);
int				afficher_constchar(const char *str, t_specif s);
int				afficher_ptr(void *ptr, t_specif s);
int				afficher_int(intmax_t nb, char c, t_specif s);
void			afficher_nb(intmax_t nb, int base, char casse);
int				taille_nb(intmax_t nb, int base);
void			*ft_memcpy(void *dest, const void *src, size_t n);
int				flags(const char *str);
t_specif		check_spe(const char *str, int i);
int				is_identifieur(char c);
int				ft_atoi(const char *nptr);
void			error(void);
int				afficher_percent(t_specif s);
int				taille_unsigned(uintmax_t nb, int base);
size_t			ft_strlen(const char *str);
int				afficher_ws(wchar_t *obj, t_specif s);
uintmax_t		get_uintmax(va_list ap, t_specif s);
intmax_t		get_intmax(va_list ap, t_specif s);

#	endif
