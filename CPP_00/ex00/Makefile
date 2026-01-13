NAME     := megaphone
CXX      := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98

OBJ_DIR  := obj/

SRCS     := srcs/megaphone.cpp

OBJS     := $(SRCS:%.cpp=$(OBJ_DIR)%.o)


all: $(NAME)
	@echo "$(NAME) built successfully!"

$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $@
	@echo "$(NAME) object files compiled."
	@echo "$(NAME) created!"

$(OBJ_DIR)%.o: %.cpp
	@mkdir -p $(dir $@)
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(NAME) object files removed."

fclean: clean
	@rm -f $(NAME)
	@echo "$(NAME) and $(NAME) object files removed."

re: fclean all

.PHONY: all clean fclean re