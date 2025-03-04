/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamijo <skamijo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 03:46:42 by skamijo           #+#    #+#             */
/*   Updated: 2025/02/13 03:46:50 by skamijo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

size_t	ft_linelen(char *s);
int		ft_hasline(char *s);
char	*ft_strndup(char *s, size_t l);
char	*ft_strjoin2(char *s1, char *s2);
char	*get_next_line(int fd);

#endif
