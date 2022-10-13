# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adlancel <adlancel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/25 14:28:17 by adlancel          #+#    #+#              #
#    Updated: 2022/10/13 18:00:22 by adlancel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

STD = std
FT = ft

NAME_FT = ft_containers 
NAME_STD = std_containers 

SRCS = main.cpp \
vector.cpp \
map.cpp \
set.cpp \
# stack.cpp \

INCLUDES = -I ./srcs/

CXX = c++

CXXFLAGS = -Wextra -Werror -Wall -std=c++98

DIR_SRCS = ./tests
DIR_OBJ_FT := ft_test

OBJS_FT		:= \
				$(addprefix ${DIR_OBJ_FT}/, ${SRCS:.cpp=.o})
DIR_OBJ_STD	:= std_test
OBJS_STD	:= \
				$(addprefix ${DIR_OBJ_STD}/, ${SRCS:.cpp=.o})

all:		${NAME_FT} ${NAME_STD}

$(DIR_OBJ_FT)/%.o  :	$(DIR_SRCS)/%.cpp
						@mkdir -p $(dir $@)
						@${CXX} ${CXXFLAGS} ${INCLUDES} -DNAMESPACE=$(FT) -o $@ -c $<

$(DIR_OBJ_STD)/%.o:		$(DIR_SRCS)/%.cpp
						@mkdir -p $(dir $@)
						@${CXX} ${CXXFLAGS} ${INCLUDES} -DNAMESPACE=$(STD) -DUSE=0 -o $@ -c $<

$(NAME_FT): 	$(OBJS_FT)
				${CXX} $(CXXFLAGS) ${INCLUDES} $(OBJS_FT) -o $(NAME_FT)

$(NAME_STD): 	$(OBJS_STD)
				${CXX} $(CXXFLAGS) ${INCLUDES} $(OBJS_STD) -o $(NAME_STD)

clean:		
			@rm -rf ${OBJS_STD} ${OBJS_FT}

fclean:		clean
			@rm -rf ${NAME_FT} ${NAME_STD}
re:			fclean all

.PHONY: all clean fclean re


