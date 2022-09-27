NAME		=	pipex // цель

FLAGS		=	-Wall -Wextra -Werror
OPTFLAGS	=	-O2

HEADER		=	pipex.h

SRCS		=	pipex.c main.c utils.c
LIBFT		=	libft/libft.a // если запускаем с либой, то обязательно добавляем библиотеку либы.


OBJS		=	$(SRCS:.c=.o)


all:		$(NAME)

$(NAME):	$(OBJS) $(LIBFT)
				cc $(FLAGS) $(OPTFLAGS) $(OBJS) -o $(NAME) $(LIBFT) // зависимость от файлов либы тоже

%.o	:	%.c $(HEADER) Makefile 
				cc ${FLAGS} -c $< -o $@

$(LIBFT) :  libft/*.h libft/*.c libft/Makefile
				@make -C libft // make для либы
clean:		
				@rm -rf $(OBJS)
				@${MAKE} -C libft clean

fclean:	clean
				@rm -rf $(NAME)
				@${MAKE} -C libft fclean

re:		fclean all

.PHONY:	all clean fclean re
