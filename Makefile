NAME		=	minishell

FOBJ_SRC 	= 	object_files

SRCS		=	./src/Main/minishell.c\
				./src/Main/init.c\
				./src/environment/lst_envadd_back.c\
				./src/environment/lst_envlast.c\
				./src/environment/lst_envnew.c\
				./src/Parsing/dollar.c\
				./src/Parsing/parser_utils.c\
				./src/Parsing/parser.c\
				./src/Parsing/pipe_parsing.c\
				./src/Parsing/pipe_utils.c\
				./src/Parsing/redirection.c\
				./src/Parsing/redirection_utils.c\
				./src/Signal/signal.c\
				./src/Utils/utils1.c\
				./src/Utils/utils2.c\
				./src/Execution/exec_utils1.c\
				./src/Execution/exec_utils2.c\
				./src/Execution/execution.c\
				./src/Execution/set_redirection.c\
				./src/Execution/here_doc.c\
				./src/Builtins/init_builtin.c\
				./src/Builtins/pwd.c\
				./src/Builtins/echo.c\
				./src/Builtins/cd.c\
				./src/Builtins/parse.c\
				./src/Builtins/env.c\
				./src/Builtins/export.c\
				./src/Builtins/unset.c\
				./src/Builtins/ft_exit.c\
				./src/Builtins/export_utils.c\

HEADER		=	./header/minishell.h

LIBFT		=	libft/libft.a

OBJ			=	$(SRCS:.c=.o)

OBJ_B		=	$(SRCS_B:.c=.o)

CC			=	gcc

RM			=	rm -rf

FLAGS		=	-Wall -Wextra -Werror 

READ		=	-lreadline

.PHONY		:	all clean fclean re bonus

all			:	$(NAME)

$(NAME)		:	$(OBJ) $(HEADER)
						$(MAKE) all -C ./libft
						$(MAKE) bonus -C ./libft
						$(CC) $(FLAGS) $(OBJ)  ${LIBFT} -o $(NAME) $(READ) -L ~/.brew/opt/readline/lib -I ~/.brew/opt/readline/include
%.o			:	%.c $(HEADER)
								$(CC) $(FLAGS) -I$(HEADER) -c $< -o $@

bonus		:	$(OBJ_B)
				make OBJ="$(OBJ_B)" all

clean		:
				$(MAKE) clean -C ./libft
				$(RM) $(OBJ) $(OBJ_B)

fclean		:	clean
						$(MAKE) fclean -C ./libft
						$(RM) $(NAME)

re			:	fclean $(NAME)