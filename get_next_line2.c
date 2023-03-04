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
	char		line[BUFFER_SIZE + 1];
	char		read_line[BUFFER_SIZE + 1];
	static char	*next_line;
	int			count;
	int			i;
	int			j;

	i = 0;
	j = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (-1);
	count = read(fd, read_line, BUFFER_SIZE);
	while (read_line[i] != '\n')
	{
		line[i] = read_line[i];
		i++;
	}
	next_line = malloc(ft_strlen(read_line) * 1);
	while ((read_line[i]) && (read_line[i] != '\0'))
	{
		next_line[j] = read_line[i];
		i++;
		j++;
	}
	//printf("%d\n", count);
	printf("str %s\n", read_line);
	printf("\n%s\n", line);
	printf("\n%s\n", next_line);
}

int	main(void)
{
	int	g = open("aba.txt", O_RDONLY);
	get_next_line(g);
	printf("n %d\n", g);
	/* g = open("/nfs/homes/jabreu-d/jabreu-d/Get_Next_Line/aba.txt", O_RDONLY);
	get_next_line(g);
	printf("n %d\n", g); */
}