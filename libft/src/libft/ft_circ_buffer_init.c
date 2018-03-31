/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_circ_buffer_init.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pribault <pribault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 19:37:34 by pribault          #+#    #+#             */
/*   Updated: 2018/03/31 00:35:40 by pribault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_circ_buffer_init(t_circ_buffer *buffer, t_alloc_type alloc,
		uint64_t type_size, uint64_t n_elements)
{
	buffer->write_idx = 0;
	buffer->read_idx = 0;
	buffer->type = type_size;
	buffer->elems = n_elements + 1;
	buffer->n = 0;
	buffer->trash_callback = NULL;
	buffer->data = NULL;
	buffer->alloc = alloc;
	if (alloc == ALLOC_MALLOC)
	{
		if (!(buffer->ptr = malloc(type_size * n_elements)))
			ft_error(2, ERROR_ALLOCATION, NULL);
	}
	else if (alloc == ALLOC_MMAP)
	{
		if (!(buffer->ptr = mmap(NULL, type_size * n_elements,
			PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANON, -1, 0)))
			ft_error(2, ERROR_ALLOCATION, NULL);
	}
}
