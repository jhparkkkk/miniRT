# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeepark <jeepark@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/25 12:18:16 by cgosseli          #+#    #+#              #
#    Updated: 2022/09/20 16:59:03 by jeepark          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CFLAGS = -Wall -Wextra -Werror -g3
CC = cc
RM = rm -rf

SRCS +=	ft_isalpha.c\
		ft_isdigit.c\
		ft_isalldigit.c\
		ft_isalnum.c\
		ft_isascii.c\
		ft_isprint.c\
		ft_strlen.c\
		ft_memset.c\
		ft_bzero.c\
		ft_memcpy.c\
		ft_memmove.c\
		ft_strlcpy.c\
		ft_toupper.c\
		ft_tolower.c\
		ft_strchr.c\
		ft_strrchr.c\
		ft_strncmp.c\
		ft_strcmp.c\
		ft_memchr.c\
		ft_memcmp.c\
		ft_strnstr.c\
		ft_atoi.c\
		ft_atof.c\
		ft_llatoi.c\
		ft_substr.c\
		ft_strtrim.c\
		ft_calloc.c\
		ft_strdup.c\
		ft_strjoin.c\
		ft_split.c\
		ft_itoa.c\
		ft_uitoa.c\
		ft_llitoa.c\
		ft_strmapi.c\
		ft_striteri.c\
		ft_putchar_fd.c\
		ft_putstr_fd.c\
		ft_putendl_fd.c\
		ft_strcmp.c\
		ft_putnbr_fd.c\
		get_next_line.c \
		ft_lstnew.c \
		ft_lstadd_front.c \
		ft_lstsize.c \
		ft_lstlast.c \
		ft_lstadd_back.c\
		ft_lstdelone.c \
		ft_lstclear.c \
		ft_lstiter.c \
		ft_lstmap.c \
		ft_memory.c
OBJS = ${SRCS:.c=.o}

.c.o: 
	${CC} $(CFLAGS) -c $< -o ${<:.c=.o}

${NAME} : ${OBJS}
	ar rcs ${NAME} ${OBJS}
all : ${NAME}
clean : 
	${RM} ${OBJS} 
fclean : clean 
	${RM} ${NAME}
re : fclean all
