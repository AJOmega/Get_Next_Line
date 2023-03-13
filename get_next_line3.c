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
	char		*read_line;
	static char	*next_line = "";
	int			rd_bytes;
	int			i;
	int			j;

	i = 0;
	j = 0;
	rd_bytes = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return ("-1");
	read_line = malloc((BUFFER_SIZE + 1) * sizeof(char));
	//while(read(fd, &next_line[i], 1) == 1)
	while (!ft_strchr(next_line, '\n') && rd_bytes != 0)
	{
		rd_bytes = read(fd, read_line, BUFFER_SIZE);
		printf("\nrd_bytes: %d\n", rd_bytes);
		printf("\nread_line: %s\n", read_line);
		if (rd_bytes == -1)
		{
			free(read_line);
			return (NULL);
		}
		read_line[rd_bytes] = '\0';
		next_line = ft_strjoin(next_line, read_line);
		printf("\nnext_line: %s\n", next_line);
	}
	//count = read(fd, read_line, BUFFER_SIZE);
	//printf("%s\n", read_line);
	while (read_line[i] != '\n' && read_line[i])
	{
		line[i] = read_line[i];
		printf("full line: %s\n", line);
		printf("line character: %d\n", line[i]);
		//printf("%d\n", i);
		i++;
	}
	//printf("%s\n", line);
	//printf("%ld\n", ft_strlen(read_line));
	next_line = malloc(ft_strlen(read_line) + 1);
	i = 0;
	//printf("%ld\n", sizeof(read_line));
	//printf("%ld\n", sizeof(next_line));
	while ((read_line[i]) && (read_line[i] != '\n'))
	{
		printf("%d\n", i);
		next_line[j] = read_line[i];
		i++;
		j++;
	}
	//printf("%d\n", count);
	printf("read_line: %s\n", read_line);
	printf("\nline: %s\n", line);
	printf("\nnext_line: %s\n", next_line);
}

int	main(void)
{
	int	g = open("pacha.txt", O_RDONLY);
	get_next_line(g);
	printf("n %d\n", g);

	g = open("pacha.txt", O_RDONLY);
	get_next_line(g);
	printf("n %d\n", g);

	g = open("cha.txt", O_RDONLY);
	get_next_line(g);
	printf("n %d\n", g);
}