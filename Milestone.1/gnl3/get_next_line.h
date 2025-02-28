/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamijo <skamijo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 21:40:10 by skamijo           #+#    #+#             */
/*   Updated: 2025/02/28 22:09:27 by skamijo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

size_t	ft_strlen(const char *str);
char	*ft_substr(char const *str, unsigned int start, size_t len);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
int		ft_strchr_index(const char *str, int c);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
char	*get_next_line(int fd);
char	*ft_shrink_buffer(char *buffer, char *line);
char	*ft_expand_buffer(char *buffer, int fd);
char	*ft_new_read(int fd);

#endif
