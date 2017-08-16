/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pribault <pribault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 09:58:06 by pribault          #+#    #+#             */
/*   Updated: 2017/07/22 17:40:49 by pribault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"
#include "structs.h"
#include "prototypes.h"

t_env	g_env = {NULL, NULL, NULL};

void	*ft_malloc(size_t size)
{
	if (!g_env.tiny)
		g_env.tiny = alloc_zone(((TINY * ALLOCS) % getpagesize() == 0)
		? TINY * ALLOCS : ((TINY * ALLOCS) / getpagesize()) * getpagesize()
		+ getpagesize());
	if (!g_env.small)
		g_env.small = alloc_zone(((SMALL * ALLOCS) % getpagesize() == 0)
		? SMALL * ALLOCS : ((SMALL * ALLOCS) / getpagesize()) * getpagesize()
		+ getpagesize());
	if (size <= TINY)
		return (alloc_in_zone(g_env.tiny, size));
	else if (size <= SMALL)
		return (alloc_in_zone(g_env.small, size));
	else
		return (alloc_large(size));
}

void	*ft_realloc(void *ptr, size_t size)
{
	ft_free(ptr);
	return (ft_malloc(size));
}

void	ft_show_alloc_mem()
{
	t_zone	*zone;
	size_t	size;

	size = 0;
	sort_zones(&g_env.tiny);
	sort_zones(&g_env.small);
	sort_allocs(&g_env.large);
	ft_printf("\033[38;5;214mTINY\033[0m : %p\n", g_env.tiny);
	zone = g_env.tiny;
	while (zone)
	{
		size += show_zone(zone);
		zone = zone->next;
	}
	ft_printf("\033[38;5;214mSMALL\033[0m : %p\n", g_env.small);
	zone = g_env.small;
	while (zone)
	{
		size +=show_zone(zone);
		zone = zone->next;
	}
	ft_printf("\033[38;5;214mLARGE\033[0m : %p\n", g_env.large);
	size += show_allocs(g_env.large);
	ft_printf("\033[38;5;166mTotal\033[0m : %u octects\n", size);
}

void	*calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	ptr = ft_malloc(nmemb * size);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}
