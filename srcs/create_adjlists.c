// #include "lem_in.h"
//
// static char		**get_rooms(char *data)
// {
// 	return (ft_strsplit(data, '-'));
// }
//
// static void		add_room(t_rooms *room, t_rooms *new_room)
// {
// 	if (!room || !new_room)
// 		return ;
// 	while (room->next_room != NULL)
// 		room = room->next_room;
// 	room->next_room = new_room;
// 	new_room->next_room = NULL;
// }
//
// static t_rooms	*new_room(const t_rooms *room)
// {
// 	t_rooms	*new_room;
//
// 	if ((new_room = (t_rooms *)malloc(sizeof(t_rooms))) == NULL)
// 		return (NULL);
// 	new_room->name = ft_strdup(room->name);
// 	new_room->name_len = room->name_len;
// 	new_room->id = room->id;
// 	new_room->visited = room->visited;
// 	new_room->start = room->start;
// 	new_room->end = room->end;
// 	new_room->next_room = NULL;
// 	return (new_room);
// }
//
// static void		make_links(t_adj_lists *adj_lists, char **rooms)
// {
// 	int	id_first;
// 	int	id_second;
//
// 	id_first = get_id(adj_lists, rooms[FIRST], ft_strlen(rooms[FIRST]));
// 	id_second = get_id(adj_lists, rooms[SECOND], ft_strlen(rooms[SECOND]));
// 	// if (room_exists(adj_lists, id_first, rooms[FIRST])
// 	// && room_exists(adj_lists, id_second, rooms[SECOND]))
// 	// {
// 	// 	// if (!adj_lists->rooms[id_second])
// 	// 		add_room(adj_lists->rooms[id_first],
// 	// 									new_room(adj_lists->rooms[id_second]));
// 	// 	// if (!adj_lists->rooms[id_first])
// 	// 		add_room(adj_lists->rooms[id_second],
// 	// 								new_room(adj_lists->rooms[id_first]));
// 	// }
// 	if (room_exists(adj_lists, id_first, rooms[FIRST]))
// 	{
// 		if (room_exists(adj_lists, id_first, rooms[SECOND]))
// 		{
// 			add_room(adj_lists->rooms[id_first],
// 										adj_lists->rooms[id_first]);
// 			add_room(adj_lists->rooms[id_second],
// 										adj_lists->rooms[id_second]);
// 		}
// 		else
// 		{
// 			add_room(adj_lists->rooms[id_first],
// 										new_room(adj_lists->rooms[id_second]));
// 			add_room(adj_lists->rooms[id_second],
// 										adj_lists->rooms[id_first]);
// 		}
// 	}
// 	else
// 	{
// 		if (room_exists(adj_lists, id_second, rooms[SECOND]))
// 		{
// 			add_room(adj_lists->rooms[id_second],
// 										new_room(adj_lists->rooms[id_first]));
// 			add_room(adj_lists->rooms[id_first],
// 										adj_lists->rooms[id_second]);
// 		}
// 		else
// 		{
// 			add_room(new_room(adj_lists->rooms[id_first]),
// 										new_room(adj_lists->rooms[id_second]));
// 			add_room(adj_lists->rooms[id_second],
// 										adj_lists->rooms[id_first]);
// 		}
// 	}
// }
//
// void			create_links(t_map *map, t_adj_lists *adj_lists)
// {
// 	while (TRUE)
// 	{
// 		if (!is_comment(buff->line))
// 		{
// 			if (is_link(buff->line))
// 				make_links(adj_lists, info->room = get_rooms(map->buffer.data));
// 			else // Use break and try to create path or just ignore this line
// 				errors_rooms(UNKNOWN_ROOM);
//			free_room(info->room);
//			free(info->room);
// 		}
// 		if (!read_line(storage, &buff->line))
// 			break ;
// 	}
// }