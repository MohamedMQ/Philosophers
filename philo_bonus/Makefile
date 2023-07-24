# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/31 10:22:14 by mmaqbour          #+#    #+#              #
#    Updated: 2023/05/31 10:22:16 by mmaqbour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#COLORS

GREEN	=	\033[1;32m
RED		=	\033[1;31m
YELLOW	=	\033[1;93m
BLUE	=	\033[1;94m
DEFAULT	=	\033[0m

#PROGRAMM NAME

PHILO_NAME	=	philo_bonus

#VARIABLES

CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror -pthread

#DIRECTORIES

SRCS_DIR = srcs
OBJS_DIR = objs

#FILES

PHILO_SRCS	=	main.c checker.c init.c life_line.c life.c \
				make_philo.c parsing.c time.c utils.c
PHILO_OBJS	= $(addprefix $(OBJS_DIR)/,$(PHILO_SRCS:.c=.o))
PHILO_HEADER = include/philo.h


all : $(PHILO_NAME)

$(PHILO_NAME): $(OBJS_DIR) $(PHILO_OBJS)
	@echo "$(RED)##### All Objects Are Compiled! #####$(DEFAULT)"
	@echo "$(YELLOW)Compiling Philo_Bonus...$(DEFAULT)"
	@$(CC) $(CFLAGS) $(PHILO_OBJS) -o $(PHILO_NAME)
	@echo "$(GREEN)##### Philo_Bonus Compiling Finished! #####$(DEFAULT)"

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(PHILO_HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(YELLOW)Compiling $<"

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

clean :
	@rm -rf $(OBJS_DIR)
	@echo "$(BLUE)All Objects Are Removed!$(DEFAULT)"

fclean : clean
	@rm -rf $(PHILO_NAME)
	@echo "$(BLUE)All Cleaned!$(DEFAULT)"

re : fclean all

.PHONY : re all fclean clean
