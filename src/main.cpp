//
// Created by spaciwork on 10/03/18.
//

#include <iostream>
#include "../include/parser.hpp"
#include "../include/Core.hpp"

int	main(int ac, char **av)
{
	int	return_value;

	//return_value = parser(ac, av);
	if (return_value == 0)
		arcade(av[1], av[2]);
	exit(0);
}