/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsokolog <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 17:59:09 by vsokolog          #+#    #+#             */
/*   Updated: 2018/08/29 17:59:10 by vsokolog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	init_storage(t_storage *strg)
{
	ft_memset(strg, 0, sizeof(t_storage));
	strg->buff.data = ft_strnew(0);
}

void	init_elems(t_adjelem **elems, size_t size)
{
	size_t	i;

	i = -1;
	while (++i <= size)
	{
		if (!(elems[i] = (t_adjelem *)malloc(sizeof(t_adjelem))))
			errors_memory(CANT_ALLOCATE_MEM, "init_elems");
		if (!(elems[i] = ft_memset(elems[i], 0, sizeof(t_adjelem))))
			errors_memory(CANT_SETZERO, "init_elems");
	}	
}

void	init_rooms(t_room **rooms, size_t size)
{
	size_t	i;

	i = -1;
	while (++i <= size)
	{
		if (!(rooms[i] = (t_room *)malloc(sizeof(t_room))))
			errors_memory(CANT_ALLOCATE_MEM, "init_rooms");
		if (!(rooms[i] = ft_memset(rooms[i], 0, sizeof(t_room))))
			errors_memory(CANT_SETZERO, "init_rooms");
	}
}

void	init_coord(t_coord **coord, size_t size)
{
	size_t	i;

	i = -1;
	while (++i <= size)
	{
		if (!(coord[i] = (t_coord *)malloc(sizeof(t_coord))))
			errors_memory(CANT_ALLOCATE_MEM, "init_coord");
		if (!(coord[i] = ft_memset(coord[i], 0, sizeof(t_coord))))
			errors_memory(CANT_SETZERO, "init_coord");
	}
}

void	init_hashtable(t_htab *htab, t_storage *strg)
{
	if (strg->info.amnt_of_rooms < 1)
		errors_rooms(NO_ROOMS);
	if (!(htab = ft_memset(htab, 0, sizeof(t_htab))))
		errors_memory(CANT_SETZERO, "init_htab");
	if (!(htab->rooms = (t_room **)malloc(sizeof(t_room *)
					* strg->info.amnt_of_rooms + 1)))
	{
		free(htab->rooms);
		errors_memory(CANT_ALLOCATE_MEM, "init_htab");
	}
	// if (!(htab->coords = (t_coord **)malloc(sizeof(t_coord *)
					// * strg->info.amnt_of_rooms + 1)))
	// {
		// free(htab->coords);
		// errors_memory(CANT_ALLOCATE_MEM, "init_htab");
	// }
	htab->size = strg->info.amnt_of_rooms;
	init_rooms(htab->rooms, htab->size);
	// init_coord(htab->coords, htab->size);
}

void	init_adjlists(t_adjlists *adjlsts, t_htab *htab)
{
	if (!(adjlsts = ft_memset(adjlsts, 0, sizeof(t_adjlists))))
	   errors_memory(CANT_SETZERO, "init_adjlists");
	adjlsts->size = htab->size;
    if (!(adjlsts->elems = (t_adjelem **)malloc(sizeof(t_adjelem *)
					* adjlsts->size + 1)))
         errors_memory(CANT_ALLOCATE_MEM, "init_adjlists");
	init_elems(adjlsts->elems, adjlsts->size);
}