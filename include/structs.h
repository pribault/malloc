/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pribault <pribault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 13:04:57 by pribault          #+#    #+#             */
/*   Updated: 2017/07/22 10:47:04 by pribault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# define TINY		32
# define SMALL		128
# define ALLOCS		128

# define LINE_FEED	16

typedef struct		s_alloc
{
	void			*ptr;
	size_t			size;
	struct s_alloc	*next;
}					t_alloc;

typedef struct		s_zone
{
	void			*ptr;
	size_t			size;
	t_alloc			*allocs;
	struct s_zone	*next;
}					t_zone;

typedef struct		s_env
{
	t_zone			*tiny;
	t_zone			*small;
	t_alloc			*large;
}					t_env;

extern t_env		g_env;

#endif
