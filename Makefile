# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alngo <alngo@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/11 11:09:45 by alngo             #+#    #+#              #
#    Updated: 2019/09/11 11:46:03 by alngo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC_PATH = src
OBJ_PATH = obj
INC_PATH= ./include

SRC_NAME = main.c
LFT_PATH = ./libft/
LFT_A = -lft

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
INC = $(addprefix $(INCLUDE_PATH)/,$(INC_NAME))

RED=\033[0;31m
NC=\033[0m

.PHONY: all fclean clean re

all: $(NAME)

$(NAME): $(OBJ_PATH) $(OBJ) $(INC)
	@echo "${RED}Libft Compilation...${NC}"
	make -C $(LFT_PATH)
	$(CC) $(CFLAGS) -I $(INC_PATH) -L $(LFT_PATH) $(LFT_A) \
	   $(OBJ) -o $(NAME) $(FRAMEWORK)
	@echo "${RED}Ready to go !${NC}"

$(OBJ_PATH):
	@mkdir $(OBJ_PATH) 2> /dev/null || true

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	$(CC) $(CFLAGS) -I $(INC_PATH) -I ./libft/include -MMD -MP -c $< -o $@

clean:
	$(RM) -r $(OBJ_PATH)

fclean:	clean
	make fclean -C $(LFT_PATH)
	$(RM) -r $(NAME)

re:	fclean all

-include $(OBJ:.o=.d)
