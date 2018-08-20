/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   taille_nb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 13:11:01 by apelissi          #+#    #+#             */
/*   Updated: 2018/08/20 13:11:38 by apelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	taille_nb(int nb, int base)
{
	int	taille;
	int	div;

	taille = 1;
	if (nb < 0)
	{
		taille++;
		nb = -nb;
	}
	div = 1;
	while (nb / div >= base)
	{
		taille++;
		div = div * base;
	}
	return (taille);
}
