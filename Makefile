NAME		=	pipex

FLAGS		=	-Wall -Wextra -Werror
OPTFLAGS	=	-O2

HEADER		=	pipex.h

SRCS		=	pipex.c main.c utils.c
LIBFT		=	libft/libft.a


OBJS		=	$(SRCS:.c=.o)


all:		$(NAME)

$(NAME):	$(OBJS) $(LIBFT)
				cc $(FLAGS) $(OPTFLAGS) $(OBJS) -o $(NAME) $(LIBFT)

%.o	:	%.c $(HEADER) Makefile 
				cc ${FLAGS} -c $< -o $@

$(LIBFT) :  libft/*.h libft/*.c libft/Makefile
				@make -C libft
clean:		
				@rm -rf $(OBJS)
				@${MAKE} -C libft clean

fclean:	clean
				@rm -rf $(NAME)
				@${MAKE} -C libft fclean

re:		fclean all

.PHONY:	all clean fclean re
