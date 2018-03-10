/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pribault <pribault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 23:02:19 by pribault          #+#    #+#             */
/*   Updated: 2018/03/08 23:07:40 by pribault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

void	malloc_error(int error, void *param)
{
	char		*debug;
	uint32_t	level;

	if ((debug = getenv("MALLOC_DEBUG")))
		level = ft_atou(debug);
	else
		level = 3;
	if (level & 1)
		ft_error(2, error, param);
	if (level & 2)
		abort();
}
