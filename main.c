#include "Header.h"

int		main(void)
{
	char	*fname;
	char	*fname2;
	char	**tab;
	int		index;
	char	***dim;
	int		nb; //DELETE

	nb = 0; //DELETE
	index = 0;
	fname = "all.txt";
	fname2 = "Text.txt";
	tab = get_in_tab(fname);
	/*while (tab[index] != NULL)
	{
		printf("%s", tab[index]);
		index++;
	}*/
	printf("\n");
	check_maps(tab);
	check_isnbrtrue(tab);
	dim = three_dim(tab);
	while (dim[nb] != NULL)
	{
		nb++;
	}
	printf("Check_links : %d\n", check_link(dim));
	printf("cases = %d\n", nb);
	dim = three_dim(tab);
	dim = cut_tetra(dim);
	turn_letter(tab);
	resolver(dim, nb);
	//printf("%s", dim[0][1]);
	return (0);
}
