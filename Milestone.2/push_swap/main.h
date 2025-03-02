/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamijo <skamijo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 05:56:46 by skamijo           #+#    #+#             */
/*   Updated: 2025/03/01 15:35:53 by skamijo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "inc/ft_printf.h"
# include "inc/ft_utils.h"
# include "inc/get_next_line.h"
# include "inc/libft.h"
# include <stdbool.h> // bool

// Bidirectional Circulation List
typedef struct s_bclst
{
	int				data;
	struct s_bclst	*next;
	struct s_bclst	*prev;
}					t_bclst;

#endif
