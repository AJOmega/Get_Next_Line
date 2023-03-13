#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	int			is_newline;
	int			i;
	int			j;

	line = NULL;
	is_newline = 0;
	if (BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
		return ("-1"); //Placeholder
	while ((!is_newline && buffer[0]) && read(fd, buffer, BUFFER_SIZE) > 0)
	{
		i = 0;
		j = 0;
		line = ft_strjoin(line, buffer); //Placeholder
		while (buffer[i])
		{
			if (is_newline)
				buffer[j++] = buffer[i];
			if (buffer[i] == '\n')
				is_newline = 1;
			buffer[i++] = 0;
		}
	}
	return (line);
}

int	main(void)
{
	char *a;
	int b;

	b = open("aba.txt", O_RDONLY);
	a = get_next_line(b);
	printf("Get_Next_Line: %s\n", a);
}
