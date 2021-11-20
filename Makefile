
NAME=ft_containers

SRCS=main.cpp\

OBJS=	$(SRCS:.cpp=.o)

CPPFLAGS=	-Wall -Werror -Wextra -std=c++98

$(NAME):	$(OBJS)
			clang++ $(CPPFLAGS) $(OBJS) -o $(NAME)

all: $(NAME)

clean:
		rm -rf $(OBJS)

fclean:	clean
		rm -rf $(NAME)

re : fclean all
