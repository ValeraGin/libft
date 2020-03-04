# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmathew <hmathew@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/05 17:16:22 by hmathew           #+#    #+#              #
#    Updated: 2020/03/04 20:44:35 by hmathew          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROJ_NAME	?= LIBFT
TARGET_EXEC	?= libft.a

BUILD_DIR	?= ./obj
SRC_DIRS	?= ./src

SRCS		:= $(shell find $(SRC_DIRS) -type f -name *.c )
OBJS		:= $(SRCS:%=$(BUILD_DIR)/%.o)
DEPS		:= $(OBJS:.o=.d)

INC_DIRS	:= inc
INC_FLAGS	:= $(addprefix -I,$(INC_DIRS))
CDEBUGFLAG	= -g
CFLAGS		?= $(CDEBUGFLAG) -Wall -Wextra -Werror -O3 $(INC_FLAGS) -MMD -MP

ARFLAGS		= rc

# make libft file
$(TARGET_EXEC): $(OBJS)
	@echo "\033[0;32m[$(PROJ_NAME)] \033[0m    \033[0;33m Compiling library binary:\033[0m" $@
	@$(AR) $(ARFLAGS) $(TARGET_EXEC) $(OBJS)

# c source
$(BUILD_DIR)/%.c.o: %.c
	@echo "\033[0;32m[$(PROJ_NAME)] \033[0m    \033[0;33m Compiling:\033[0m" $<
	@$(MKDIR_P) $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean fclean re

all: $(TARGET_EXEC)

clean:
	@echo "\033[0;32m[$(PROJ_NAME)] \033[0m    \033[0;33m Clean objects $(PROJ_NAME) \033[0m" $<
	@$(RM) -r $(BUILD_DIR)

fclean:
	@echo "\033[0;32m[$(PROJ_NAME)] \033[0m    \033[0;33m Clean objects $(PROJ_NAME) \033[0m" $<
	@$(RM) -r $(BUILD_DIR)
	@echo "\033[0;32m[$(PROJ_NAME)] \033[0m    \033[0;33m Clean bin $(PROJ_NAME) \033[0m" $<
	@rm -rf $(TARGET_EXEC)

re: fclean all

-include $(DEPS)

MKDIR_P ?= mkdir -p
