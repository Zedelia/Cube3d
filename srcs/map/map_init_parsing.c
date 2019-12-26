/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map_init_parsing.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/26 16:09:05 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/12/26 17:45:42 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

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
	g_map_parser_fct[_map] = map_parse_map;
}