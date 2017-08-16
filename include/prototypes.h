/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pribault <pribault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 14:34:59 by pribault          #+#    #+#             */
/*   Updated: 2017/07/22 18:01:19 by pribault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H
# define PROTOTYPES_H

# include "ft_printf.h"
# include "structs.h"
# include <sys/mman.h>
# include <pthread.h>

t_zone			*alloc_zone(size_t size);
void			*alloc_in_zone(t_zone *zone, size_t size);
void			*alloc_large(size_t size);

char			search_and_free(t_alloc **head, void *ptr, char state);

size_t			show_zone(t_zone *zone);
size_t			show_allocs(t_alloc *alloc);

void			sort_zones(t_zone **head);
void			sort_allocs(t_alloc **head);

void			*malloc_error(int error);

#endif
