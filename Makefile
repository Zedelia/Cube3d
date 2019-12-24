
NAME = cube3d

NAME_TEST = tests

INCLUDES = cube3d

SRC_PATH = srcs

SRCS = main

TESTS =

INCLUDES_PATH = includes

INCLUDES := $(patsubst %,includes/%.h,${INCLUDES})
SRCS := $(patsubst %,srcs/%.c,${SRCS})
TESTS := $(patsubst %,srcs/%.c,${TESTS})

OBJ_PATH = .objects

OBJ := ${SRCS:.c=.o}
OBJ_TEST := ${SRCS:.c=.o} ${TESTS:.c=.o}

MAIN = main.c
MAIN_TEST = tests.c

LIBMINILIBX = lib/minilibx_opengl/libmlx.a
LBFTPRINTF = lib/libft/libftprintf.a

CC = gcc -g
CFLAGS = -Wall -Wextra -Werror -framework OpenGL -framework AppKit
DFLAGS = -fsanitize=address
IFLAG = -I ${INCLUDES}

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


all : libprintf libx ${NAME}
	@printf "$(BLUE)> $(NAME) : $(YELLOW)Project ready !$(END)\n"

${NAME}: $(LIBMINILIBX) $(LIBFTPRINTF) ${OBJ}
		@@$(CC) $(CFLAGS) $(LIBMINILIBX) $(LIBFTPRINTF) $(IFLAG) $^ -o $@
		@printf "\n$(ERASE)$(BLUE)> $@ : $(GREEN)Success !$(END)\n\n"

libprintf :
	@make -C lib/Printf

libx :
	@make -C lib/minilibx_opengl

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(SRC_PATH)/%.h $(LIBFTPRINTF) $(LIBMINILIBX)
	@mkdir -p $(OBJ_PATH) $(OBJ_PATH)/$(SRC_SUP)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<
	@printf "$(ERASE)$(BLUE)> Compilation :$(END) $<"

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