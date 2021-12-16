#include "get_next_line.h"

char *ft_strdup(char *str)
{
	char *line;
	int i = 0;
	while(str[i])
		i++;
	line = malloc(i + 1);
	i = 0;
	while (str[i])
	{
		line[i] = str[i];
		i++;
	}
	line[i] = 0;
	return (line);
}
