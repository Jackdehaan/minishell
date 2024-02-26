/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   echo.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jade-haa <jade-haa@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/01 11:40:21 by rfinneru      #+#    #+#                 */
/*   Updated: 2024/02/26 11:02:14 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	echo(t_env_ll *env, char **arg)
{
	t_env_ll	*node;
	int			i;
	int			x;
	char		*key;
	int			j;

	node = NULL;
	key = NULL;
	i = 0;
	x = 0;
	j = 0;
	if (!arg || !arg[0])
	{
		write(STDOUT_FILENO, "\n", 1);
		return ;
	}
	if (!ft_strncmp(arg[0], "-n", 2))
		j++;
	while (arg[j])
	{
		if (ft_strchr(arg[j], '$'))
		{
			i = 0;
			while (arg[j][i])
			{
				if (arg[j][i] == '$')
				{
					x = i + 1;
					while (arg[j][i] && arg[j][i] != ' ')
						i++;
					key = ft_strndup(arg[j] + x, i - x);
					node = find_key(env, key);
					if (node)
						write(STDOUT_FILENO, node->value,
							ft_strlen(node->value));
					free(key);
					break ;
				}
				i++;
			}
		}
		else
		{
			write(STDOUT_FILENO, arg[j], ft_strlen(arg[j]));
			if (arg[j + 1])
				write(1, " ", 1);
		}
		++j;
	}
	if (arg[0] && ft_strncmp(arg[0], "-n", 2))
		write(STDOUT_FILENO, "\n", 1);
}

// void	echo(t_env_ll *env, char **arg)
// {
// 	t_env_ll	*node;
// 	int			i;
// 	int			x;
// 	char		*key;

// 	node = NULL;
// 	i = 0;
// 	x = 0;
// 	if (ft_strchr(msg, '$'))
// 	{
// 		while (msg[i])
// 		{
// 			if (msg[i] == '$')
// 			{
// 				x = i + 1;
// 				while (msg[i] && msg[i] != ' ')
// 					i++;
// 				key = ft_strndup(msg + x, i - x);
// 				break ;
// 			}
// 			i++;
// 		}
// 	}
// 	i = 0;
// 	x = 0;
// 	while (msg[i])
// 	{
// 		if (msg[i] != '$')
// 			printf("%c", msg[i]);
// 		else if (msg[i] == '$' && msg[i + 1] && !ft_isalnum(msg[i + 1]))
// 			printf("%c", msg[i]);
// 		else
// 		{
// 			i += ft_strlen(key);
// 			node = find_key(env, key);
// 			if (node && node->value)
// 				printf("%s", node->value);
// 		}
// 		i++;
// 	}
// 	if (!n)
// 		printf("\n");
// }