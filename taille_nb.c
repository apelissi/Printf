int	taille_nb(int nb, int base)
{
	int	taille;
	int	div;

	taille = 1;
	if(nb < 0)
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
