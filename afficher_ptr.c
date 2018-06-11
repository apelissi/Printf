#include "ft_printf.h"

int	afficher_ptr(void *p)
{
	unsigned char t[sizeof p];
	int i;

	i = sizeof p - 3;
	ft_memcpy(t, &p, sizeof p);
	write(1, "0x", 2);
	while (i >= 0) 
	{
		if (t[i] < 16)
			write(1, "0", 1);
		afficher_nb((int)t[i], 16, 'a');
		i--;
	}
	return (14);
}
