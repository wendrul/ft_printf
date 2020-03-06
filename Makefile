# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/16 17:26:10 by dhorvill          #+#    #+#              #
#    Updated: 2020/03/06 20:34:30 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	src/ft_printf.c\
				src/read_format.c\
				src/read_flags.c\
				src/utils.c\
				src/common.c\

SRCS		+=	src/put_c.c\
				src/put_s.c


MKDIR_P		=	mkdir -p
RM			=	rm -f

NAME		=	libftprintf.a

# **************************************************************************** #

# Directories
SRC_DIR		=	src
OBJ_DIR		=	obj
INC_DIR		=	include
# **************************************************************************** #

# LIBFT
LFT_NAME	=	libft.a
LFT_PATH	=	./libft
LFT_LIB		=	-L$(LFT_PATH) -lft
LFT_INC		=	-I$(LFT_PATH)/
LFT_RULE	=	$(LFT_PATH)/$(LFT_NAME)
# **************************************************************************** #

OBJS		=	$(patsubst src/%.c, $(OBJ_DIR)/%.o, $(SRCS))
LIB			=	$(LFT_LIB) $(LSDL_LIB) 
INC			=	-I $(INC_DIR) $(LFT_INC)

# COLORS
RED			=	\033[0;31m
GREEN		= 	\033[0;32m
YELLOW		=	\033[0;33m
BLUE		=	\033[0;34m
MAGENTA		=	\033[0;35m
CYAN		=	\033[0;36m
RESET		=	\033[0m
# **************************************************************************** #
CFLAGS		=	-Wall -Wextra -Werror
ARFLAGS		=	-crs

CC			=	gcc
AR			=	ar


all:			${NAME}

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c $(INC_DIR)/
				@$(MKDIR_P) $(OBJ_DIR)
				@$(CC) $(CFLAGS) -c -o $@ $< $(INC)
				@printf "$(CYAN)Compiling $(MAGENTA)$<$(RESET)\r"

$(NAME):		$(OBJS)
				@printf "$(CYAN)Done creating $(NAME) object files!\n$(RESET)"
				$(AR) $(ARFLAGS) $(NAME) $(OBJS)
				@echo "$(CYAN)Created $(GREEN)$(NAME)$(CYAN)!! $(RESET)"

$(LFT_RULE):
				@make -C $(LFT_PATH)/

clean: 
				@${RM} ${OBJS}
				@rmdir $(OBJ_DIR)
				@echo "$(CYAN)TIDY UP $(RED)pls$(RESET)"

fclean:			clean
				@${RM} ${NAME}
				@echo "$(CYAN)Everything is $(RED)c $(YELLOW)l $(GREEN)e $(CYAN)a $(MAGENTA)n $(RESET)"
				
re:				fclean all

test:			all
				$(CC) test.c  $(OBJS) -I$(INC_DIR)

together:		all
				@echo "$(CYAN)"
				@echo "&&&&&&&&&&&&&&&(((((((((((((#((((((((((((((((((((((((((((((((((((((((((((((((%@@@@@@@@@@@@@%#######%&&&&&&&&&"
				@echo "&&&&&&&&&&&&&&%(((#(((((((((((#((((((((##(((((((((((((((((((((((((((((((((((((((&@@@@@@@@@@@@@@@@%####&&&@&&&"
				@echo "&&&&&&&&&&&&@@@@@@@%((#((((((#(((((((((#(((((((((((((((((((%@@@((((((((((((((((@@&@@@@@@@@@@@@@@@@@%#&&&@@&&&"
				@echo "&&&&&&&&&&&@@@@@@@@@@@@@#((((#(((((((##((((((((((((#(#%@@@@@@@@@@@@((((((((((((#@@&@@@@@@@&@@@@@@@@@@@@@@@@@@"
				@echo "&&&&&&&&&@@@@@@@@@@@@@@@@@@@&((((((((%&((((((((#%@@@@@@@@@@@@@@@@@@@@@#(((((((((((&@@@@@@@@#((((((&@@@@@@@@@&"
				@echo "&&&&&&&&&@@@@@@@@@@@@@@@@@@@@&(#(((((&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%(((((((((((@@@@@@@%((((((((&@@@@@@@@@"
				@echo "&&&&&&&&&&((((((((((%@@@@@@@@@@#((((((@@@@@@@@@@@@@@@@@@@@@@%%#((#%@@@@@##((((((((((@@@@@%((((((#((#@@@@@@@@@"
				@echo "&&&&&&&&&&(((((((((((((#&@@@@@#((((@@@@@@@@@@@@@@%(#%%##((((((((#&@@@(((((((((#(#@@@&(#((((%((((&@@@@@@@@@&&@"
				@echo "&&&&&&&&&&&(((((((((((((((#((@@@%(((((&@@@@@@(((##(((((((#(((((((((#@@(((((((((((&@&((((((#(((((%@@@@@@@@@@@@"
				@echo "&&&&&&&&&&&&&%(#(((((((((###(((##(##(((((((((((((##(((((((((((##(((((((((&%(((((((((((@((((((##(((((%@@@@@@@@"
				@echo "&&&&&&&&&&&&&&%(((((((((##((((((((##((((((((((((#(((((((((((((((#((((((((((((((((((((((((((((#((((((%@@&@@@@@"
				@echo "&&&&&&&&&&&&&&&%(((((((#((#((((((((#(((((((((((((((((((((((((((((((((((((((((((((((((((((((((#(((((#@@@@&@@@@"
				@echo "&&&&&&&&&&&&&&&&&((((#((((((((((((##((((((((((((((((((((((((((((((###(((((((((((((((((((((((((((((#@@@@@&@@@@"
				@echo "&&&&&&&&&&&&&&(((((((((((((((((((#(((((((((((((((#(###%&@@@@@@#(##(((((((((((((((((((((((((((((#@@@@@@&@@@@&&"
				@echo "&&&&&&&&&&&%#((((((@@@@&&&@@@@@@@%/#(((((((((((#(*******(@@@@@(((((((((((((((((((((((((##(((((%@@@@@@@@@@@@@&"
				@echo "&&&&&&&&%#((((((((((((#(******@@@%##((((((((((#((((((((((((((((((((((((((((((((((((((((((###(##(#@@@@@@@@@@@@"
				@echo "&&&&&&&%((((((((((((#(#((***(((((((%(((((((((((##(((((((((((((((((((((((((((((((((((((((((#((((((@@@@@@@@&@@@"
				@echo "&&&&&&&&%(((((((((((((##(((((((((#(#((((((((((((((#((((((((((((((((((((((((((((((((((((((((%(((((&@@@@@@@@&@@"
				@echo "&&&&&&&&&%((((((((((((((((((((((((##((((((((((((((((((((((((((((((((((((((((((((((((((((((((#((((#@@@@@@@@@@&"
				@echo "&&&&&&&&&&%((((((((((((((((((((((((#((((((((((((((((((((((((((((((((((((((((((((((((((((((((#(((((&@@@@@@@@@@"
				@echo "&&&&&&&&&&&%(((((((((((((((((((((((#((((((((((((((((((((((((((((((###(((((((((((((((((((((((#%((((#@@@@@@@@@@"
				@echo "&&&&&&&&&&&((((((((((((((((((((((#((((((((((((((((((((((((((((##(((#((((((((((((((((((((((((#((((&@@@@@@@@@@@"
				@echo "&&&&&&&&&&&&(((((((((((((((((((((#((((((((#((((((((((((#(#%#(###(((%#(((((((((((((((((((((((#((((#@@@@@@@@@@@"
				@echo "&&&&&&&&&&&&&((((((((((((((((((#(#(((((((#(%((((((((((((((((((##(((##(((((((((((((((((((((((#%((((&@@@@@@@@@@"
				@echo "&&&&&&&&&&&&&&&(((((((((((((((#((#(#((((((((((%#(((((((((((((((#%((((#((((((((((((((((((((((((((#(((#@@@@@@@@"
				@echo "&&&&&&&&&&&&&&&%((((((((((((((#(#((#(((((((((((%((((((((((((((#%(((((((((((((((((((((((((((((((((#(((&@@@@@@@"
				@echo "&&&&&&&&&&&&&&&&%(((((((((((((((#(#%(((((((######((((((((((((%%#(((((((((((((((((((((((((((((((((#(#(#@@@@@@@"
				@echo "&&&&&&&&&&&&&&&&((((((((((((((((##(((((((##((((((((((((((#(%#(((((((((((((((((((((((((((((((((((%(((%@@@@@@@@"
				@echo "&&&&&&&&&&&&&&&&&((((((((((((((((#((((((##((((((((((((((#*(#(((((((((((((((((((((((((((((((((((((#((#@@@@@@@@"
				@echo "&&&&&&&&&&&&&&&&&&&((((((((((((((((#((((((##((((((((((((%**((((((((((((((((((((((((((((((((((((((((##((%@@@@@"
				@echo "&&&&&&&&&&&&&&&&&@@#((((((((((((((((#(((((##((((((((###/**%(#(((((((((((((((((((((((((((((((((((((((#((#@@@@@"
				@echo "&&&&&&&&&&&&&&&&@@@%(((((((((((((##(((((((((((((#(##****/#(((((((((((((((((((((((((((((((((((((((((((%((%@@@@"
				@echo "&&&&&&&&&&&&&&&@@@@@#((((((((((#############%#/********#(((((((((((((((((((((((((((((((((((((((((((((%((#@@@@"
				@echo "&&&&&&&&&&&&&&@@@@@@#(((((((((((********************/#((((((((((((((((((((((((((((((((((((((((((((###((((%@@@"
				@echo "&&&&&&&&&&&&&@@@@@@@#(((####((((/***************/(#((((((((((((((((((((((((((((((((((((((((((((((##((((((#@@@"
				@echo "&&&&&&&&&&&&@@@@@@@@#((((%(#((((((#############((((((((((((((((((((((((((((((((((((((((((((((((#%(((((((((%@@"
				@echo "&&&&&&&&&&&@@@@@@@@@((((((%(((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((%((((((((((((&@"
				@echo "&&&&&&&&&&&@@@@@@@@&(((((((#((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((##(((((((((((((#@"
				@echo "&&&&&&&&&&&@@@@@@@@%(((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((#(%((((((((((((((((&"
				@echo "&&&&&&&&&&&@@@@@@@@#(((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((%((((((((((((((((((#"
				@echo "&&&&&&&&&&&@@@@@@@@((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((##(((((((((((((((((((("
				@echo "&&&&&&&&&&&@@@@@@@#((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((#%(((((((((((((((((((((("
				@echo "&&&&&&&&&&@@@@@@@&((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((#(((((((((((((((((((((((("
				@echo "&&&&&&&&&@@@@@@@@#((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((##((((((((((((((((((((((((("
				@echo "$(RESET)"
				@echo "$(YELLOW)╔═╗┬ ┬  ┬ ┬┌─┐┌─┐┬ ┬    ┬┌┬┐┌─┐  ┌─┐┬  ┬    ┌─┐┌─┐┌┬┐┬┌┐┌┌─┐  ┌┬┐┌─┐┌─┐┌─┐┌┬┐┬ ┬┌─┐┬─┐$(RESET)"
				@echo "$(YELLOW)║ ║├─┤  └┬┘├┤ ├─┤├─┤    │ │ └─┐  ├─┤│  │    │  │ │││││││││ ┬   │ │ ││ ┬├┤  │ ├─┤├┤ ├┬┘$(RESET)"
				@echo "$(YELLOW)╚═╝┴ ┴   ┴ └─┘┴ ┴┴ ┴┘,  ┴ ┴ └─┘  ┴ ┴┴─┘┴─┘  └─┘└─┘┴ ┴┴┘└┘└─┘   ┴ └─┘└─┘└─┘ ┴ ┴ ┴└─┘┴└─$(RESET)"

.PHONY:	all clean fclean test re