#
#

NOM=libmlx.a
SRC= mlx_shaders.c mlx_new_window.m mlx_init_loop.m mlx_new_image.m mlx_xpm.c mlx_int_str_to_wordtab.c
SRC+= mlx_png.c mlx_mouse.m
OBJ1=$(SRC:.c=.o)
OBJ=$(OBJ1:.m=.o)
CFLAGS+=-O2

# colors
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

# add to match string put with X11 in size and position
CFLAGS+= -DSTRINGPUTX11

%.o: %.c
	@gcc $(CFLAGS) -Wno-deprecated -o $@ -c $<
	@printf "$(ERASE)$(BLUE)> Compilation :$(END) $<"
%.o: %.m
	@gcc $(CFLAGS) -Wno-deprecated -o $@ -c $<
	@printf "$(ERASE)$(BLUE)> Compilation :$(END) $<"

all: $(NOM)

$(NOM):	$(OBJ)
	@ar rc $(NOM) $(OBJ)
	@ranlib $(NOM)
	@printf "$(ERASE)$(GREEN)[SUCCESS] $(NOM)$(END)\n"


clean:
	@rm -f $(NOM) $(OBJ) *~
	@rm -f mlx_app
	@printf "$(BLUE)> Deleted : $(RED)mlx .obj$(END)\n"
	@printf "$(BLUE)> Deleted : $(RED)libmlx.a$(END)\n"

re: clean all
