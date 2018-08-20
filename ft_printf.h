/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 13:03:07 by apelissi          #+#    #+#             */
/*   Updated: 2018/08/20 16:13:42 by apelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef FT_PRINTF_H
#	define FT_PRINTF_H
#	include "unistd.h"

typedef struct	s_specif
{
	int	flags;
	int	field;
	int	preci;
}				t_specif;
int				ft_printf(const char *format, ...);
int				afficher_unsigned(unsigned int nb, char c, t_specif s);
int				afficher_constchar(const char *str, t_specif s);
//int			afficher_constwchar_t(const wchar_t str);
int				afficher_ptr(void *ptr, t_specif s);
//int 			afficher_wint_t(wint_t wt);
int				afficher_int(int nb, char c, t_specif s);
void			afficher_nb(int nb, int base, char casse);
int				taille_nb(int nb, int base);
void			*ft_memcpy(void *dest, const void *src, size_t n);
int				flags(const char *str);
t_specif		check_spe(const char *str);
int				is_identifieur(char c);
int				ft_atoi(const char *nptr);
void			error(void);

#	endif
