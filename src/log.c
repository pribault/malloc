/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pribault <pribault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 23:54:51 by pribault          #+#    #+#             */
/*   Updated: 2018/03/31 00:55:07 by pribault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

static void	log_trashed(void *data, void *trashed)
{
	(void)data;
	free(trashed);
	ft_printf("trash\n");
}

void	malloc_log(t_log_type type, uint64_t value)
{
	static t_bool	init = FT_FALSE;
	t_log			log;
	char			*env;

	if (init == FT_FALSE)
	{
		if ((env = getenv("MALLOC_LOG_SIZE")))
			ft_circ_buffer_init(&g_env.log, ALLOC_MMAP, sizeof(t_log),
			ft_atou(env));
		else
			ft_circ_buffer_init(&g_env.log, ALLOC_MMAP, sizeof(t_log),
			MALLOC_LOG_SIZE);
		ft_circ_buffer_set_trash_callback(&g_env.log, &log_trashed, NULL);
		init = FT_TRUE;
	}
	log.type = type;
	log.value = value;
	ft_circ_buffer_enqueue(&g_env.log, &log);
}

void	malloc_print_logs(void)
{
	t_log	*log;

	while ((log = ft_circ_buffer_dequeue(&g_env.log)))
	{
		if (log->type == LOG_MMAP)
			ft_printf("page maped of size %lu\n", log->value);
		else if (log->type == LOG_MALLOC_REQUEST)
			ft_printf("malloc request of size %lu\n", log->value);
		else
			ft_printf("unknown log\n");
	}
}
