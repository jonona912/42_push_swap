# Compiler and flags
CC = gcc
CFLAGS = -g# -Wall -Wextra -Werror

# Directories
SRC_DIR = src
OBJ_DIR = obj
LIB_DIR = ft_printf

# Source files
SRCS = input_checker_1.c \
		input_checker_2.c \
		lists_1.c \
		lists_2.c \
		lst_sort_checker.c \
		main.c  \
		merge_sort_lst_1.c \
		merge_sort_lst_2.c \
		operands_1.c \
		operands_2.c \
		ps_quick_sort_1.c \
		ps_quick_sort_2.c \
		ps_sort_1_asc.c \
		ps_sort_2_desc.c

# Add full paths for source files
SRC_FILES = $(addprefix $(SRC_DIR)/, $(SRCS))

# Object files
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:%.c=%.o))

# Output executable
NAME = push_swap

# Libraries to link
LIBS = -L$(LIB_DIR) -lftprintf

# Default rule to build the executable
all: $(NAME)
	./push_swap 11 10 9 8 7 6 5 4 3 2 1
# ./push_swap 321 2 1 12 9 11 3 4 43 23 93 17 0
# ./push_swap 321 2 1 12 9 -2147483648 9 22 21 20
# Link object files to create the executable
$(NAME): $(OBJS)
	$(CC) $(OBJS) $(LIBS) -o $(NAME)

# Rule to compile .c files into .o files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean the object files
clean:
	rm -rf $(OBJ_DIR)

# Remove all generated files
fclean: clean
	rm -f $(NAME)

# Rebuild everything
re: fclean all

# Phony targets
.PHONY: all clean fclean re
































# # Compiler and flags
# CC = gcc
# CFLAGS = #-Wall -Wextra -Werror

# # Directories
# SRC_DIR = src
# OBJ_DIR = obj
# LIB_DIR = ft_printf

# # List of source files (manually add the .c files here)
# SRCS = ps_ft_list_1.c ps_ft_list_2.c push_swap.c main.c input_checker.c

# # Source files with full path
# SRC_FILES = $(addprefix $(SRC_DIR)/, $(SRCS))

# # Object files (corresponding .o files for each .c file)
# OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)

# # Object files (corresponding .o files for each .c file)
# OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:%.c=%.o))

# # Output executable
# NAME = push_swap

# # Library to link against (example: libm.a or libother.a in the lib directory)
# LIBS = -L$(LIB_DIR) -lftprintf

# # Default rule to build the executable
# all: $(NAME)
# 	./push_swap 1 2 3 4 5 6 -2147483648 9 3
# # Rule to build the executable
# $(NAME): $(OBJS)
# 	$(CC) $(OBJS) $(LIBS) -o $(NAME)

# # Rule to compile .c files into .o files
# $(OBJ_DIR)/%.o: %.c
# 	@mkdir -p $(OBJ_DIR)
# 	$(CC) $(CFLAGS) -c $< -o $@

# # Clean the object files
# clean:
# 	rm -rf $(OBJ_DIR)

# # Remove all generated files
# fclean: clean
# 	rm -f $(NAME)

# # Rebuild everything
# re: fclean all

# # Phony targets
# .PHONY: all clean fclean re
