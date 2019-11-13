# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmathew <hmathew@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/05 17:16:22 by hmathew           #+#    #+#              #
#    Updated: 2019/11/13 17:39:33 by hmathew          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC				=	gcc
CFLAGS			=	-g -Wall -Wextra -Werror -O3
AR				=	ar
ARFLAGS			=	rc
NAME			=	libft.a
SRC				=	$(shell find src -type f | grep -E "\.c$$")
OBJ				=	$(SRC:.c=.o)
INC 			=	inc

all: $(NAME)

$(NAME): $(OBJ)
	@$(AR) $(ARFLAGS) $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo Compile $(NAME)

%.o: %.c
	@$(CC) -o $@ -c $< $(CFLAGS) $(addprefix -I,$(INC))
	@echo Compile $<

clean:
	@rm -f $(OBJ)
	@echo Clean objects

fclean: clean
	@rm -f $(NAME)
	@echo Clean library file

re: fclean all
