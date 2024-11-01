/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamijo <skamijo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:11:01 by skamijo           #+#    #+#             */
/*   Updated: 2024/10/29 15:29:46 by skamijo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#define BUFFER_SIZE 8192

typedef struct s_fd_info
{
	int	fd;
	int	line_num;
}		t_fd_info;

// t_fd_info	*allocate_info_mem(fd)

// static変数に構造体配列をいれる
char	*get_next_line(int fd)
{
	// static t_fd_info	*info;
}
