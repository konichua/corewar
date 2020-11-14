.PHONY: clean fclean re all

# COLORS
BLUE = "\e[38;5;69m"
EOC = "\e[0m"

# COMPILER
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Wunused

# LIBNAME
NAME := lib.a

# HEADERS
DIR_H = include
H_LIBFT = libft get_next_line
H_LIBFT := $(addprefix $(DIR_H)/, $(addsuffix .h, $(H_LIBFT)))
H_PRINTF = ft_printf
H_PRINTF := $(addprefix $(DIR_H)/, $(addsuffix .h, $(H_PRINTF)))

# LIBFT, GET_NEXT_LINE
DIR_LIBFT = libft
DIR_SRC_LIBFT = $(DIR_LIBFT)/src
DIR_OBJ_LIBFT = $(DIR_LIBFT)/obj

SRC_LIBFT = \
memset bzero memcpy memccpy memmove memchr memcmp memalloc memdel \
atoi itoa itoa_base\
isalpha isdigit isalnum isascii isprint toupper tolower isnumber isnumber_int\
strlen strdup strcpy strncpy strcat strncat strlcat strchr strrchr \
strstr strnstr strcmp strncmp strnew strdel strclr striter striteri \
strmap strmapi strequ strnequ strsub strjoin strtrim strsplit \
putchar putstr putendl putnbr putchar_fd putstr_fd putendl_fd putnbr_fd \
numlen strnew_size arrdel
SRC_LIBFT := $(addprefix ft_, $(addsuffix .c, $(SRC_LIBFT)))
SRC_GNL = get_next_line
SRC_GNL := $(addsuffix .c, $(SRC_GNL))

# PRINTF
DIR_PRINTF = printf
DIR_SRC_PRINTF = $(DIR_PRINTF)/src
DIR_OBJ_PRINTF = $(DIR_PRINTF)/obj

SRC_PRINTF = \
ft_printf ft_itoabasex ft_str_sym_cmp \
ft_cast_size_di ft_cast_size_poxu ft_cast_size_float \
parse_chr parse_str parse_per parse_bit parse_bcolor parse_bdollar parse_float parse_dipoxu \
parse_num_spec parse_dipoxu_spec_cases parse_num parse_float_number parse_float_flag \
parse_specifiers parse_output is_specifers \
record_chr record_str record_bit record_per record_float \
init_spec_struct ft_clean_mult \
ld_util ft_smbu long_m_str long_math ft_array_mantisa
SRC_PRINTF := $(addsuffix .c, $(SRC_PRINTF))

# FILE PATH TO LIBFT, GET_NEXT_LINE SRC/OBJ FILES
SRCS_LIBFT = $(addprefix $(DIR_SRC_LIBFT)/, $(SRC_LIBFT) $(SRC_GNL))
OBJS_LIBFT = $(addprefix $(DIR_OBJ_LIBFT)/, $(SRC_LIBFT:.c=.o) $(SRC_GNL:.c=.o))

# FILE PATH TO PRINTF SRC/OBJ FILES
SRCS_PRINTF = $(addprefix $(DIR_SRC_PRINTF)/, $(SRC_PRINTF))
OBJS_PRINTF = $(addprefix $(DIR_OBJ_PRINTF)/, $(SRC_PRINTF:.c=.o))

all: $(NAME)

$(DIR_OBJ_LIBFT)/%.o: $(DIR_SRC_LIBFT)/%.c $(H_LIBFT)
	@mkdir -p $(DIR_OBJ_LIBFT) 
	@$(CC) $(CFLAGS) -c $< -o $@

$(DIR_OBJ_PRINTF)/%.o: $(DIR_SRC_PRINTF)/%.c $(H_PRINTF) $(H_LIBFT)
	@mkdir -p $(DIR_OBJ_PRINTF) 
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(SRCS_LIBFT) $(OBJS_LIBFT) $(SRCS_PRINTF) $(OBJS_PRINTF) $(H_LIBFT) $(H_PRINTF)
	@ar rcs $(NAME) $(OBJS_LIBFT) $(OBJS_PRINTF)
	@echo $(BLUE)"LIB COMPILED"$(EOC)

clean:
	@rm -rf $(DIR_OBJ_LIBFT)
	@rm -rf $(DIR_OBJ_PRINTF)

fclean: clean
	@rm -f $(NAME)

re: fclean all
