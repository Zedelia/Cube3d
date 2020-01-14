
NAME = cube3d

SRC_PATH = srcs
SRCS_NAME = img/img_load_xpm.c \
	img/img_display.c \
	camera/camera_init.c \
	camera/camera_printf.c \
	display/display_exit.c \
	display/display_tile.c \
	display/display_update.c \
	map/map_init.c \
	map/map_free.c \
	map/map_parser.c \
	map/map_printf.c \
	mlx/mlx_init.c \
	map/parsing/map_init_parsing.c \
	map/parsing/map_get_info.c \
	map/parsing/map_get_text.c \
	map/parsing/map_get_r.c \
	map/parsing/map_get_colors.c \
	map/parsing/map_get_map_line.c \
	map/parsing/map_tab_init.c \
	map/parsing/map_tab_fill.c \
	map/check/map_check_colors.c \
	map/check/map_check_infos.c \
	map/check/map_check_map.c \
	map/check/map_check_resolution.c \
	map/check/map_check_texture.c \
	move/move_apply.c \
	move/move_keydown.c \
	utils/colors.c \
	utils/angles.c \
	utils/utils_01.c \
	utils/utils_02.c \
	utils/return_func.c \
	rays/rays_printf.c \
	rays/rays_tab_init.c \
	rays/ray_casting.c \
	rays/ray_init.c \
	rays/ray_get_distance.c \
	rays/ray_get_intersections.c \
	rays/ray_get_steps.c \
	rays/ray_get_direction.c \
	rays/ray_get_walls_hit.c \
	rays/ray_rotate.c \
	display/display_rays.c



INC_PATH = includes
INC_FLAGS = -I ${INC_PATH}

MKDIR_LST = {img,map,mlx,rays,utils,render,camera,display,move}

INCLUDES = cube3d

LIBMINILIBX =  lib/minilibx_opengl/libmlx.a -framework OpenGL 	\
		-framework AppKit
LIBFTPRINTF = lib/Printf/libftprintf.a
LIBFT = lib/Printf/libft/libft.a

REBUILD_DEPENDENCIES = includes/cube3d.h lib/Printf/libftprintf.a lib/Printf/libft/libft.a

OBJ_PATH = .objects
OBJ_NAME := ${SRCS_NAME:.c=.o}
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

CC = gcc -g
CFLAGS = -Wall -Wextra -Werror
DFLAGS = -fsanitize=address
COMPIL = $(CC) $(DFLAGS) $(LIBFTPRINTF) $(LIBMINILIBX) $(LIBFT) $^ -o $@

# Colors
GREY = \x1b[30m
RED = \x1b[31m
GREEN = \x1b[32m
YELLOW = \x1b[33m
BLUE = \x1b[34m
PURPLE = \x1b[35m
CYAN = \x1b[36m
WHITE = \x1b[37m
END = \x1b[0m
ERASE = \033[2K\r
RESET = \033[0;37m

all : libprintf libx $(NAME)
	@printf "$(BLUE)> $(NAME) : $(YELLOW)Project ready !$(END)\n"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(REBUILD_DEPENDENCIES)
	@mkdir -p $(OBJ_PATH) $(OBJ_PATH)/$(MKDIR_LST) $(OBJ_PATH)/map/parsing $(OBJ_PATH)/map/check
	@$(CC) $(CFLAGS) $(INC_FLAGS) -o $@ -c $<
	@printf "$(ERASE)$(BLUE)> Compilation :$(END) $<"

${NAME}: $(OBJ)
	@$(COMPIL) tests/mains/main.c
	@printf "$(ERASE)$(BLUE)> $@ : $(GREEN)Success !$(END)\n\n"
	@rm -rf *.dSYM


# Tests
tmap: $(OBJ)
	@$(COMPIL) tests/mains/main-maps.c
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

clean:
	@rm -rf *.dSYM
	@make -C lib/Printf clean
	@printf "$(BLUE)> Deleted : $(RED)lib .obj$(END)\n"
	@rm -rf $(OBJ_PATH)
	@rm -rf tmap tmlx
	@printf "$(BLUE)> Deleted : $(RED)cube3d $(OBJ_PATH)$(END)\n"
	@printf "$(BLUE)> Deleted : $(RED)tests prog $(OBJ_PATH)$(END)\n"

fclean: clean
	@make -C lib/minilibx_opengl clean
	@make -C lib/Printf fclean
	@rm -rf $(NAME)
	@printf "$(BLUE)> Deleted : $(RED)$(NAME)$(END)\n"

re: fclean all

.PHONY: all, clean, fclean, re, tmap, tmlx