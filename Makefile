
NAME	= miniRT

CC            := cc
CFLAGS        := -Wall -Wextra -Werror -g3 
INC			=	-I includes -I libft -I libmlx 
LFLAGS		=	-I./libft -lft -L./libft -I./libmlx -L./libmlx -I./miniRT -L./miniRT

LIBFT		=	./libft/libft.a

MLX			=	./libmlx/libmlx_Linux.a
SRCS_PATH     := src
OBJS_PATH     := obj
SRCS          := main.c \
					mlx.c \
					utils.c \
					destroy.c \
					/parsing/check_filename.c \
					/parsing/get_scene.c \
					/parsing/get_camera.c \
					/parsing/get_light.c \
					/parsing/get_ambient_light.c \
					/parsing/get_objects_list.c \
					/parsing/create_sphere.c \
					/parsing/create_plane.c \
					/parsing/create_cylinder.c \
					/parsing/parse_position.c \
					/parsing/parse_direction.c \
					/parsing/check_float.c \
					/parsing/check_valid_color_range.c \
					/utils/jump_spaces.c \
					/utils/jump_data.c \
					/utils/is_space.c \
					/utils/print_world.c \
					init_view.c
					
				
SRCS          := $(SRCS:%=$(SRCS_PATH)/%)
OBJS          := $(SRCS:$(SRCS_PATH)/%.c=$(OBJS_PATH)/%.o)

RM            := rm -f
MAKE          := make -C

all:        $(NAME)

$(OBJS_PATH)/%.o: $(SRCS_PATH)/%.c
	-[ ! -d $(@D) ] && mkdir -p $(@D)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
	echo "CREATED $@"

$(LIBFT):
	$(MAKE) $(@D) $(@F) $(LFLAGS)
	echo "CREATED libft"

$(MLX):
	$(MAKE) $(@D) $(@F) $(LFLAGS)
	echo "CREATED libmlx"

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(LFLAGS) $(OBJS) -o $(NAME) -lm
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