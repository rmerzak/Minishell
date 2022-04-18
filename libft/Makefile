# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zchbani <zchbani@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/05 15:28:54 by rmerzak           #+#    #+#              #
#    Updated: 2022/04/15 23:18:26 by zchbani          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a 

SRCS		=	ft_isascii.c ft_memmove.c ft_strlen.c ft_atoi.c ft_isdigit.c ft_memset.c ft_strncmp.c\
		  ft_bzero.c ft_isprint.c ft_strchr.c ft_strnstr.c\
		  ft_calloc.c ft_memchr.c ft_strdup.c ft_strrchr.c\
		  ft_isalnum.c ft_memcmp.c ft_strlcat.c ft_tolower.c\
		  ft_isalpha.c ft_memcpy.c ft_strlcpy.c ft_toupper.c\
		  ft_substr.c ft_strjoin.c ft_strtrim.c ft_putstr_fd.c\
		  ft_putchar_fd.c ft_putendl_fd.c ft_strmapi.c ft_striteri.c ft_split.c ft_itoa.c\
		  ft_putnbr_fd.c ft_strcmp.c\


SRCS_B		=	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstadd_back.c ft_lstlast.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c\

HEADER		=	libft.h
OBJS		=	$(patsubst %.c,%.o,$(SRCS))
OBJS_B		=	$(SRCS_B:%.c=%.o)
 
CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror -I$(HEADER)

.PHONY		:	all clean fclean re bonus

all			:	$(NAME)

$(NAME)		:	$(OBJS) $(HEADER)
	@ar rcs $(NAME) $?

%.o : %.c $(HEADER)
	@$(CC) -g $(CFLAGS) -c $< -o $@

bonus		:
	@make OBJS="$(OBJS_B)" all

clean		:	
	@rm -f $(OBJS) $(OBJS_B)

fclean		:	clean
	@rm -f $(NAME)

re:			fclean all
