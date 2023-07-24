# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmaqbour <mmaqbour@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/31 10:21:14 by mmaqbour          #+#    #+#              #
#    Updated: 2023/05/31 10:21:15 by mmaqbour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#COLORS

GREEN	=	\033[1;32m
RED		=	\033[1;31m
YELLOW	=	\033[1;93m
BLUE	=	\033[1;94m
DEFAULT	=	\033[0m

#PROGRAMM NAME

PHILO_NAME	=	philo

#VARIABLES

CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror -pthread

#DIRECTORIES

SRCS_DIR = srcs
OBJS_DIR = objs

#FILES

PHILO_SRCS	=	main.c init.c life.c time.c thread.c checker.c utils.c
PHILO_OBJS	= $(addprefix $(OBJS_DIR)/,$(PHILO_SRCS:.c=.o))
PHILO_HEADER = include/philo.h


all : $(PHILO_NAME)

$(PHILO_NAME): $(OBJS_DIR) $(PHILO_OBJS)
	@echo "$(RED)##### All Objects are Compiled! #####$(DEFAULT)"
	@echo "$(YELLOW)Compiling Philo...$(DEFAULT)"
	@$(CC) $(CFLAGS) $(PHILO_OBJS) -o $(PHILO_NAME)
	@echo "$(GREEN)##### Philo Compiling Finished! #####$(DEFAULT)"

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

.PHONY: clean fclean all re
