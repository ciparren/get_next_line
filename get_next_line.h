/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciparren <ciparren@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 17:16:38 by cintia            #+#    #+#             */
/*   Updated: 2026/02/22 16:44:10 by ciparren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

// SÓLO SE PUEDEN USAR read, malloc y free

// Medir la longitud de un string.
// Buscar un salto de línea (\n) dentro de un string.
// Unir dos strings (similar a strjoin) para ir acumulando lo que lees.
// Extraer una parte de un string (para sacar la línea final o guardar el sobrante).




char    *get_next_line(int fd);

// utils
int     strl(const char *str);
int     search_n(char *str);
char    *strj(char *str1, char *str2);
char    *subs(char const *s, unsigned int start, size_t len);


#endif