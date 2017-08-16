/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pribault <pribault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 10:46:23 by pribault          #+#    #+#             */
/*   Updated: 2017/07/22 17:29:04 by pribault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"
#include "structs.h"
#include "prototypes.h"

void	*malloc_error(int error)
{
	char	*env;

	env = getenv("MALLOC_DEBUG");
	if (!env)
		return (NULL);
	if (!ft_strcmp(env, "1") || !ft_strcmp(env, "3"))
	{
		ft_putstr_fd("\033[38;5;124m", 2);
		if (error == 1)
			ft_putendl_fd("malloc error: cannot allocate memory", 2);
		else if (error == 2)
			ft_putendl_fd("malloc error: invalid free", 2);
		ft_putstr_fd("\033[0m", 2);
	}
	if (!ft_strcmp(env, "2") || !ft_strcmp(env, "3"))
		abort();
	return (NULL);
}
