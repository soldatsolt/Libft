NAME = libft.a
SRCS =	srcs/ft_itoa_base_big_ll.c \
		srcs/ft_atoi_base.c\
		srcs/ft_itoa_base_big_l.c \
		srcs/collect.c \
		srcs/ft_itoa_base_big_h.c \
		srcs/ft_itoa_base_big_hh.c \
		srcs/ft_itoa_base_small_h.c \
		srcs/ft_itoa_base_small_hh.c \
		srcs/ft_itoa_base_small_l.c \
		srcs/ft_itoa_base_small_ll.c \
		srcs/ft_atoi.c \
		srcs/ft_utoa_hh.c \
		srcs/ft_utoa_h.c \
		srcs/ft_utoa_l.c \
		srcs/ft_utoa_ll.c \
		srcs/ft_itoa_h.c \
		srcs/ft_itoa_hh.c \
		srcs/ft_itoa_l.c \
		srcs/ft_itoa_ll.c  \
		srcs/ft_catstr.c \
		srcs/ft_itoa_base_small.c \
		srcs/ft_itoa_base_big.c \
		srcs/get_next_line.c \
		srcs/ft_utoa.c \
		srcs/ft_strrev.c \
		srcs/ft_bzero.c \
		srcs/ft_strrejoin.c \
		srcs/ft_isalnum.c \
		srcs/ft_strchr_n.c \
		srcs/ft_isalpha.c \
		srcs/ft_isascii.c \
		srcs/ft_isdigit.c \
		srcs/ft_isprint.c \
		srcs/ft_memccpy.c \
		srcs/ft_memchr.c \
		srcs/ft_memcmp.c \
		srcs/ft_memcpy.c \
		srcs/ft_memmove.c \
		srcs/ft_memset.c \
		srcs/ft_strcat.c \
		srcs/ft_strchr.c \
		srcs/ft_strcmp.c \
		srcs/ft_strcpy.c \
		srcs/ft_strdup.c \
		srcs/ft_strlcat.c \
		srcs/ft_strlen.c \
		srcs/ft_strncat.c \
		srcs/ft_strncmp.c \
		srcs/ft_strncpy.c \
		srcs/ft_strnstr.c \
		srcs/ft_strrchr.c \
		srcs/ft_strstr.c \
		srcs/ft_tolower.c \
		srcs/ft_toupper.c \
		srcs/ft_itoa.c \
		srcs/ft_memalloc.c \
		srcs/ft_memdel.c \
		srcs/ft_putchar.c \
		srcs/ft_putchar_fd.c \
		srcs/ft_putendl.c \
		srcs/ft_putendl_fd.c \
		srcs/ft_putnbr.c \
		srcs/ft_putnbr_fd.c \
		srcs/ft_putstr.c \
		srcs/ft_putstr_fd.c \
		srcs/ft_strclr.c \
		srcs/ft_strdel.c \
		srcs/ft_strequ.c \
		srcs/ft_striter.c \
		srcs/ft_striteri.c \
		srcs/ft_strjoin.c \
		srcs/ft_strmap.c \
		srcs/ft_strmapi.c \
		srcs/ft_strnequ.c \
		srcs/ft_strnew.c \
		srcs/ft_strsplit.c \
		srcs/ft_strsub.c \
		srcs/ft_strtrim.c \
		srcs/ft_lstadd.c \
		srcs/ft_lstdel.c \
		srcs/ft_lstdelone.c \
		srcs/ft_lstiter.c \
		srcs/ft_lstmap.c \
		srcs/ft_lstnew.c \
		srcs/xmalloc.c \
		srcs/all_flagsspec.c \
		srcs/buffer.c \
		srcs/buffer2.c \
		srcs/colors.c \
		srcs/double.c \
		srcs/free_dd.c \
		srcs/i_flags.c \
		srcs/i_flags1.c \
		srcs/i_flags2.c \
		srcs/l_ll_h_hh_for_i.c \
		srcs/l_ll_h_hh_for_o.c \
		srcs/l_ll_h_hh_for_u.c \
		srcs/l_ll_h_hh_for_x.c \
		srcs/long_double.c \
		srcs/make_ox_for_any.c \
		srcs/make_str_with_precision_for_any.c \
		srcs/none_infinity.c \
		srcs/o_flags.c \
		srcs/o_flags1.c \
		srcs/parsing_and_flags.c \
		srcs/pf_printf.c \
		srcs/preparce_for_flags.c \
		srcs/print_float.c \
		srcs/str_calc.c \
		srcs/str_calc_extra.c \
		srcs/u_flags.c \
		srcs/x_flags.c \
		srcs/x_flags1.c \
		srcs/c_ft_itoa.c \
		srcs/c_ft_memalloc.c \
		srcs/c_ft_strdup.c \
		srcs/c_ft_strjoin.c \
		srcs/c_ft_strnew.c \
		srcs/c_ft_strsplit.c \
		srcs/c_ft_strsub.c \
		srcs/c_get_next_line.c
OBJS=$(SRCS:srcs%.c=objs%.o)
SRCS_DIR = srcs/
OBJS_DIR = objs/
INCLUDES = includes/
HEADERS = $(addprefix $(INCLUDES),libft.h ft_printf.h collector.h)
FLAGS = -Wall -Wextra -Werror
NO_COLOR=\x1b[0m
OK_COLOR=\x1b[32;01m
ERROR_COLOR=\x1b[31;01m
WARN_COLOR=\x1b[33;01m
COMPILING_STRING=$(OK_COLOR)[LIBFT.A COMPILED]$(NO_COLOR)
REMOVE_ALL_STRING=$(ERROR_COLOR)[LIBFT.A REMOVED]$(NO_COLOR)
REMOVE_O_STRING=$(WARN_COLOR)[.O LIBFT FILES REMOVED]$(NO_COLOR)
ECHO=echo

all: $(NAME)

write:
	@echo $(HEADERS)

$(NAME): $(OBJS)
	@$(ECHO) "$(COMPILING_STRING)"
	@ar rc $(NAME) $(OBJS)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c $(INCLUDES) $(HEADERS)
	gcc -c -g $< -I $(INCLUDES) -o $@

clean:
	@$(ECHO) "$(REMOVE_O_STRING)"
	@rm -f $(OBJS)

fclean: clean
	@$(ECHO) "$(REMOVE_ALL_STRING)"
	@rm -f $(NAME)

re: fclean all
