#include "mini.h"

int	main(int argc, char *argv[])
{
	t_minishell	minishell;

	minishell.tokens_list = NULL;

	tokenizer("&& || | () < << > >>", &minishell);
	return (0);
}
