/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 13:11:45 by apelissi          #+#    #+#             */
/*   Updated: 2018/08/23 16:42:58 by apelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"
#include "ft_printf.h"

int	main(void)
{
/* 	
	int i;

	i = 450;
	printf("->(%s)\n", "ueiuefhuieziyh");
	write(1, "\t---\n->[", 9);
	ft_printf("ooo\\ooo\\po");
	write(1, "]\n", 3);
*/

/*	t_specif s;

	s = check_spe("#.458d");
	printf("flags = %d\nfield = %d\npreci = %d\n", s.flags, s.field, s.preci);
*/

/*	int i;
	int a;
	int b;

	i = 'a';

	a = printf("A-> -[%c]-\n", i);
	b = ft_printf("A-> -[%c]-\n", i);
	printf("%d VS %d\n\n", a, b);

	a = printf("B-> -[%-20c]-\n", i);
	b = ft_printf("B-> -[%-20c]-\n", i);
	printf("%d VS %d\n\n", a, b);

	a = printf("C-> -[%.12d]-\n", i);
	b = ft_printf("C-> -[%.12d]-\n", i);
	printf("%d VS %d\n\n", a, b);

	a = printf("D-> -[% d]-\n", i);
	b = ft_printf("D-> -[% d]-\n", i);
	printf("%d VS %d\n\n", a, b);

	a = printf("E-> -[%+d]-\n", i);
	b = ft_printf("E-> -[%+d]-\n", i);
	printf("%d VS %d\n\n", a, b);

	a = printf("F-> -[%-d]-\n", i);
	b = ft_printf("F-> -[%-d]-\n", i);
	printf("%d VS %d\n\n", a, b);

	a = printf("G-> -[% 20d]-\n", i);
	b = ft_printf("G-> -[% 20d]-\n", i);
	printf("%d VS %d\n\n", a, b);

	a = printf("H-> -[%+20d]-\n", i);
	b = ft_printf("H-> -[%+20d]-\n", i);
	printf("%d VS %d\n\n", a, b);

	a = printf("I-> -[%-20.12d]-\n", i);
	b = ft_printf("I-> -[%-20.12d]-\n", i);
	printf("%d VS %d\n\n", a, b);

	printf("J-> -[%0 20d]-\n", i);
	ft_printf("J-> -[%0 20d]-\n", i);
	printf("%d VS %d\n\n", a, b);*/


/*	long l;

	l = 2147483648;
	printf("%d\n", l);
	afficher_nb(l, 10, 'a');
	write(1, "\n", 1);
*/
	
/*	unsigned int j;

	j = 3147483648;

	a = printf("A-> -[%X]-\n", j);
	b = ft_printf("A-> -[%X]-\n", j);
	printf("%d VS %d\n\n", a, b);

	a = printf("B-> -[%-20o]-\n", j);
	b = ft_printf("B-> -[%-20o]-\n", j);
	printf("%d VS %d\n\n", a, b);

	a = printf("C-> -[%.12o]-\n", j);
	b = ft_printf("C-> -[%.12o]-\n", j);
	printf("%d VS %d\n\n", a, b);

	a = printf("D-> -[%#o]-\n", j);
	b = ft_printf("D-> -[%#o]-\n", j);
	printf("%d VS %d\n\n", a, b);

	a = printf("E-> -[%#x]-\n", j);
	b = ft_printf("E-> -[%#x]-\n", j);
	printf("%d VS %d\n\n", a, b);

	a = printf("F-> -[%-o]-\n", j);
	b = ft_printf("F-> -[%-o]-\n", j);
	printf("%d VS %d\n\n", a, b);

	a = printf("G-> -[%20o]-\n", j);
	b = ft_printf("G-> -[%20o]-\n", j);
	printf("%d VS %d\n\n", a, b);

	a = printf("H-> -[%20o]-\n", j);
	b = ft_printf("H-> -[%20o]-\n", j);
	printf("%d VS %d\n\n", a, b);

	a = printf("I-> -[%-20.12o]-\n", j);
	b = ft_printf("I-> -[%-20.12o]-\n", j);
	printf("%d VS %d\n\n", a, b);

	printf("J-> -[%-20o]-\n", j);
	ft_printf("J-> -[%-20o]-\n", j);
	printf("%d VS %d\n\n", a, b);



	char *k;

	k = "Hello world.";

	a = printf("A-> -[%s]-\n", k);
	b = ft_printf("A-> -[%s]-\n", k);
	printf("%d VS %d\n\n", a, b);

	a = printf("B-> -[%-20s]-\n", k);
	b = ft_printf("B-> -[%-20s]-\n", k);
	printf("%d VS %d\n\n", a, b);

	a = printf("C-> -[%.12s]-\n", k);
	b = ft_printf("C-> -[%.12s]-\n", k);
	printf("%d VS %d\n\n", a, b);

	a = printf("D-> -[%.30s]-\n", k);
	b = ft_printf("D-> -[%.30s]-\n", k);
	printf("%d VS %d\n\n", a, b);

	a = printf("E-> -[%.1s]-\n", k);
	b = ft_printf("E-> -[%.1s]-\n", k);
	printf("%d VS %d\n\n", a, b);

	a = printf("F-> -[%-s]-\n", k);
	b = ft_printf("F-> -[%-s]-\n", k);
	printf("%d VS %d\n\n", a, b);

	a = printf("G-> -[%20s]-\n", k);
	b = ft_printf("G-> -[%20s]-\n", k);
	printf("%d VS %d\n\n", a, b);

	a = printf("H-> -[%20.1s]-\n", k);
	b = ft_printf("H-> -[%20.1s]-\n", k);
	printf("%d VS %d\n\n", a, b);

	a = printf("I-> -[%-20.12s]-\n", k);
	b = ft_printf("I-> -[%-20.12s]-\n", k);
	printf("%d VS %d\n\n", a, b);

	printf("J-> -[%20s]-\n", k);
	ft_printf("J-> -[%20s]-\n", k);
	printf("%d VS %d\n\n", a, b);





	a = printf("A-> -[%%]-\n");
	b = ft_printf("A-> -[%%]-\n");
	printf("%d VS %d\n\n", a, b);

 	a = printf("A-> -[%5%]-\n");
	b = ft_printf("A-> -[%5%]-\n");
	printf("%d VS %d\n\n", a, b);

	a = printf("A-> -[%-5%]-\n");
	b = ft_printf("A-> -[%-5%]-\n");
	printf("%d VS %d\n\n", a, b);

	int *p;

	p = &i;
	a = printf("A-> -[%p]-\n", p);
	b = ft_printf("A-> -[%p]-\n", p);
	printf("%d VS %d\n\n", a, b);

	a = printf("B-> -[%55p]-\n", p);
	b = ft_printf("B-> -[%55p]-\n", p);
	printf("%d VS %d\n\n", a, b);

	a = printf("C-> -[%-55p]-\n", p);
	b = ft_printf("C-> -[%-55p]-\n", p);
	printf("%d VS %d\n\n", a, b);*/

	int	i;

	i = 6;
	printf("-[%C et %d]-\n", i, i);
	ft_printf("-[%C et %d]-\n", i, i);
}
























