/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciparren <ciparren@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 17:16:46 by cintia            #+#    #+#             */
/*   Updated: 2026/02/22 16:08:03 by ciparren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// todas las funciones de ayuda
// añadir esta opcion a la llamada de tu compilador: -D BUFFER_SIZE=n
// no se puede usar LIBFT
// 

int     ft_strlen(const char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

int     search_n(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char    *ft_strjoin(char *str1, char *str2)
{
    char	*res;
	int		i;
	int		j;

	if (!str1)
	{
		str1 = malloc(1);
		if (!str1)
			return (NULL);
		str1 = '\0';
	}
	if (!str2)
		return (NULL);
	res = malloc(sizeof(char) * (long_str(str1) + long_str(str2) + 1));
	if (!res)
		return (NULL);	
	i = -1;
	while (str1[++i])
		res[i] = str1[i];
	j = 0;
	while (str2[j])
		res[i++] = str2[j++];
	res[i] = '\0';

    // entender bien por qué debo hacer este free
	free(str1);

	return (res);
}
char    *ft_substr(char const *s, unsigned int start, size_t len)
{
        char    *res;
        size_t  s_len;
        size_t  i;

        if (!s)
                return (NULL);
        s_len = ft_strlen(s);
        if (start >= s_len)
        {
                res = (char *)malloc(1);
                if (!res)
                        return (NULL);
                *res = '\0';
                return (res);
        }
        if (len > s_len - start)
                len = s_len - start;
        res = (char *)malloc(sizeof(char) * (len + 1));
        if (!res)
                return (NULL);
        i = -1;
        while (++i < len)
                res[i] = s[start + i];
        res[i] = '\0';
        return (res);
}

