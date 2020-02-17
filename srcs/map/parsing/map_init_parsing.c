/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init_parsing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbos <mbos@student.le-101.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 14:19:56 by mbos              #+#    #+#             */
/*   Updated: 2020/02/17 14:19:57 by mbos             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cube3d.h"

void	init_map_parser_fct_tab(void)
{
	g_map_parser_fct[_r] = map_parse_r;
	g_map_parser_fct[_no] = map_parse_no;
	g_map_parser_fct[_so] = map_parse_so;
	g_map_parser_fct[_we] = map_parse_we;
	g_map_parser_fct[_ea] = map_parse_ea;
	g_map_parser_fct[_sp] = map_parse_sp;
	g_map_parser_fct[_floor] = map_parse_floor;
	g_map_parser_fct[_cell] = map_parse_cell;
}
