#include "string.h"
#include "unistd.h"
#include "stdarg.h"
#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	t;

	t = 0;
	while (s[t])
		t++;
	return (t);
}

int	identifieur(char c)
{
	if (c == 's' || c == 'S'|| c == 'p' || c == 'd' || c == 'D' || c == 'i' 
	|| c == 'o' || c == 'O' || c == 'u' || c == 'U' || c == 'x' || c == 'X'
	|| c == 'c' || c == 'C' || c == '%')
		return(1);
	else
		return(0);

}

char	identification(const char *str)
{
	int i;

	i = 0;
	while (str[i] || !(identifieur(str[i])))
		i++;
	return ((char)str[i]);
}

int	ft_printf(const char *format,...)
{
	va_list	ap;
	int	i;
	int	tot;
	char	c;

	va_start(ap, format);
	i = 0;
	tot = 0;
	while(format[i])
	{
		if (format[i] != '%')
		{
			write (1, &format[i], 1);
			tot++;
			i++;
		}
		else
		{
			c = identification(&format[i]);
			if (c == 'd' || c == 'D' || c == 'c' || c == 'i')
				afficher_int(va_arg(ap, int), c);
			else if (c == 'o' || c == 'O' || c == 'u' || c == 'U'
			|| c == 'x' || c == 'X')
				afficher_unsigned(va_arg(ap, unsigned int), c);
			else if (c == 's')
				afficher_constchar(va_arg(ap, const char *));
		//	else if (c == 'S')
		//		afficher_constwchar_t(va_arg(ap, const wchar_t));
			else if (c == 'p')
				afficher_ptr(va_arg(ap, void *));
		//	else if (c == 'C')
		//		afficher_wint_t(va_arg(ap, wint_t));
			else if (c == '%')
				write(1, "%", 1);
		}
	}
	va_end(ap);
	return (tot);
}
