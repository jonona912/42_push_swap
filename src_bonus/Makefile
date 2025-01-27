# Compiler
CC = cc

# Flags
CFLAGS = -Wall -Wextra -Werror

# Directories
SRC_DIR = ../src
FT_PRINTF_DIR = ../ft_printf
GNL_DIR = ./gnl

# Libraries
LIBS = -L $(FT_PRINTF_DIR) -lftprintf -L $(GNL_DIR) -lgnl

# Output
OUTPUT = ./push_swap_bonus

# Source Files
SRCS = $(wildcard *.c) $(shell find $(SRC_DIR) -maxdepth 1 -name "*.c" ! -name "main.c")

# Object Files
OBJS = $(SRCS:.c=.o)

# Build the executable
$(OUTPUT): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(OUTPUT) $(LIBS)

# Compile source files into object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean the build
clean:
	rm -f $(OBJS)

# Clean everything
fclean: clean
	rm -f $(OUTPUT)

# Rebuild
re: fclean $(OUTPUT)

.PHONY: all clean fclean re





# Compiler and flags
CC = gcc
CFLAGS = -g #-fsanitize=address #-Wall -Wextra -Werror

# Directories
SRC_DIR = src
OBJ_DIR = obj
LIB_DIR = ft_printf

# Source files
SRCS = input_checker_1.c \
		input_checker_2.c \
		lists_1.c \
		lists_2.c \
		main_helper.c \
		main.c \
		merge_sort_lst_1.c \
		merge_sort_lst_2.c \
		operands_1.c \
		operands_2.c \
		ps_qs_partition_a.c \
		ps_quick_sort_1.c \
		ps_quick_sort_2.c \
		ps_quick_sort_helper.c \
		ps_quick_sort_helper_2.c \
		ps_sort_asc.c \
		ps_sort_desc.c \
		ps_sort_helper.c

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
	rm -rf $(OBJ_DIR_BONUS)

# Remove all generated files
fclean: clean
	rm -f $(NAME)
	rm -f $(BONUS_NAME)

# Rebuild everything
re: fclean all

# Phony targets
.PHONY: all clean fclean re