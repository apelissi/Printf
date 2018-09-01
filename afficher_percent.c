#include "ft_printf.h"

void	ft_percent_field(t_specif s)
{
	while (s.field > 1)
		s.field -= write(1, " ", 1);
}

int	afficher_percent(t_specif s)
{
	if (s.flags % 5)
		ft_percent_field(s);
	write(1, "%", 1);
	if (!(s.flags % 5))
		ft_percent_field(s);
	if (s.field > 0)
		return (s.field);
	return (1);
}	
