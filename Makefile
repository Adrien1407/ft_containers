# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adlancel <adlancel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/25 14:28:17 by adlancel          #+#    #+#              #
#    Updated: 2022/06/06 16:50:55 by adlancel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = containers 

SRCS = main.cpp

HEADER = ./iterator.hpp ./map.hpp ./vector.hpp ./random_access_iterator.hpp ./stack.hpp ./ft_enable_if.hpp
CXX = c++

CXXFLAGS = -Wextra -Werror -Wall -std=c++98

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


