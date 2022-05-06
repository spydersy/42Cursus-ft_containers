# ************************************************************************************************** #
#                                                                                                    #
#                                                         :::   ::::::::   ::::::::  :::::::::::     #
#    Makefile                                          :+:+:  :+:    :+: :+:    :+: :+:     :+:      #
#                                                       +:+         +:+        +:+        +:+        #
#    By: mamoussa <mamoussa@student.1337.ma>           +#+      +#++:      +#++:        +#+          #
#                                                     +#+         +#+        +#+      +#+            #
#    Created: Invalid date        by                 #+#  #+#    #+# #+#    #+#     #+#              #
#    Updated: 2022/05/06 23:34:14 by abelarif         ###   ########.fr        #
#                                                                                                    #
# ************************************************************************************************** #

COMPILER = clang++
FLAGS = -g3#--std=c++98 -Wall -Wextra -Werror# -g3 -fsanitize=address  

vector:
	@$(COMPILER) $(FLAGS)	Vector_tests.cpp -o vector.out 

map:
	@$(COMPILER) $(FLAGS)	Map_tests.cpp -o map.out 

stack:
	@$(COMPILER) $(FLAGS)	Stack_tests.cpp -o stack.out 

set:
	@$(COMPILER) $(FLAGS)	Set_tests.cpp -o set.out 
clean:
	rm -f vector.out map.out stack.out set.out
