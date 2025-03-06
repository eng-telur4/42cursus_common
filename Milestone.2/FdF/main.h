/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamijo <skamijo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 09:29:33 by skamijo           #+#    #+#             */
/*   Updated: 2025/03/03 09:48:14 by skamijo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "inc/ft_printf.h"
# include "inc/get_next_line.h"
# include "inc/libft.h"
# include "inc/mlx.h"
# include <fcntl.h>   // open, O_RDONLY
# include <stdbool.h> // bool
# include <stdio.h>   // printf
# include <stdlib.h>  // malloc, EXIT_SUCCESS
// Bidirectional Circulation List
typedef struct s_bclst
{
	int				data;
	struct s_bclst	*next;
	struct s_bclst	*prev;
}					t_bclst;

#endif
