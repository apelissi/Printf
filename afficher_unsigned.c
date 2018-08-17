#include "ft_printf.h"

int	afficher_unsigned(unsigned int nb, char c, struct specif S)
{
	int base;

	base = 2;
	if (c == 'x' || c == 'X')
		base = 16;
	else if (c == 'O' || c == 'o')
		base = 8;
	else if (c == 'u' || c == 'U')
		base = 10;
	afficher_nb((int)nb, base, c);
	return (taille_nb((int)nb, base));
}
