/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabreu-d <jabreu-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:47:00 by jabreu-d          #+#    #+#             */
/*   Updated: 2023/03/17 16:47:00 by jabreu-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_freebuffer(char *buffer, int fd)
{
	int	i;

	if (fd > FOPEN_MAX || fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	i = 0;
	while (buffer[i])
	{
		buffer[i] = 0;
		i++;
	}
	return (NULL);
}

int	ft_strlen_gnl(const char *string)
{
	int	len;

	len = 0;
	if (!string)
		return (0);
	while (string[len] && string[len] != '\n')
		len++;
	if (string[len] == '\n')
		len++;
	return (len);
}

char	*ft_strjoin_gnl(char *line, char *buffer)
{
	char	*newline;
	int		i;
	int		j;
	int		line_len;
	int		buff_len;

	if (!buffer)
		return (NULL);
	line_len = ft_strlen_gnl(line);
	buff_len = ft_strlen_gnl(buffer);
	newline = malloc(sizeof newline * line_len + buff_len + 1);
	if (!newline)
		return (NULL);
	i = -1;
	j = i;
	while (++i < line_len)
		newline[i] = line[i];
	while (++j < buff_len)
		newline[i + j] = buffer[j];
	newline[i + j] = 0;
	free (line);
	return (newline);
}
