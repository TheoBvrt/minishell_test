#ifndef MINI_H
# define MINI_H

# include "../libft/libft.h"
# include "stdio.h"
# include "unistd.h"
# include "stdlib.h"
# include "fcntl.h"

#ifndef ARGS_TYPE
# define AND 0
# define OR 1
# define PIPE 2
# define OPEN_BRACKET 3
# define CLOSE_BRACKET 4
# define STRING 5
# define REDIR_IN 6
# define REDIR_OUT 7
# define HERE_DOC 8
# define APPEND 9
#endif

typedef struct s_token
{
	char	*token;
	int		type;
}	t_token;

#endif