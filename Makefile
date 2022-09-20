
NAME	= miniRT

CC            := cc
CFLAGS        := -Wall -Wextra -Werror -g3 
INC			=	-I include -I libft -I libmlx 
LFLAGS		=	-I./libft -lft -L./libft -I./libmlx -L./libmlx -I./miniRT -L./miniRT

LIBFT		=	./libft/libft.a

MLX			=	./libmlx/libmlx_Linux.a
SRCS_PATH     	:= src
OBJS_PATH     	:= obj
DEP_PATH		:= dep
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
					
				
DEP           := $(SRCS:$(SRCS_PATH)/%.c=$(OBJS_PATH)/%.d)
SRCS          := $(SRCS:%=$(SRCS_PATH)/%)
OBJS          := $(SRCS:$(SRCS_PATH)/%.c=$(OBJS_PATH)/%.o)


RM            := rm -f
MAKE          := make -C

all:        $(NAME)

$(DEP_PATH)/%.d: $(SRCS_PATH)/%.c
	@ mkdir -p $(@D)
	$(CC) $(CFLAGS) $< $(OUTPUT_OPTION)
	echo "CREATED $@"

$(OBJS_PATH)/%.o: $(SRCS_PATH)/%.c $(DEP_PATH)/%.d
	@ mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< $(OUTPUT_OPTION) $(INC) 
	echo "CREATED $@"

$(LIBFT):
	$(MAKE) $(@D) $(@F)
	echo "CREATED libft"

$(MLX):
	$(MAKE) $(@D)
	echo "CREATED libmlx"

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	$(CC) $(OBJS) $(LFLAGS)  $(OUTPUT_OPTION)  -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)  
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