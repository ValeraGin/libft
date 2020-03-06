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

OBJ_DIR = ./obj

FILE_LAST_MODE = $(OBJ_DIR)/last_version.txt
cat := $(if $(filter $(OS),Windows_NT),type,cat)
LAST_MODE = $(shell $(cat) $(FILE_LAST_MODE) 2>/dev/null)

ifneq ($(mode),debug)
   mode = release
   BUILD_DIR = $(OBJ_DIR)/release
   INFO_MESSAGE = "\033[0;32m[$(PROJ_NAME)]\e[95m[$(PREFIX)]\033[0m      \033[0;33m Release mode compilation ON\033[0m"
   PREFIX = RELEASE MODE
else
   mode = debug
   BUILD_DIR = $(OBJ_DIR)/debug
   PREFIX = DEBUG MODE
   INFO_MESSAGE = "\033[0;32m[$(PROJ_NAME)]\e[95m[$(PREFIX)]\033[0m      \033[0;33m Debug mode compilation\033[0m"
endif

ifneq ($(mode),$(LAST_MODE))
    REBUILD = clean_only_exe
endif

SRC_DIRS	?= ./src

SRCS		:= $(shell find $(SRC_DIRS) -type f -name *.c )
OBJS		:= $(SRCS:%=$(BUILD_DIR)/%.o)
DEPS		:= $(OBJS:.o=.d)

INC_DIRS	:= inc
INC_FLAGS	:= $(addprefix -I,$(INC_DIRS))

CFLAGS		?= -Wall -Wextra -Werror $(INC_FLAGS) -MMD -MP
ifeq ($(mode),release)
   CFLAGS += -O3
else
   CFLAGS += -O0 -g
endif

ARFLAGS		= rc

.PHONY: all clean fclean re info

all: info $(TARGET_EXEC)

clean_only_exe:
	@echo "\033[0;32m[$(PROJ_NAME)]\033[0m      \033[0;33m Clean bin $(PROJ_NAME), because changed MODE COMPILATION \033[0m" $<
	@rm -rf $(TARGET_EXEC)

# make libft file
$(TARGET_EXEC): $(OBJS) $(REBUILD)
	@echo "\033[0;32m[$(PROJ_NAME)]\e[95m[$(PREFIX)]\033[0m    \033[0;33m Compiling library binary:\033[0m" $@
	@$(AR) $(ARFLAGS) $(TARGET_EXEC) $(OBJS)
	@rm -f $(FILE_LAST_MODE)
	@echo "$(mode)" >> $(FILE_LAST_MODE)

# c source
$(BUILD_DIR)/%.c.o: %.c
	@echo "\033[0;32m[$(PROJ_NAME)]\e[95m[$(PREFIX)]\033[0m    \033[0;33m Compiling:\033[0m" $<
	@$(MKDIR_P) $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

info:

clean:
	@echo "\033[0;32m[$(PROJ_NAME)]\033[0m    \033[0;33m Clean objects $(PROJ_NAME) \033[0m" $<
	@$(RM) -rf $(OBJ_DIR)

fclean:
	@echo "\033[0;32m[$(PROJ_NAME)]\033[0m    \033[0;33m Clean objects $(PROJ_NAME) \033[0m" $<
	@$(RM) -rf $(OBJ_DIR)
	@echo "\033[0;32m[$(PROJ_NAME)]\033[0m    \033[0;33m Clean bin $(PROJ_NAME) \033[0m" $<
	@rm -rf $(TARGET_EXEC)

norme:
	@norminette | grep Error -B 1

re: fclean all

# -include $(DEPS)

MKDIR_P ?= mkdir -p
