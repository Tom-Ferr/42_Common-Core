.DEFAULT_GOAL	:= a
UTILS			= $(addprefix utils/, sigsegv.cpp color.cpp check.cpp leaks.cpp)
TESTS_PATH		= tests/
MANDATORY		= memset bzero memcpy memccpy memmove memchr memcmp strlen isalpha isdigit isalnum \
				isascii isprint toupper tolower strchr strrchr strncmp strlcpy strlcat strnstr \
				atoi calloc strdup substr strjoin strtrim split itoa strmapi putchar_fd putstr_fd \
				putendl_fd putnbr_fd
BONUS			= lstnew lstadd_front lstsize lstlast lstadd_back lstdelone lstclear lstiter lstmap
VSOPEN			= $(addprefix vs, $(MANDATORY)) $(addprefix vs, $(BONUS))
MAIL			= $(addprefix send, $(MANDATORY)) $(addprefix send, $(BONUS))

CC		= clang++
CFLAGS	= -g3 -ldl -std=c++11 -I utils/ -I..

UNAME = $(shell uname -s)
ifeq ($(UNAME), Linux)
	VALGRIND = valgrind -q --leak-check=full
endif

$(MANDATORY): %: mandatory_start
	@$(CC) $(CFLAGS) $(UTILS) $(TESTS_PATH)ft_$*_test.cpp -L.. -lft && $(VALGRIND) ./a.out && rm -f a.out

$(BONUS): %: bonus_start
	@$(CC) $(CFLAGS) $(UTILS) $(TESTS_PATH)ft_$*_test.cpp -L.. -lft && $(VALGRIND) ./a.out && rm -f a.out

$(VSOPEN): vs%:
	@code $(TESTS_PATH)ft_$*_test.cpp

$(MAIL): send%:
	cat ../ft_$*.c | mail -s "libftTester Improvement $*" jgambard@student.42lyon.fr

mandatory_start: update message
	@tput setaf 6
	make -C ..
	@tput setaf 4 && echo [Mandatory]

bonus_start: update message
	@tput setaf 6
	make bonus -C ..
	@tput setaf 5 && echo [Bonus]

update:
	@git pull

message: checkmakefile
	@tput setaf 3 && echo If all your tests are OK and the moulinette KO you, please send an email with make sendfunction ex: make sendsubstr

checkmakefile:
	@ls .. | grep Makefile > /dev/null 2>&1 || (tput setaf 1 && echo Makefile not found. && exit 1)

$(addprefix docker, $(MANDATORY)) $(addprefix docker, $(BONUS)) dockerm dockerb dockera: docker%:
	@docker rm -f mc > /dev/null 2>&1 || true
	docker build -qt mi .
	docker run -dti --name mc -v $(shell dirname $(shell pwd)):/project/ mi
	docker exec -ti mc make $* -C libftTester || true
	@docker rm -f mc > /dev/null 2>&1

m: $(MANDATORY)
b: $(BONUS)
a: m b 

clean:
	make clean -C .. && rm -rf a.out*

fclean:
	make fclean -C .. && rm -rf a.out*

.PHONY:	mandatory_start m bonus_start b a fclean clean update message $(VSOPEN) $(MAIL)