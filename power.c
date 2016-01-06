#include "Header.h"

int		get_power(int nb)
{
	int		power;

	power = 0;
	while ((power * power) < nb * 4)
		power++;
	return (power);
}