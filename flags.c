#include "ft_printf.h"

int	is_flag(char c)
{
	if (c == '#') 
		return (2);
	else if (c ==  '0')
		return (3);
	else if (c ==  '-')
		return (5);
	else if (c == '+') 
		return (7);
	else if (c == ' ')
		return (11);
	return (0);
}

int	flags(const char *str)
{
	int	i;
	int	F;

	F = 1;
	i = 0;
	while (is_flag(str[i]))
	{	
		F = F * is_flag(str[i]);
		i++;
	}
	return (F);
}
