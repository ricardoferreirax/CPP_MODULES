NAME     := phonebook
CPP      := c++
CPPFLAGS := -Wall -Wextra -Werror -std=c++98
SRCS     := srcs/Contact.cpp srcs/Phonebook.cpp srcs/main.cpp
OBJS     := $(SRCS:%.cpp=$(OBJ_DIR)%.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CPP) $(CPPFLAGS) $(OBJS) -o $@
	@echo "$(NAME) created!"

%.o: %.cpp
	@$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJS)
	@echo "$(NAME) object files removed."

fclean: clean
	@rm -f $(NAME)
	@echo "$(NAME) removed."

re: fclean all

.PHONY: all clean fclean re