/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pribault <pribault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 09:37:43 by pribault          #+#    #+#             */
/*   Updated: 2018/03/10 10:11:25 by pribault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

t_zone	*create_zone(size_t size, char *name)
{
	t_alloc	alloc;
	t_zone	*zone;

	size = ((size + sizeof(t_zone) - 1) / getpagesize()) * getpagesize() +
	getpagesize();
	if (!(zone = mmap(NULL, size, PROT_READ | PROT_WRITE,
		MAP_PRIVATE | MAP_ANON, -1, 0)))
	{
		malloc_error(ERROR_MMAP, NULL);
		return (NULL);
	}
	zone->size = size - sizeof(t_zone);
	zone->next = NULL;
	zone->name = name;
	alloc.size = zone->size;
	alloc.type = TYPE_FREE;
	ft_memcpy(&zone[1], &alloc, sizeof(t_alloc));
	return (zone);
}

void	*get_allocation(t_zone *zone, size_t size)
{
	t_alloc	*alloc;

	if (!zone)
		return (NULL);
	alloc = (void*)&zone[1];
	while (alloc)
	{
		if (alloc->type == TYPE_FREE && size < alloc->size)
		{
			claim_allocation(alloc, size);
			return (&alloc[1]);
		}
		alloc = get_in_zone(zone, (void*)&alloc[1] + alloc->size, size);
	}
	return (NULL);
}

void	*allocate_in_zone(t_zone *zone, size_t size)
{
	t_zone	*prev;
	void	*ptr;

	prev = NULL;
	while (zone)
	{
		if ((ptr = get_allocation(zone, size)))
			return (ptr);
		prev = zone;
		zone = zone->next;
	}
	if (!prev || !(prev->next = create_zone(prev->size, prev->name)))
		return (NULL);
	if ((ptr = get_allocation(prev->next, size)))
		return (ptr);
	return (NULL);
}