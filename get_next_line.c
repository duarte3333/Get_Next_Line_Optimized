/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsa-mora <dsa-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 18:01:12 by dsa-mora          #+#    #+#             */
/*   Updated: 2022/11/08 20:08:08 by dsa-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


//Caso o buffer seja menor que 0 ou o fd nao seja valido retorna-se NULL
//Esta funcao ira ler a primeira linha de um ficheiro caso seja chamada, 
//e caso seja chamada de novo ira ler a linha a seguir do ficheiro, etc...
//Caso ja nao haja mais linhas no ficheiro para ler e se 
//continue a chamar a funcao ela ira retorna NULL 
char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	int			i;
	int			j;
	int			flag;

	if (BUFFER_SIZE <= 0 || (read(fd, 0, 0) < 0))
		return (NULL);
	line = NULL;
	flag = 0;
	while (!flag && (buffer[0] || (read(fd, buffer, BUFFER_SIZE) > 0)))
	{
		line = ft_strjoin(line, buffer);
		i = 0;
		j = 0;
		while (buffer[i])
		{
			if (flag)
				buffer[j++] = buffer[i];
			if (buffer[i] == '\n')
				flag = 1;
			buffer[i++] = 0;
		}
	}
	return (line);
}

// printf("MY STRING \n%s\n", line);
// printf("READY: \n %s\n", ready_line);
// printf("HOW I AM NEXT\n %s\n", line);

// int	main(void)
// {
// 	int	fd;
// 	char *s;

// 	fd = open("oi.txt", O_RDONLY);
// 	s = get_next_line(fd);
// 	printf("VALOR FD: %i\n", fd);
// /* 	printf("\033[0;32m");
// 	printf("ITERATION 1  \n");
// 	printf("\033[0m"); */
// 	printf("\nOUTPUT 1 Iteration: %s\n", s); free(s);
// 	printf("-----------------------------------------------\n");
// /* 	printf("\033[0;32m");
// 	printf("ITERATION 2  \n");
// 	printf("\033[0m"); */
// 	s = get_next_line(fd); printf("\nOUTPUT 2 Iteration: %s\n", s); free(s);
// 	printf("-----------------------------------------------\n");
// /* 	printf("\033[0;32m");
// 	printf("ITERATION 3  \n");
// 	printf("\033[0m"); */
// 	s = get_next_line(fd); printf("\nOUTPUT 3 Iteration: %s\n", s); free(s);
// 	printf("-----------------------------------------------\n");
// 	s = get_next_line(fd); printf("\nOUTPUT 3 Iteration: %s\n", s); free(s);
// 	printf("-----------------------------------------------\n");
// 	s = get_next_line(fd); printf("\nOUTPUT 3 Iteration: %s\n", s); free(s);
// 	printf("-----------------------------------------------\n");
// }

