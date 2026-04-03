/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciparren <ciparren@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 17:16:46 by cintia            #+#    #+#             */
/*   Updated: 2026/04/03 12:23:00 by ciparren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	search_n(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == SEPARATOR)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *storage, char *str2)
{
	char	*res;
	int		len1;
	int		i;

	if (!str2)
		return (NULL);
	len1 = ft_strlen(storage);
	res = malloc(sizeof(char) * (len1 + ft_strlen(str2) + 1));
	if (!res)
	{
		free(storage);
		return (NULL);
	}
	i = -1;
	while (storage && storage[++i])
		res[i] = storage[i];
	i = -1;
	while (str2[++i])
		res[len1 + i] = str2[i];
	res[len1 + i] = '\0';
	free(storage);
	return (res);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	s_len;
	size_t	i;

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
