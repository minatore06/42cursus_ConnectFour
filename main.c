#include "connect4.h"

int	main(int argc, char **argv)
{
	if (argc != 3)
		return (0);
	if (ft_atoi(argv[1]) < 6 || ft_atoi(argv[2]) < 7)
	{
		ft_printf("Error: Invalid size\n");
		return (0);
	}
	return (0);
}