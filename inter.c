#include <unistd.h>

int ft_strchr(char *str, char c)
{
	int i = 0;
	while(str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return 0;
}
int main(int argc, char *argv[])
{
char letters[1000] = {0};
	int i = 0;
	int c = 0;
	if (argc != 3)
		{
			write(1, "\n", 1);
			return 0;
		}
	while(argv[1][i])
	{
		if (!(ft_strchr(letters,argv[1][i])) && ft_strchr(argv[2], argv[1][i]))
			letters[c] = argv[1][i],write(1, &letters[c++], 1);
		i++;
	}
			write(1, "\n", 1);
	return 0;
}
