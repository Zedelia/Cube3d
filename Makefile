
##					##
##	 VARIABLES		##
##					##

NAME = Cub3D

SRC_PATH = srcs

SRCS_NAME = img/img_load_xpm.c \
	img/img_print.c \
	camera/camera_init.c \
	camera/camera_get_pos.c \
	camera/camera_get_rotation_angle.c \
	display/display_exit.c \
	display/display_mini_map.c \
	display/display_update.c \
	display/display_rays.c \
	display/display_walls.c \
	display/display_walls_text.c \
	display/display_floor_sky.c \
	display/display_sprite.c \
	display/display_colored_walls.c \
	display/display_sprite.c \
	display/display_bonus.c \
	map/map_init.c \
	map/map_free.c \
	map/map_parser.c \
	mlx/mlx_init.c \
	mlx/mlx_free.c \
	map/parsing/map_init_parsing.c \
	map/parsing/map_get_bonus.c \
	map/parsing/map_get_text.c \
	map/parsing/map_get_r.c \
	map/parsing/map_get_colors.c \
	map/parsing/map_get_map_line.c \
	map/parsing/map_tab_init.c \
	map/parsing/map_tabs_fill.c \
	map/check/map_check_others.c \
	map/check/map_check_colors.c \
	map/check/map_check_infos.c \
	map/check/map_check_map.c \
	map/check/map_check_resolution.c \
	map/check/map_check_texture.c \
	map/map_textures_init.c \
	move/move_apply.c \
	move/move_keydown.c \
	utils/colors.c \
	utils/angles.c \
	utils/utils_miscellaneous.c \
	utils/return_func.c \
	utils/math_dist.c \
	utils/pixel.c \
	utils/vectors.c \
	utils/print_map_infos.c \
	rays/rays_tab_init.c \
	rays/ray_casting.c \
	rays/ray_init.c \
	rays/ray_get_intersections.c \
	rays/ray_get_steps.c \
	rays/ray_get_direction.c \
	rays/ray_get_walls_hit.c \
	rays/ray_rotate.c \
	rays/ray_wall_detection.c \
	rays/ray_get_distance.c \
	sprites/sprites_init.c \
	sprites/sprite_sort_tab.c \
	sprites/sprite_draw.c \


MKDIR_LST = {img,map,mlx,rays,utils,render,camera,display,move,sprites}

INCLUDES = cube3d
INC_PATH = includes

OBJ_PATH = .objects
OBJ_NAME := ${SRCS_NAME:.c=.o}
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

##					##
##	 LIBRAIRIES		##
##					##

LIBMINILIBX =  lib/minilibx_opengl/libmlx.a -framework OpenGL 	\
		-framework AppKit
LIBFTPRINTF = lib/Printf/libftprintf.a
LIBFT = lib/Printf/libft/libft.a

##					##
##		COLORS		##
##					##

GREY = \x1b[30m
RED = \x1b[31m
GREEN = \x1b[32m
YELLOW = \x1b[33m
BLUE = \x1b[34m
PURPLE = \x1b[35m
CYAN = \x1b[36m
WHITE = \x1b[37m
RESET = \033[0;37m
ORANGE = \033[38;5;214m
PINK = \033[38;5;197m
END = \x1b[0m
ERASE = \033[2K\r


##					##
##		FONTS		##
##					##

END			=	\033[0m
BOLD		=	\033[1m
R_BOLD		=	\033[21m
BLINK		=	\033[5m
R_BLINK		=	\033[25m
UNDERLINE	=	\033[4m
R_UNDERLINE	=	\033[24m


##					##
## COMPIL SHORTCUT	##
##					##

CC = gcc -g3
CFLAGS = -Wall -Wextra -Werror
DFLAGS = -fsanitize=address

INC_FLAGS = -I ${INC_PATH}
REBUILD_DEPENDENCIES = includes/*.h

COMPIL = $(CC) $(CFLAGS) $(LIBFTPRINTF) $(LIBMINILIBX) $(LIBFT) $(INC_FLAGS) $^ -o $@

##					##
##		RULES		##
##					##

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(REBUILD_DEPENDENCIES)
	@$(CC) $(CFLAGS) $(INC_FLAGS) -o $@ -c $<
	@printf "$(ERASE)$(BLUE)> Compilation :$(END) $<"


all : makedir libprintf libx $(NAME)
	@printf "\n$(BLUE)> $(NAME) : $(YELLOW)Project ready !$(END)\n"

bonus : all
	@printf "$(BLUE)> $(NAME) : $(YELLOW)Bonus ready !$(END)\n\n"
	@printf "$(CYAN)> Use $(YELLOW) L ./path_to_life_bar !$(END)\n"
	@printf "$(CYAN)> Use $(YELLOW) L ./path_to_screen_frame !$(END)\n\n"

makedir:
	@mkdir -p $(OBJ_PATH) $(OBJ_PATH)/$(MKDIR_LST) $(OBJ_PATH)/map/parsing $(OBJ_PATH)/map/check


${NAME}: $(OBJ)
	@$(COMPIL) main.c
	@printf "$(ERASE)$(BLUE)> Compilation :$(END) $<"
	@printf "$(ERASE)$(BLUE)> $@ : $(GREEN) SUCCESS !$(END)\n\n"
	@printf "\n\n$(YELLOW)| ->		$(NAME):" "$(RESET)|\033[42m     $(BOLD)L O A D I N G$(R_BOLD)     $(RESET)|\n\n" #| pv -qL 15
	@rm -rf *.dSYM
	@echo "\n$(BOLD)$(GREEN)	   _____________________________"
	@echo "	|>                               <|"
	@echo "	|>	   ┌─┐ ┬ ┬┌─┐┌─┐         <|"
	@echo "	|>	   │   │ ││-|├-	         <|"
	@echo "	|>	   └─┘ └─┘┴─┘└─┘ _3D     <|"
	@echo "	|>                               <|"
	@echo "	   __________________$(BLINK)$(ORANGE)is ready$(R_BLINK)$(GREEN)____$(RESET)\n\n"


# 	Tests 	#

tmap: $(OBJ)
	@$(COMPIL) tests/mains/main-maps.c
	@printf "$(ERASE)$(BLUE)> Compilation :$(END) $<"
	@printf "$(ERASE)$(BLUE)> $@ : $(GREEN) SUCCESS !$(END)\n\n"
	@rm -rf *.dSYM

tmlx: $(OBJ)
	@$(COMPIL) tests/mains/main-mlx.c
	@printf "$(ERASE)$(BLUE)> $@ : $(GREEN) SUCCESS !$(END)\n\n"
	@rm -rf *.dSYM



libprintf :
	@make -C lib/Printf

libx :
	@make -C lib/minilibx_opengl

# 	clean 	#

clean:
	@rm -rf *.dSYM
	@make -C lib/Printf clean
	@rm -rf $(OBJ_PATH)
	@rm -rf tmap tmlx
	@printf "$(BLUE)> Deleted : $(RED)cube3d $(OBJ_PATH)$(END)\n"
	@printf "$(BLUE)> Deleted : $(RED)tests prog $(OBJ_PATH)$(END)\n"

fclean: clean
	@make -C lib/minilibx_opengl clean
	@make -C lib/Printf fclean
	@rm -rf $(NAME)
	@printf "$(BLUE)> Deleted : $(RED)$(NAME)$(END)\n"
	@echo "$(YELLOW)| ->		FCLEAN: DONE\n$(RESET)"

re: fclean all

.PHONY: all, clean, fclean, re, tmap, tmlx
