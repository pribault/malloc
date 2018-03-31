/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pribault <pribault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 00:17:08 by pribault          #+#    #+#             */
/*   Updated: 2018/03/31 00:54:33 by pribault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"
#include "libft.h"

int	main(void)
{
	void	*ptr;

	for (int i = 0; i < 1; i++)
	ptr = malloc(1);
	malloc_print_logs();
	return (0);
}
