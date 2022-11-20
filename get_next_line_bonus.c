/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsa-mora <dsa-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 16:42:15 by dsa-mora          #+#    #+#             */
/*   Updated: 2022/11/19 16:42:19 by dsa-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

//Caso o buffer seja menor que 0 ou o fd nao seja valido retorna-se NULL
//Esta funcao ira ler a primeira linha de um ficheiro caso seja chamada, 
//e caso seja chamada de novo ira ler a linha a seguir do ficheiro, etc...
//Caso ja nao haja mais linhas no ficheiro para ler e se 
//continue a chamar a funcao ela ira retorna NULL 
char	*get_next_line(int fd)
{
	static char	buffer[FOPEN_MAX + 1][BUFFER_SIZE + 1];
	char		*line;
	int			i;
	int			j;
	int			flag;

	if (BUFFER_SIZE <= 0 || (read(fd, 0, 0) < 0))
		return (NULL);
	line = NULL;
	flag = 0;
	while (!flag && (buffer[fd][0] || (read(fd, buffer[fd], BUFFER_SIZE) > 0)))
	{
		line = ft_strjoin(line, buffer[fd]);
		i = 0;
		j = 0;
		while (buffer[fd][i])
		{
			if (flag)
				buffer[fd][j++] = buffer[fd][i];
			if (buffer[fd][i] == '\n')
				flag = 1;
			buffer[fd][i++] = 0;
		}
	}
	return (line);
}
