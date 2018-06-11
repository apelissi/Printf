#include "unistd.h"

void	afficher_nb(int nb, int base, char casse)
{
	int div;
	char c;

	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	if (nb == 0)
		write(1, "0", 1);
	else
	{
		div = 1;
		while (nb / div >= base)
			div = div * base;
		while (div != 0)
		{
			if ( nb / div < 10)
				c = '0' + nb / div;
			else
			{	
				if (casse >= 'a' && casse <= 'z')
					c = 'a' + nb / div - 10;
				else
					c = 'A' + nb / div - 10;
			}
			write(1, &c, 1);
			nb = nb % div;
			div = div / base;
		}
	}
}
