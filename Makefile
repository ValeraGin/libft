# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmathew <hmathew@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/05 17:16:22 by hmathew           #+#    #+#              #
#    Updated: 2019/12/11 21:51:20 by hmathew          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROJ_NAME=LIBFT
NO_COLOR=\x1b[0m
OK_COLOR=\x1b[32;01m
ERROR_COLOR=\x1b[31;01m
WARN_COLOR=\x1b[33;01m
OK_STRING="$(OK_COLOR)[OK]$(NO_COLOR)"

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
	@echo "\033[0;32m[$(PROJ_NAME)] \033[0m       \033[0;33m Compiling binary:\033[0m" $@
	@$(AR) $(ARFLAGS) $(NAME) $(OBJ)
	@ranlib $(NAME)

%.o: %.c
	@echo "\033[0;32m[$(PROJ_NAME)] \033[0m       \033[0;33m Compiling:\033[0m" $<
	@$(CC) -o $@ -c $< $(CFLAGS) $(addprefix -I,$(INC))

clean:
	@echo "\033[0;32m[$(PROJ_NAME)] \033[0m       \033[0;33m Cleaning libft objects\033[0m" $<
	@rm -f $(OBJ)

fclean: clean
	@echo "\033[0;32m[$(PROJ_NAME)] \033[0m       \033[0;33m Cleaning libft binary\033[0m" $<
	@rm -f $(NAME)

re: fclean all
