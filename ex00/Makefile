# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alsaeed <alsaeed@student.42abudhabi.ae>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/04 20:51:31 by alsaeed           #+#    #+#              #
#    Updated: 2024/05/08 06:35:51 by alsaeed          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# colors #
GREEN 		= \033[32m
RED 		= \033[31m
BOLD_GREEN 	= \033[1;32m
BOLD_RED 	= \033[1;31m
RESET 		= \033[0m

NAME = bureaucrat

CXX = c++

CXXFLAGS = -Wall -Werror -Wextra -std=c++98

SRCS = Bureaucrat.cpp

OBJS_DIR = objs

OBJS = $(SRCS:%.cpp=$(OBJS_DIR)/%.o)

$(OBJS_DIR)/%.o: %.cpp
	@mkdir -p $(OBJS_DIR)
	@$(CXX) $(CXXFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS) main.cpp
	@$(CXX) $(CXXFLAGS) $(OBJS) main.cpp -o $@
	@echo "bureaucrat compiled: $(BOLD_GREEN)OK$(RESET)"

$(OBJS): Makefile main.cpp Bureaucrat.cpp Bureaucrat.hpp

clean:
	@if [ -e $(OBJS_DIR) ]; then \
		rm -rf $(OBJS_DIR); \
		echo "bureaucrat clean: $(BOLD_RED)OK$(RESET)"; \
	fi

fclean: clean
	@if [ -e $(NAME) ]; then \
		rm -rf $(NAME); \
		echo "bureaucrat full-clean: $(BOLD_RED)OK$(RESET)"; \
	fi

re: fclean all

.PHONY: all clean fclean re