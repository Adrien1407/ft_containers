# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adlancel <adlancel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/25 14:28:17 by adlancel          #+#    #+#              #
#    Updated: 2022/06/15 11:45:21 by adlancel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = containers 

SRCS = mains/main.cpp

HEADER = ../includes/iterator.hpp \
		 ../includes/map.hpp \
		 ../includes/vector.hpp \
		 ../includes/random_access_iterator.hpp \
		 ../includes/stack.hpp \
		 ../includes/ft_enable_if.hpp
CXX = c++

CXXFLAGS = -Wextra -Werror -Wall -std=c++98 -g

OBJS = ${SRCS:.cpp=.o}


all:		${NAME}

${NAME}:	${OBJS}
			@${CXX} ${CXXFLAGS} ${OBJS} -o ${NAME}
			
clean:		
			@rm -rf ${OBJS}

fclean:		clean
			@rm -rf ${NAME}
re:			fclean all

.PHONY: all clean fclean re


