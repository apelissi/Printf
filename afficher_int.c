#include "ft_printf.h"

int	afficher_int(int nb, char c)
{
	unsigned char R;

	if (c == 'c')
	{
		R = (unsigned char)nb;
		write(1, &R, 1);
		return (1);
	}
	else
	{
		afficher_nb(nb, 10, 'a');
		return (taille_nb(nb, 10));
	}
}
