NAME 		= 	miniRT

CC			= 	cc

RM 			= 	rm -f

INC			=	-I include -I libft -I minilibx

CFLAGS		=	-Wall -Wextra -Werror

LFLAGS		=	-I./libft -lft -L./libft -I./mlx -L./mlx_linux -I./miniRT -L./miniRT

SRCS		=	main.c \

SRCS_PATH	= 	./src/

OBJS_PATH	= 	./obj/

OBJS		= 	$(addprefix $(OBJS_PATH), $(SRCS:.c=.o))

LIBFT		=	./libft/libft.a

MLX			=	./mlx_linux/libmlx_Linux.a


$(OBJS_PATH)%.o : 	$(SRCS_PATH)%.c
			@mkdir -p $(dir $@)
			$(CC) $(CFLAGS)$(LFLAGS) -c $< $(OUTPUT_OPTION) $(INC)
			@echo "CREATED $@"
$(LIBFT):
			$(MAKE) -C $(@D) $(@F)
			@echo "CREATED $(LIBFT)"
$(MLX):
			$(MAKE) -C $(@D)
			@echo "CREATED $@"

$(NAME):	$(OBJS) $(LIBFT) $(MLX) 
			$(CC) $(OBJS) $(CFLAGS) $(LFLAGS) $(OUTPUT_OPTION) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

all:		$(NAME)

clean:
			$(RM) $(OBJS) 
			$(RM) ./libft/*.o ./mlx_linux/obj/*.o
		
fclean:		clean
			$(RM) $(NAME) $(LIBFT) $(MLX)

re:			fclean all

# .SILENT: 
.PHONY:		all clean fclean re bonus