#include "../headers/mini.h"


int	main(void)
{
	char	cmd[] = "( 25 + ( 20 - 30 ) )";
	char	**tokens = ft_split(cmd, ' ');

	printf("%s", tokens[1]);
	return (0);
}