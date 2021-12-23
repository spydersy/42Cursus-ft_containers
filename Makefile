
NAME=ft_containers

SRCS=vector_test.cpp\

OBJS=	$(SRCS:.cpp=.o)

CPPFLAGS= -Wall -Werror -Wextra -std=c++98

$(NAME):	$(OBJS)
			clang++ $(OBJS) -o $(NAME)

all: $(NAME)

clean:
		rm -rf $(OBJS)

fclean:	clean
		rm -rf $(NAME)

re : fclean all
