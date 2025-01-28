# Directories
SRC_DIR = src
OBJ_DIR = obj
FT_PRINTF_DIR = ft_printf
GNL_DIR = src_bonus/gnl
LIBFT_DIR = libft
SRC_DIR_BONUS = src_bonus
OBJ_DIR_BONUS = obj_bonus

LIBFT = $(LIBFTDIR)/libft.a
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a
GNL = $(GNL_DIR)/libgnl.a

# Libraries
LIBS = -L $(FT_PRINTF_DIR) -lftprintf
LIBS_BONUS = -L $(FT_PRINTF_DIR) -lftprintf -L $(GNL_DIR) -lgnl -L $(LIBFT_DIR) -lft

# NAME
NAME = push_swap
NAME_BONUS = checker

# Compiler and Flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -fPIC
INCLUDES = -I include -I $(FT_PRINTF_DIR) -I $(GNL_DIR) -I $(LIBFT_DIR)

# Source Files
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

SRCS_BONUS = check_error_bonus.c \
				checker_bonus.c \
				list_bonus.c \
				perform_operations_bonus.c \
				push_swap_bonus.c \
				input_checker_1.c \
				input_checker_2.c \
				lists_1.c \
				lists_2.c \
				main_helper.c \
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

# Object Files
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
OBJS_BONUS = $(addprefix $(OBJ_DIR_BONUS)/, $(SRCS_BONUS:.c=.o))

# Rules
all: $(NAME)

bonus: $(NAME_BONUS)
	

$(NAME): $(OBJS) $(LIBFT) $(FT_PRINTF)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

$(NAME_BONUS): $(OBJS_BONUS) $(LIBFT) $(FT_PRINTF) $(GNL)
	$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBS_BONUS) -o $(NAME_BONUS)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(FT_PRINTF):
	$(MAKE) -C $(FT_PRINTF_DIR)

$(GNL):
	$(MAKE) -C $(GNL_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR_BONUS)/%.o: $(SRC_DIR_BONUS)/%.c
	@mkdir -p $(OBJ_DIR_BONUS)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR) $(OBJ_DIR_BONUS)
	cd $(LIBFT_DIR) && $(MAKE) clean
	cd $(GNL_DIR) && $(MAKE) clean
	cd $(FT_PRINTF_DIR) && $(MAKE) clean

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)
	cd $(LIBFT_DIR) && $(MAKE) fclean
	cd $(GNL_DIR) && $(MAKE) fclean
	cd $(FT_PRINTF_DIR) && $(MAKE) fclean

re: fclean all



























# # Compiler
# CC = cc

# # Flags
# CFLAGS = -Wall -Wextra -Werror

# # Directories
# SRC_DIR = src
# OBJ_DIR = obj
# FT_PRINTF_DIR = ft_printf
# GNL_DIR = src_bonus/gnl
# SRC_DIR_BONUS = src_bonus
# OBJ_DIR_BONUS = obj_bonus

# # Libraries
# LIBS_BONUS = -L $(FT_PRINTF_DIR) -lftprintf -L $(GNL_DIR) -lgnl

# # NAME
# NAME = push_swap_bonus
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

# # Source Files
# SRCS_BONUS = check_error_bonus.c \
# 				input_checker_1_bonus.c \
# 				input_checker_2_bonus.c \
# 				list_bonus.c \
# 				perform_operations_bonus.c \
# 				push_swap_bonus.c
# 				input_checker_1.c \
# 				input_checker_2.c \
# 				lists_1.c \
# 				lists_2.c \
# 				main_helper.c \
# 				merge_sort_lst_1.c \
# 				merge_sort_lst_2.c \
# 				operands_1.c \
# 				operands_2.c \
# 				ps_qs_partition_a.c \
# 				ps_quick_sort_1.c \
# 				ps_quick_sort_2.c \
# 				ps_quick_sort_helper.c \
# 				ps_quick_sort_helper_2.c \
# 				ps_sort_asc.c \
# 				ps_sort_desc.c \
# 				ps_sort_helper.c
# # $(wildcard $(SRC_DIR_BONUS)/*.c) $(shell find $(SRC_DIR) -maxdepth 1 -name "*.c" ! -name "main.c")

# # Object Files
# OBJS_BONUS = $(addprefix $(OBJ_DIR_BONUS)/, $(SRCS_BONUS:.c=.o))
# OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:%.c=%.o))

# # Build the executable
# $(NAME): $(OBJS_BONUS) $(OBJS)
# 	$(CC) $(CFLAGS) $(OBJS_BONUS) $(OBJS) -o $(NAME) $(LIBS_BONUS)

# # Compile source files into object files
# $(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
# 	mkdir -p $(OBJ_DIR)
# 	$(CC) $(CFLAGS) -c $< -o $@

# # Clean the build
# clean:
# 	rm -f $(OBJS_BONUS)

# # Clean everything
# fclean: clean
# 	rm -f $(NAME)

# # Rebuild
# re: fclean $(NAME)

# .PHONY: all clean fclean re


























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

# # NAME executable
# NAME = push_swap
# # Libraries to link
# LIBS = -L$(LIB_DIR) -lftprintf

# # Default rule to build the executable
# all: $(NAME)


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







# ./push_swap 4 40 10 49 82 70 89 76 55 31 29 37 45 5 9 13 60 80 22 86 67 42 93 101





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

# # NAME executable
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
