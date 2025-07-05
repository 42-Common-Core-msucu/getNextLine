/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msucu <msucu@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 23:48:53 by msucu             #+#    #+#             */
/*   Updated: 2025/07/05 12:54:18 by msucu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strchr(char const *s, int c)
{
	char	letter;

	letter = (char) c;
	while (*s && *s != letter)
		s++;
	if (*s == letter)
		return ((char *) s);
	else
		return (FT_NULL);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (d == s || n == 0)
		return (dest);
	if (d > s && d < s + n)
	{
		while (n--)
			d[n] = s[n];
	}
	else
	{
		while (n--)
			*d++ = *s++;
	}
	return (dest);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*newstr;

	if (s1 == FT_NULL || s2 == FT_NULL)
		return (FT_NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	newstr = malloc((s1_len + s2_len + 1) * sizeof(char));
	if (newstr == FT_NULL)
		return (FT_NULL);
	ft_memmove(newstr, s1, s1_len);
	ft_memmove(newstr + s1_len, s2, s2_len);
	newstr[s1_len + s2_len] = '\0';
	free(s1);
	return (newstr);
}
