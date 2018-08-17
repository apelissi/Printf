#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include "unistd.h"

struct specif
{
	int	Flags;
	int	Field;
	int	Preci;
};
int		ft_printf(const char *format,...);
int		afficher_unsigned(unsigned int nb, char c, struct specif S);
int		afficher_constchar(const char *str, struct specif S);
//int		afficher_constwchar_t(const wchar_t str);
int		afficher_ptr(void *ptr, struct specif S);
//int 		afficher_wint_t(wint_t wt);
int		afficher_int(int nb, char c, struct specif S);
void		afficher_nb(int nb, int base, char casse);
int		taille_nb(int nb, int base);
void		*ft_memcpy(void *dest, const void *src, size_t n);
int		flags(const char *str);
struct specif	check_spe(const char *str);

#endif
