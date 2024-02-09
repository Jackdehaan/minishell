/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cd.c                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: rfinneru <rfinneru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/30 12:09:22 by rfinneru      #+#    #+#                 */
/*   Updated: 2024/02/09 12:24:00 by rfinneru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	cd(char *directory, char **env)
{
	char	buffer[1024];
	char	*path;
	int		i;

	if (!directory)
		return ;
	if (directory[0] != '/')
		directory = ft_strjoin("/", directory);
	getcwd(buffer, 1024);
	path = ft_strjoin(buffer, directory);
	if (chdir(path) == -1)
	{
		write(1, "cd: not a directory: ", 21);
		write(1, directory, ft_strlen(directory));
		write(1, "\n", 1);
	}
	i = 0;
	while (ft_strnstr(env[i], "PWD=", 4) == NULL)
		i++;
	// free(env[i]);
	env[i] = ft_strjoin("PWD=", path);
}

// int	main(void)
// {
// 	cd("directory_test");
// 	return (0);
// }