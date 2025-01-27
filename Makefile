SRC_DIR_BONUS = src_bonus
OBJ_DIR_BONUS = obj_bonus
LIB_DIR_BONUS = src_bonus/gnl
BONUS_NAME = push_swap_bonus

SRCS_BONUS = input_checker_1_bonus.c \
				input_checker_2_bonus.c \
				push_swap_bonus.c \
				merge_sort_lst_1.c \
				merge_sort_lst_2.c \
				operands_1.c \
				operands_2.c

OBJ_BONUS = $(addprefix $(OBJ_DIR_BONUS)/, $(SRCS_BONUS:%.c=%.o))
LIBS_BONUS = -L$(LIB_DIR_BONUS) libgnl.a

CC = gcc
CFLAGS = #-Wall -Wextra -Werror

bonus: $(LIB_DIR_BONUS)/libgnl.a $(BONUS_NAME)

$(LIB_DIR_BONUS)/libgnl.a:
	$(MAKE) -C $(LIB_DIR_BONUS)

$(BONUS_NAME): $(OBJ_BONUS)
	$(CC) $(OBJ_BONUS) $(LIBS_BONUS) -o $(BONUS_NAME)

$(OBJ_DIR_BONUS)/%.o: $(SRC_DIR_BONUS)/%.c
	@mkdir -p $(OBJ_DIR_BONUS)
	$(CC) $(CFLAGS) -c $< -o $@



# # Compiler and flags
# CC = gcc
# CFLAGS = -g #-fsanitize=address #-Wall -Wextra -Werror

# # Directories
# SRC_DIR = src
# OBJ_DIR = obj
# LIB_DIR = ft_printf

# # Source files
# SRCS = input_checker_1.c \
# 		input_checker_2.c \
# 		lists_1.c \
# 		lists_2.c \
# 		main_helper.c \
# 		main.c \
# 		merge_sort_lst_1.c \
# 		merge_sort_lst_2.c \
# 		operands_1.c \
# 		operands_2.c \
# 		ps_qs_partition_a.c \
# 		ps_quick_sort_1.c \
# 		ps_quick_sort_2.c \
# 		ps_quick_sort_helper.c \
# 		ps_quick_sort_helper_2.c \
# 		ps_sort_asc.c \
# 		ps_sort_desc.c \
# 		ps_sort_helper.c

# # Add full paths for source files
# SRC_FILES = $(addprefix $(SRC_DIR)/, $(SRCS))

# # Object files
# OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:%.c=%.o))

# # Output executable
# NAME = push_swap
# # Libraries to link
# LIBS = -L$(LIB_DIR) -lftprintf

# # Default rule to build the executable
# all: $(NAME)
# 	./push_swap 4 40 10 49 82 70 89 76 55 31 29 37 45 5 9 13 60 80 22 86 67 42 93 101

# # Link object files to create the executable
# $(NAME): $(OBJS)
# 	$(CC) $(OBJS) $(LIBS) -o $(NAME)

# # Rule to compile .c files into .o files
# $(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
# 	@mkdir -p $(OBJ_DIR)
# 	$(CC) $(CFLAGS) -c $< -o $@

# # Clean the object files
# clean:
# 	rm -rf $(OBJ_DIR)
# 	rm -rf $(OBJ_DIR_BONUS)

# # Remove all generated files
# fclean: clean
# 	rm -f $(NAME)
# 	rm -f $(BONUS_NAME)

# # Rebuild everything
# re: fclean all

# # Phony targets
# .PHONY: all clean fclean re













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
