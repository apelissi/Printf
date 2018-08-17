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

int	taille(const char *str)
{
	int i; 

	i = 0;
	while (str[i] && !(identifieur(str[i])))
		i++;
	return (i + 2);
}

char	identification(const char *str)
{
	while (*str && !(identifieur(*str)))
		str++;
	return ((char)*str);
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
			c = identification(&format[i + 1]);
			if (c == 'd' || c == 'D' || c == 'c' || c == 'i')
				tot += afficher_int(va_arg(ap, int), c, flags(&format[i + 1]));
			else if (c == 'o' || c == 'O' || c == 'u' || c == 'U' || c == 'x' || c == 'X')
			tot += afficher_unsigned(va_arg(ap, unsigned int), c, flags(&format[i + 1]));
			else if (c == 's')
				tot += afficher_constchar(va_arg(ap, const char *), flags(&format[i + 1]));
		//	else if (c == 'S')
		//		afficher_constwchar_t(va_arg(ap, const wchar_t));
			else if (c == 'p')
				tot += afficher_ptr(va_arg(ap, void *), flags(&format[i + 1]));
		//	else if (c == 'C')
		//		afficher_wint_t(va_arg(ap, wint_t));
			else if (c == '%')
				tot += write(1, "%", 1);
			i += taille(&format[i + 1]);
		}
	}
	va_end(ap);
	return (tot);
}
