# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alngo <alngo@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/11 11:09:45 by alngo             #+#    #+#              #
#    Updated: 2019/10/22 10:20:05 by alngo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC_PATH = src
OBJ_PATH = obj
INC_PATH= ./include

SRC_NAME = main.c\
	   retrieve_options.c\
	   retrieve_arguments.c\
	   sort_arguments.c\
	   format_out.c\
	   long_plain_field_out.c\
	   long_formatted_field_out.c\
	   error_out.c\
	   tmpToDelete.c

LFT_PATH = ./libft/
LFT_A = -lft

OBJ_NAME = $(SRC_NAME:.c=.o)

SANITIZE = -fsanitize=address

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
	$(CC) $(CFLAGS) $(SANITIZE) -I $(INC_PATH) -L $(LFT_PATH) $(LFT_A) \
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
