/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamijo <skamijo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 14:41:53 by skamijo           #+#    #+#             */
/*   Updated: 2025/03/01 15:44:18 by skamijo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

bool	ft_check(int paramc, int *paramv)
{
	(void)paramc;
	(void)paramv;
	return (true);
}

int	main(int argc, char **argv)
{
	int	*parsed_arr;

	if (argc >= 2)
	{
		// validate input
		if (!validate_input(argc - 1, argv + 1))
		{
			ft_printf("Error\n");
			return (EXIT_FAILURE);
		}
		// parse input
		parsed_arr = parse_input(argc - 1, argv + 1);
		print_parsed_arr(parsed_arr);
		// check for duplicates
		if (has_duplicates(argc - 1, parsed_arr))
		{
			ft_printf("Error\n");
			return (EXIT_FAILURE);
		}
		// check input
		ft_check(argc - 1, parsed_arr);
		// print output
		free(parsed_arr);
	}
	return (EXIT_SUCCESS);
}
