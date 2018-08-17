#include "ft_printf.h"

int	afficher_constchar(const char *str, struct specif S)
{
	int i;

	i = 0;
	while(str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return(i);
}
