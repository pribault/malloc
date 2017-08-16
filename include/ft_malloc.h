/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pribault <pribault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 09:58:00 by pribault          #+#    #+#             */
/*   Updated: 2017/07/22 18:00:51 by pribault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MALLOC_H
# define FT_MALLOC_H

# include <stdlib.h>

void			*ft_malloc(size_t size);
void			*calloc(size_t nmemb, size_t size);
void			*ft_realloc(void *ptr, size_t size);
void			ft_free(void *ptr);

void			ft_show_alloc_mem(void);
void			ft_show_alloc_mem_ex(void);

#endif
