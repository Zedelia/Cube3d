
NAME = cube3d

SRC_PATH = srcs
SRCS_NAME = main.c \
	img/img_load_xpm.c \
	img/img_display.c \
	display/display_exit.c \
	mlx/mlx_init.c \
	utils/maths.c \
	rays/rays_init.c


INC_PATH = includes
INC_FLAGS = -I ${INC_PATH}

MKDIR_LST	= {img,map,maths,mlx,rays,utils,display}

INCLUDES = cube3d

LIBMINILIBX =  lib/minilibx_opengl/libmlx.a -framework OpenGL 	\
		-framework AppKit
LBFTPRINTF = lib/Printf/libftprintf.a
LBFT = lib/Printf/libft/libft.a

REBUILD_DEPENDENCIES = includes/cube3d.h lib/Printf/libftprintf.a lib/Printf/libft/libft.a


OBJ_PATH = .objects
OBJ_NAME := ${SRCS_NAME:.c=.o}
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

CC = gcc -g
CFLAGS = -Wall -Wextra -Werror
DFLAGS = -fsanitize=address


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


all : libprintf libx $(NAME)
	@printf "$(BLUE)> $(NAME) : $(YELLOW)Project ready !$(END)\n"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(REBUILD_DEPENDENCIES)
	@mkdir -p $(OBJ_PATH) $(OBJ_PATH)/$(MKDIR_LST)
	@$(CC) $(CFLAGS) $(INC_FLAGS) -o $@ -c $<
	@printf "$(ERASE)$(BLUE)> Compilation :$(END) $<"

${NAME}: $(OBJ)
	@$(CC) $(CFLAGS) $(LIBFT) $(LIBMINILIBX) $(LBFTPRINTF) $^ -o $@
	@printf "$(ERASE)$(BLUE)\n> $@ : $(GREEN)Success !$(END)\n"


libprintf :
	@make -C lib/Printf

libx :
	@make -C lib/minilibx_opengl

clean:
	@make -C lib/Printf clean
	@printf "$(BLUE)> Deleted : $(RED)lib .obj$(END)\n"
	@make -C lib/minilibx_opengl clean
	@rm -rf $(OBJ_PATH)
	@printf "$(BLUE)> Deleted : $(RED)cube3d $(OBJ_PATH)$(END)\n"

fclean: clean
	@make -C lib/Printf fclean
	@rm -rf $(NAME)
	@printf "$(BLUE)> Deleted : $(RED)$(NAME)$(END)\n"

re: fclean all

.PHONY: all, clean, fclean, re