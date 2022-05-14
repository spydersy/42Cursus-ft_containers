# ************************************************************************************************** #
#                                                                                                    #
#                                                         :::   ::::::::   ::::::::  :::::::::::     #
#    Makefile                                          :+:+:  :+:    :+: :+:    :+: :+:     :+:      #
#                                                       +:+         +:+        +:+        +:+        #
#    By: mamoussa <mamoussa@student.1337.ma>           +#+      +#++:      +#++:        +#+          #
#                                                     +#+         +#+        +#+      +#+            #
#    Created: Invalid date        by                 #+#  #+#    #+# #+#    #+#     #+#              #
#    Updated: 2022/05/14 04:15:26 by abelarif         ###   ########.fr        #
#                                                                                                    #
# ************************************************************************************************** #

COMPILER = c++
FLAGS_DEBUG = -g3 #-std=c++98 -Wall -Wextra -Werror
FLAGS = -g3 #-std=c++98 -Wall -Wextra -Werror

vector_tle:
	@$(COMPILER) $(FLAGS_DEBUG)	vector_tests_tle.cpp -o vector.out 

vector:
	@$(COMPILER) $(FLAGS)	vector_tests.cpp -o vector.out 

map:
	@$(COMPILER) $(FLAGS)	Map_tests.cpp -o map.out 

stack:
	@$(COMPILER) $(FLAGS)	Stack_tests.cpp -o stack.out 

set:
	@$(COMPILER) $(FLAGS)	Set_tests.cpp -o set.out 
clean:
	rm -f vector.out map.out stack.out set.out
