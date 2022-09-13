NAME          := miniRT

CC            := cc
CFLAGS        := -Wall -Wextra -Werror -g3
CPPFLAGS      := -I . -I include -I libft -I libmlx
LDFLAGS       :=                 -L libft -L libmlx
LDLIBS        :=                 -l ft    -l mlx

SRCS_PATH     := src
OBJS_PATH     := obj
SRCS          := main.c \
					init.c \
					mlx.c \
					utils.c \
					destroy.c \
					check_filename.c \
					get_scene.c \
					get_light.c \
					get_ambient_light.c
				
SRCS          := $(SRCS:%=$(SRCS_PATH)/%)
OBJS          := $(SRCS:$(SRCS_PATH)/%.c=$(OBJS_PATH)/%.o)

RM            := rm -f
MAKE          := make -C

all:        $(NAME)

$(OBJS_PATH)/%.o: $(SRCS_PATH)/%.c
	-[ ! -d $(@D) ] && mkdir -p $(@D)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
	echo "CREATED $@"

libft/libft.a:
	$(MAKE) libft
	echo "CREATED libft"

libmlx/libmlx.a:
	$(MAKE) libmlx
	echo "CREATED libmlx"

$(NAME): $(OBJS) libmlx/libmlx.a libft/libft.a
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) -MD $(OBJS) $(LDLIBS) -o $(NAME)
	echo "CREATED $(NAME)"

clean:
	$(RM) $(OBJS)
	$(MAKE) libft clean
	$(MAKE) libmlx clean

fclean: clean
	$(RM) $(NAME) $(LIBFT) $(MLX)

re: fclean all

info:
	make --dry-run --always-make --no-print-directory | grep -v "echo \| mkdir"

# .SILENT:
.PHONY:    all clean fclean re bonus