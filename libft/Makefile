NAME 	= libft.a
CC 		= gcc
AR 		= ar rcs
CFLAGS	= -Wall -Wextra -Werror

define LOADING_BAR_COMP
	@printf "\033[0;32mCompiling LIBFT: ["
	@for i in `seq 1 20`; do \
		printf "█"; \
		sleep 0.02; \
	done; \
	printf "] ✔️\033[0m\n\n"
endef

define LOADING_BAR_CLEAN
    @printf "\033[0;31mCleaning LIBFT: ["
    @for i in `seq 1 20`; do \
        printf "█"; \
        sleep 0.02; \
    done; \
    printf "] ✔️\033[0m\n\n"
endef

SRC = ft_isalpha.c \
	ft_isdigit.c \
	ft_isalnum.c \
	ft_isascii.c \
	ft_isprint.c \
	ft_strlen.c \
	ft_memset.c \
	ft_bzero.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_strlcpy.c \
	ft_strlcat.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_strncmp.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_strnstr.c \
	ft_atoi.c \
	ft_calloc.c \
	ft_strdup.c \
	ft_substr.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_split.c \
	ft_itoa.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putnbr_fd.c \
	ft_putendl_fd.c \
	ft_striteri.c \
	ft_strmapi.c \
	ft_printf_handlers.c \
	ft_printf_utils.c \
	ft_printf.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(AR) $(NAME) $(OBJ)
	$(call LOADING_BAR_COMP)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)
	$(call LOADING_BAR_CLEAN)

fclean: clean 
	 @rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean recd