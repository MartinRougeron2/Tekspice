NAME	= nanotekspice

CC	= g++

RM	= rm -f

SRCS	= ./commands.cpp \
	  ./Exceptions.cpp \
	  ./components.cpp \
	  ./create_chipset.cpp \
	  ./Pin.cpp \
	  ./pin_gate.cpp \
	  ./read_config.cpp \
	  ./terminal.cpp

MAIN = ./main.cpp

MAIN_TEST = ./test_unit/main.cpp

SRCS_TESTS = test_unit/*.cpp

OBJS	= $(SRCS:.cpp=.o)

OBJS_TEST = $(SRCS_TESTS:.cpp=.o)

MAIN_OBJS	= $(MAIN:.cpp=.o)

MAIN_OBJS_TEST = $(MAIN_TESTS:.cpp=.o)

CPPFLAGS = -I ./pp -O0 -g3
CPPFLAGS += -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS) $(MAIN_OBJS)
	$(CC) $(OBJS) $(MAIN_OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

test: $(OBJS_TEST) $(OBJS) $(MAIN_OBJS_TEST)
	$(CC) $(OBJS_TEST) $(OBJS) $(MAIN_OBJS_TEST) -o test -lgtest -lgtest_main

.PHONY: all clean fclean re
