/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msucu <msucu@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 23:48:55 by msucu             #+#    #+#             */
/*   Updated: 2025/07/05 12:52:07 by msucu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stddef.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# define FT_NULL 0

size_t	ft_strlen(const char *s);
char	*ft_strchr(char const *s, int c);
void	*ft_memmove(void *dest, const void *src, size_t n);
char	*ft_strjoin(char *s1, char const *s2);
void	ft_reset_str(char *str, size_t n);

char	*get_next_line(int fd);

#endif
