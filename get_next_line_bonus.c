/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabreu-d <jabreu-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 17:23:58 by jabreu-d          #+#    #+#             */
/*   Updated: 2023/03/17 17:23:58 by jabreu-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buffer[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*line;
	int			flag;
	int			i;
	int			i_0;

	if (BUFFER_SIZE < 1 || fd > FOPEN_MAX || read(fd, 0, 0) < 0)
		return (ft_freebuffer(buffer[fd], fd));
	line = NULL;
	flag = 0;
	while (!flag && (buffer[fd][0] || (read(fd, buffer[fd], BUFFER_SIZE) > 0)))
	{
		i = 0;
		i_0 = 0;
		line = ft_strjoin_gnl(line, buffer[fd]);
		while (buffer[fd][i])
		{
			if (flag)
				buffer[fd][i_0++] = buffer[fd][i];
			if (buffer[fd][i] == '\n')
				flag = 1;
			buffer[fd][i++] = 0;
		}
	}
	return (line);
}

/* int	main(void)
{
	char *a;
	int b;

	char *c;
	int d;

	b = open("pacha.txt", O_RDONLY);
	a = get_next_line(b);
	printf("Get_Next_Line: %s\n", a);

	d = open("pacha.txt", O_RDONLY);
	c = get_next_line(b);
	printf("Get_Next_Line: %s\n", c);
} */