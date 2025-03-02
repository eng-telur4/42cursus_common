/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamijo <skamijo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 04:42:16 by skamijo           #+#    #+#             */
/*   Updated: 2025/03/01 14:44:30 by skamijo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include <stdbool.h>
#include <stdlib.h> // malloc, EXIT_SUCCESS

void	print_parsed_arr(int *arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		ft_printf("parsed_arr[%d]: %d\n", i, arr[i]);
		i++;
	}
}

bool	validate_input(int paramc, char **paramv)
{
	int	i;

	i = 0;
	if (paramc < 3)
		return (false);
	while (i < paramc)
	{
		if (!ft_isinteger(paramv[i]))
			return (false);
		i++;
	}
	return (true);
}
int	*parse_input(int paramc, char **paramv)
{
	int	*ret;
	int	i;

	ret = malloc(sizeof(int) * paramc);
	i = 0;
	while (i < paramc)
	{
		ret[i] = ft_atoi(paramv[i]);
		i++;
	}
	return (ret);
}

bool	has_duplicates(int paramc, int *paramv)
{
	int	i;
	int	j;

	i = 0;
	while (i < paramc)
	{
		j = i + 1;
		while (j < paramc)
		{
			if (paramv[i] == paramv[j])
				return (true);
			j++;
		}
		i++;
	}
	return (false);
}

int	*ft_sort_three(int paramc, int *paramv)
{
	int	*ret;

	ret = malloc(sizeof(int) * paramc);
	if (paramv[0] > paramv[1]) // 213, 312, 321
	{
		if (paramv[1] > paramv[2]) // 321
			ft_printf("ra\nsa\n");
		else if (paramv[0] > paramv[2]) // 312
			ft_printf("ra\n");
		else // 213
			ft_printf("sa\n");
	}
	else // paramv[0] < paramv[1] // 123, 132, 231
	{
		if (paramv[0] > paramv[2]) // 231
			ft_printf("rra\n");
		else if (paramv[1] > paramv[2]) // 132
			ft_printf("rra\nsa\n");
	}
	return (ret);
}

int	*ft_sort_six(int paramc, int *paramv)
{
	int	*ret;

	(void)paramv;
	ret = malloc(sizeof(int) * paramc);
	return (ret);
}

int	*ft_sort_big(int paramc, int *paramv)
{
	int	*ret;

	(void)paramv;
	ret = malloc(sizeof(int) * paramc);
	return (ret);
}

int	*ft_sort(int paramc, int *paramv)
{
	int	*ret;

	ft_printf("paramc: %d\n", paramc);
	ret = malloc(sizeof(int) * paramc);
	if (paramc == 3)
		ret = ft_sort_three(paramc, paramv);
	else if (paramc <= 6)
		ret = ft_sort_six(paramc, paramv);
	else
		ret = ft_sort_big(paramc, paramv);
	return (ret);
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
		// sort input
		ft_sort(argc - 1, parsed_arr);
		// print output
		free(parsed_arr);
	}
	return (EXIT_SUCCESS);
}
