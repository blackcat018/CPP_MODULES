# Compiler
CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++17

# Executable name
NAME = phonebook

# Source files
SRCS = main.cpp PhoneBook.cpp Contact.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Header dependencies (optional)
HEADERS = PhoneBook.hpp Contact.hpp

# Default target
all: $(NAME)

# Link object files into executable
$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

# Compile .cpp files to .o
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)


fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re