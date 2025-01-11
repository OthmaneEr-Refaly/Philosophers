White 	= \e[0;30m
Yellow 	= \x1b[33m
Red	= \e[0;31m
Blue	= \e[0;34m
Green 	= \033[1;32m
RESET 	= \033[0m

NAME	 = philo
COMPILER = cc
FLAGS	 =  -Wall -Werror -Wextra -g3 -fsanitize=address
FLAGS	 =  -g3
SRCS	 = src/philo.c \
	src/data/init_data.c src/data/init_forks.c src/data/threads.c  \
	src/GarbegCollector/gc.c \
	src/GettersAndSetters/g_setters.c src/GettersAndSetters/g_s2.c \
	src/Parsing/is_valid_input.c \
	src/Print/print.c \
	src/Routine/eat.c src/Routine/eat2.c src/Routine/routine.c \
	src/Sleep/sleep.c \
	src/Think/think.c \
	src/Time/time.c src/Time/time2.c \
	src/Tools/tools.c \


OBJS	 = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(COMPILER) $(FLAGS) $(OBJS) -o $(NAME) $(READLINE)
%.o: %.c
	@$(COMPILER) $(FLAGS) -c $< -o $@
	@echo "$(Red) [!] Compiling File Named $< In Progress \n"
	@echo "$(Green) [✔] Compilation Complete ... !$(RESET)"
	@echo "\n"
clean:
	@rm -rf $(OBJS)
fclean:
	@rm -rf $(OBJS) $(NAME)
re: fclean all
