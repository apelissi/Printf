#include "stdio.h"
#include "ft_printf.h"
#include <wchar.h>


static void test_simple_mix(void)
{
		int i;
		int	j;

		i = printf("%p\n", &i);
		j = ft_printf("%p\n", &i);
		printf("%d VS %d\n", i, j);
} 
		

int main(void)
{
	long long i;
	long long j;
	wchar_t	o;
	long *c;

	o = 0;
	i = 22222222222;

	printf ("%hli", i); 
//	i = printf("%p", NULL);
//	j = 0;
//	i = printf("%s", NULL);
//	printf("\n%d\n", i);
	
//	test_simple_mix();
	
	//	ft_printf("%U", 42);
/*	printf("\n%d\n", i);
	
	//i = printf("{%}");
	printf("\n%d\n", i);

	i = printf("s: %s, p: %p, d:%d\n", "a string", NULL, 42);
	j = ft_printf("s: %s, p: %p, d:%d\n", 42, 42, 42);
	printf("%d vs %d\n", i, j);

	while (o < 2000)
	{
		write(1, &o, 1);
		write(1, "  ", 2);
		i++;
	}*/
	return(0);
}
