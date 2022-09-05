NAME          := miniRT

CC            := cc
CFLAGS        := -Wall -Wextra -Werror
CPPFLAGS      := -I . -I include -I libft -I libmlx
LDFLAGS       :=                 -L libft -L libmlx
LDLIBS        :=                 -l ft    -l mlx

SRCS_PATH     := src
OBJS_PATH     := obj
SRCS          := main.c
SRCS          := $(SRCS:%=$(SRCS_PATH)/%)
OBJS          := $(SRCS:$(SRCS_PATH)/%.c=$(OBJS_PATH)/%.o)

RM            := rm -f
MAKE          := make -C
MUTE          := 1>/dev/null

all:        $(NAME)

$(OBJS_PATH)/%.o: $(SRCS_PATH)/%.c
	-[ ! -d $(@D) ] && mkdir -p $(@D)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
	echo "CREATED $@"

libft/libft.a:
	$(MAKE) libft $(MUTE)
	echo "CREATED libft"

libmlx/libmlx.a:
	$(MAKE) libmlx $(MUTE)
	echo "CREATED libmlx"

$(NAME): $(OBJS) libmlx/libmlx.a libft/libft.a
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(OBJS) $(LDLIBS) -o $(NAME)
	echo "CREATED $(NAME)"

clean:
	$(RM) $(OBJS)
	$(MAKE) libft clean $(MUTE)
	$(MAKE) libmlx clean $(MUTE)

fclean: clean
	$(RM) $(NAME) $(LIBFT) $(MLX)

re: fclean all

info:
	make --dry-run --always-make --no-print-directory | grep -v "echo \| mkdir"

.SILENT:
.PHONY:    all clean fclean re bonus