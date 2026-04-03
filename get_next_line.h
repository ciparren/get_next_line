/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciparren <ciparren@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 17:16:38 by cintia            #+#    #+#             */
/*   Updated: 2026/04/03 13:00:59 by ciparren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# define SEPARATOR '|'

char	*get_next_line(int fd);
int		ft_strlen(const char *str);
int		search_n(char *str);
char	*ft_strjoin(char *str1, char *str2);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif