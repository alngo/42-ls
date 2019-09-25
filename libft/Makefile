# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alngo <alngo@student.42.fr>                +#+  +:+       +#+         # #                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/25 21:33:03 by alngo             #+#    #+#              #
#    Updated: 2017/11/28 17:54:31 by alngo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SUB_PATH = /{type,mem,assert,put,str,conv,lst,gnl,printf}

SRC_NAME = 	assert/ft_assert.c\
		assert/ft_test.c\
		type/ft_ctype.c\
		type/ft_isalnum.c\
		type/ft_isalpha.c\
		type/ft_iscntrl.c\
		type/ft_isdigit.c\
		type/ft_isgraph.c\
		type/ft_islower.c\
		type/ft_isprint.c\
		type/ft_ispunct.c\
		type/ft_isspace.c\
		type/ft_isupper.c\
		type/ft_isxdigit.c\
		type/ft_isascii.c\
		type/ft_lower.c\
		type/ft_upper.c\
		type/ft_tolower.c\
		type/ft_toupper.c\
		\
		str/ft_strlen.c\
		str/ft_strnlen.c\
		str/ft_strcat.c\
		str/ft_strchr.c\
		str/ft_strclr.c\
		str/ft_strcmp.c\
		str/ft_strcpy.c\
		str/ft_strdel.c\
		str/ft_strdup.c\
		str/ft_strequ.c\
		str/ft_striter.c\
		str/ft_striteri.c\
		str/ft_strjoin.c\
		str/ft_strlcat.c\
		str/ft_strmap.c\
		str/ft_strmapi.c\
		str/ft_strncat.c\
		str/ft_strncmp.c\
		str/ft_strncpy.c\
		str/ft_strnequ.c\
		str/ft_strnew.c\
		str/ft_strnstr.c\
		str/ft_strrchr.c\
		str/ft_strsplit.c\
		str/ft_strstr.c\
		str/ft_strsub.c\
		str/ft_strtrim.c\
		\
		put/ft_putchar.c\
		put/ft_putchar_fd.c\
		put/ft_putendl.c\
		put/ft_putendl_fd.c\
		put/ft_putmem.c\
		put/ft_putnbr.c\
		put/ft_putnbr_fd.c\
		put/ft_putstr.c\
		put/ft_putstr_fd.c\
		\
		mem/ft_memset.c\
		mem/ft_memalloc.c\
		mem/ft_memccpy.c\
		mem/ft_bzero.c\
		mem/ft_memchr.c\
		mem/ft_memcmp.c\
		mem/ft_memcpy.c\
		mem/ft_memdel.c\
		mem/ft_memmove.c\
		\
		conv/ft_atoi.c\
		conv/ft_atol.c\
		conv/ft_stoul.c\
		conv/ft_strtol.c\
		conv/ft_strtoul.c\
		conv/ft_imaxtoa_base.c\
		conv/ft_itoa.c\
		\
		lst/ft_lstadd.c\
		lst/ft_lstaddafter.c\
		lst/ft_lstat.c\
		lst/ft_lstcount.c\
		lst/ft_lstdel.c\
		lst/ft_lstdelone.c\
		lst/ft_lstinsert.c\
		lst/ft_lstiter.c\
		lst/ft_lstmap.c\
		lst/ft_lstnew.c\
		lst/ft_lstreverse.c\
		\
		gnl/ft_gnl.c\
		\
		printf/format_character.c\
		printf/format_integer.c\
		printf/format_pointer.c\
		printf/format_string.c\
		printf/format_color.c\
		printf/ft_printf.c\
		printf/get_parameters.c\
		printf/out.c

OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ_PATH = obj
SRC_PATH = src
INCLUDE_PATH = include

LOG_CLEAR		= \033[2K
LOG_UP 			= \033[A
LOG_NOCOLOR		= \033[0m
LOG_GREEN		= \033[1;32m
LOG_YELLOW		= \033[1;33m

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ_PATH) $(OBJ)
	@echo "$(LOG_CLEAR)$(NAME)... $(LOG_YELLOW)assembling...$(LOG_NOCOLOR)"
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "$(LOG_CLEAR)$(NAME)... $(LOG_GREEN)Done !$(LOG_NOCOLOR)"

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)$(SUB_PATH) 2> /dev/null || true

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@echo "$(LOG_CLEAR)$(NAME)... $(LOG_YELLOW)$<$(LOG_NOCOLOR)$(LOG_UP)"
	@$(CC) $(CFLAGS) -I $(INCLUDE_PATH) -MMD -MP -c $< -o $@

clean:
	$(RM) -r $(OBJ_PATH)

fclean:	clean
	$(RM) -r $(NAME)

re:	fclean all

-include $(OBJ:.o=.d)
