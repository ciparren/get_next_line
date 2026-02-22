/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciparren <ciparren@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 17:16:43 by cintia            #+#    #+#             */
/*   Updated: 2026/02/22 16:39:18 by ciparren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


// asegurarse de que funciona bien cuando lee de archivo y cuando lee de input normal
// la linea devuelta debe incluir el \n menos cuando se ha llegado al final del archivo
// 
char *extract_line(char *storage)
{	
	int	i;
	char	*str;
	
	i = 0;
	if(!storage || storage == '\0')
		return (NULL);
	while(storage[i] && storage[i] != '\n')
		i++;
	if(storage[i] == '\n')
		i++;
	str = ft_substr(storage, 0, i);
	return (str);
}

char *clean_storage(char *storage)
{
	int	i;
	char	*tmp;

	tmp = malloc(sizeof(BUFFER_SIZE) + 1);
	if(!storage)
		return (NULL);
	i = 0;
	while(storage[i] && storage[i] != '\n')
		i++;
	if(storage[i] == '\0')
	{
		free(storage);
		return (NULL);
	}
	else if(storage[i] == '\n')
	{
		i++;
		tmp = ft_substr(storage, i, ft_strlen(storage));
		free(storage);
	}
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*storage; // Aquí guardaremos lo que sobre después del \n
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	storage = read_and_store(fd, storage);
	if (!storage)
		return (NULL);
	// 3. Extraer la línea exacta que vamos a devolver
	line = extract_line(storage);

	// 4. Actualizar 'storage' dejando solo el texto sobrante
	storage = clean_storage(storage);

	return (line);
}

char	*read_and_store(int fd, char *storage)
{
	char	*buffer;
	int		bytes_read;

	// Reservamos memoria para el buffer temporal (+1 para el '\0')
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	// El bucle sigue mientras no haya un '\n' y no hayamos llegado al final (EOF)
	while (!search_n(storage) && bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1) // Error de lectura
		{
			free(buffer);
			free(storage); // Evitamos leaks si hay error
			return (NULL);
		}
		buffer[bytes_read] = '\0'; // Terminamos el string leído
		storage = joinstr(storage, buffer); // Lo unimos a lo que ya teníamos
	}
	free(buffer); // Ya no necesitamos el buffer temporal
	return (storage);
}