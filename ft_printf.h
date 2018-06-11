#include "unistd.h"

int	ft_printf(const char *format,...);
int	afficher_unsigned(unsigned int nb, char c);
int	afficher_constchar(const char *str);
//int	afficher_constwchar_t(const wchar_t str);
int	afficher_ptr(void *ptr);
//int 	afficher_wint_t(wint_t wt);
int	afficher_int(int nb, char c);
void	afficher_nb(int nb, int base, char casse);
int	taille_nb(int nb, int base);
void	*ft_memcpy(void *dest, const void *src, size_t n);

