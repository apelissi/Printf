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
 *
 *	int i;

	i = 450;
	printf("->(%s)\n", "ueiuefhuieziyh");
	write(1, "\t---\n->[", 9);
	ft_printf("ooo\\ooo\\po");
	write(1, "]\n", 3);
*/
/*	t_specif s;

	s = check_spe("#.458d");
	printf("flags = %d\nfield = %d\npreci = %d\n", s.flags, s.field, s.preci);*/

	int i;

	i = 25;

	printf("-> -[%d]-\n", i);
	ft_printf("-> -[%d]-\n\n", i);

	printf("-> -[%+20d]-\n", i);
	ft_printf("-> -[%+20d]-\n\n", i);

	printf("-> -[%-20d]-\n", i);
	ft_printf("-> -[%-20d]-\n\n", i);

	printf("-> -[%020d]-\n", i);
	ft_printf("-> -[%020d]-\n\n", i);

	printf("-> -[%0-20.5d]-\n", i);
	ft_printf("-> -[%0-20.5d]-\n\n", i);

	printf("-> -[%20.5d]-\n", i);
	ft_printf("-> -[%20.5d]-\n\n", i);

	printf("-> -[% 20d]-\n", i);
	ft_printf("-> -[% 20d]-\n\n", i);

	printf("-> -[%+20d]-\n", i);
	ft_printf("-> -[%+20d]-\n\n", i);

	printf("-> -[%0+20.5d]-\n", i);
	ft_printf("-> -[%0+20.5d]-\n\n", i);

	printf("-> -[% .5d]-\n", i);
	ft_printf("-> -[% .5d]-\n\n", i);
	return (0);
}
























