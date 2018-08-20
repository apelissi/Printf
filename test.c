/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 13:11:45 by apelissi          #+#    #+#             */
/*   Updated: 2018/08/20 16:39:16 by apelissi         ###   ########.fr       */
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
	t_specif s;

	s = check_spe("#.458d");
	printf("flags = %d\nfield = %d\npreci = %d\n", s.flags, s.field, s.preci);

/*	int i;

	i = 53;

	printf("d -> -[%20d]-\n", i);
	printf("D -> -[%20D]-\n", i);
	printf("c -> -[%20c]-\n", i);
	printf("i -> -[%+.3i]-\n", i);	*/
	return (0);
}


























