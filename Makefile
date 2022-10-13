
NAME	= miniRT

CC            := cc
CFLAGS        := -Wall -Wextra -Werror -c -g3

# ifeq ($(DEBUG), 1)
# CFLAGS			+= -g3
# endif

INC			=	-I include -I$(LIBFT_PATH) -I$(MLX_PATH)
LFLAGS		=	-L$(MLX_PATH) -l$(MLX) -lXext -lX11
# -lz si ca bug
LFLAGS		+=	-L$(LIBFT_PATH) -l$(LIBFT)
LFLAGS		+=	-lm

LIBFT		=	ft
LIBFT_A		=	lib$(LIBFT).a
LIBFT_PATH	=	./libft/

MLX			=	mlx_Linux
MLX_A		=	lib$(MLX).a
MLX_PATH	=	./libmlx/

SRCS_PATH	:=	src
OBJS_PATH	:=	obj
SRCS     	+=	main.c \
				init_view.c \
				set_ray.c \
				draw_world.c \
				get_viewport.c \
				${addprefix parsing/, \
					check_filename.c \
					get_scene.c \
					get_camera.c \
					get_light.c \
					get_ambient_light.c \
					get_objects_list.c \
					create_sphere.c \
					create_plane.c \
					create_cylinder.c \
					parse_position.c \
					parse_direction.c \
					check_double.c \
					check_valid_color_range.c \
					get_surface.c \
					get_specular_exponent.c \
				} \
				${addprefix utils/, \
					jump_spaces.c \
					jump_data.c \
					is_space.c \
					print_world.c \
					get_hex_color.c \
					vec_cross.c \
					vec_dot.c \
					vec_substract.c \
					vec_add.c \
					vec_scalar.c \
					vec_divide.c \
					vec_len.c \
					vec_init.c \
					vec_normalize.c \
					vec_compare.c \
					print_sp.c \
					deg_to_rad.c \
				} \
				${addprefix mlx/, \
					init_mlx.c \
					put_pix.c \
				} \
				${addprefix intersections/, \
					hit_obj.c \
					hit_sp.c \
				} \
				${addprefix lights/, \
					compute_lighting.c \
					compute_color.c \
				} \
				${addprefix shadows/, \
					sp_shadows.c \
				}
					
				
SRCS          := $(SRCS:%=$(SRCS_PATH)/%)
OBJS          := $(SRCS:$(SRCS_PATH)/%.c=$(OBJS_PATH)/%.o)


RM            := rm -f

$(NAME): $(OBJS) $(LIBFT_PATH)$(LIBFT_A) $(MLX_PATH)$(MLX_A)
	$(CC) $(OBJS) $(LFLAGS) $(OUTPUT_OPTION) 
	echo "CREATED $(NAME)"

all:        $(NAME)

$(OBJS_PATH)/%.o: $(SRCS_PATH)/%.c 
	@ mkdir -p $(@D)
	$(CC) $(CFLAGS) $< $(OUTPUT_OPTION) $(INC) 
	echo "CREATED $@"

$(LIBFT_PATH)$(LIBFT_A):
	$(MAKE) -C $(@D) $(@F)

$(MLX_PATH)$(MLX_A):
	$(MAKE) -C $(@D)


clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFT_PATH) clean
	$(MAKE) -C $(MLX_PATH) clean

fclean: clean
	$(RM) $(NAME) $(LIBFT_PATH)$(LIBFT_A) $(MLX_PATH)$(MLX_A)

re: fclean all

# info:
# 	make --dry-run --always-make --no-print-directory | grep -v "echo \| mkdir"

# .SILENT:
.PHONY:    all clean fclean re check_libft check_libmlx