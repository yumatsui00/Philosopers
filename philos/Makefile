CC = cc
CCFLAGS = -Wall -Wextra -Werror
DEBUG = -g -fsanitize=address
DEBUG2 = -g -fsanitize=thread

SRCDIR = srcs/
OBJDIR = objs

SRCS =	srcs/main.c srcs/life/angel.c srcs/life/philo.c srcs/life/reaper.c srcs/utils/argcheck.c \
		srcs/utils/ft_atoi.c srcs/utils/ft_time.c srcs/utils/init.c srcs/utils/write.c
OBJS = $(SRCS:$(SRCDIR)%.c=$(OBJDIR)/%.o)

TARGET = philo
TARGET1 = debug
TARGET2 = thread

all: $(TARGET)
	@echo $(BRIGHT_RED)$(BOLD)╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱
	@echo ╱╱╱╱╭━━━╮╱╭╮╱╱╱╭╮╱╭╮╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╭╮╱╱╱╱╱╱╱╱╱╱╱╱╭━━━╮╱╱╱╱╱
	@echo ╱╱╱╱┃╭━╮┃╱┃┃╱╱╱╰╯╱┃┃╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱┃┃╱╱╱╱╱╱╱╱╱╱╱╱┃╭━╮┃╱╱╱╱╱
	@echo ╱╱╱╱┃╰━╯┃╱┃╰━╮╱╭╮╱┃┃╱╱╭━━╮╱╭━━╮╱╭━━╮╱╭━━╮╱┃╰━╮╱╭━━╮╱╭━╮╱┃╰━━╮╱╱╱╱╱
	@echo ╱╱╱╱┃╭━━╯╱┃╭╮┃╱┃┃╱┃┃╱╱┃╭╮┃╱┃━━┫╱┃╭╮┃╱┃╭╮┃╱┃╭╮┃╱┃┃━┫╱┃╭╯╱╰━━╮┃╱╱╱╱╱
	@echo ╱╱╱╱┃┃╱╱╱╱┃┃┃┃╱┃┃╱┃╰╮╱┃╰╯┃╱┣━━┃╱┃╰╯┃╱┃╰╯┃╱┃┃┃┃╱┃┃━┫╱┃┃╱╱┃╰━╯┃╱╱╱╱╱
	@echo ╱╱╱╱╰╯╱╱╱╱╰╯╰╯╱╰╯╱╰━╯╱╰━━╯╱╰━━╯╱╰━━╯╱┃╭━╯╱╰╯╰╯╱╰━━╯╱╰╯╱╱╰━━━╯╱╱╱╱╱
	@echo ╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╰╯╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱
	@echo ╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱

debug: $(TARGET1)

thread: $(TARGET2)

$(TARGET): $(OBJS)
	$(CC) $(CCFLAGS) -o $@ $^
	@echo

$(TARGET1): $(OBJS)
	@echo $(BRIGHT_YELLOW)
	$(CC) $(CCFLAGS) $(DEBUG) -o $@ $^
	@echo
	@echo FSANITIZE=ADDRESS DONE

$(TARGET2): $(OBJS)
	@echo $(BRIGHT_YELLOW)
	$(CC) $(CCFLAGS) $(DEBUG2) -o $@ $^
	@echo
	@echo FSANITIZE=THREAD DONE

$(OBJDIR):
	@echo $(GREEN)
	@mkdir -p $(OBJDIR)
	@mkdir -p $(OBJDIR)/life
	@mkdir -p $(OBJDIR)/utils

$(OBJDIR)/%.o: $(SRCDIR)%.c | $(OBJDIR)
	$(CC) $(CCFLAGS) -o $@ -c $<

clean:
	@rm -rf $(OBJDIR)
	@echo $(BRIGHT_MAGENTA)
	@echo ╭━╮╭╮╱╭━╮╭━━╮╭━┳╮╭━┳╮╭━━╮╭━┳╮╭━━╮
	@echo ┃╭╯┃┃╱┃┳╯┃╭╮┃┃┃┃┃┃┃┃┃╰┃┃╯┃┃┃┃┃╭━┫
	@echo ┃╰╮┃╰╮┃┻╮┃┣┫┃┃┃┃┃┃┃┃┃╭┃┃╮┃┃┃┃┃╰╮┃╭╮╭╮╭╮
	@echo ╰━╯╰━╯╰━╯╰╯╰╯╰┻━╯╰┻━╯╰━━╯╰┻━╯╰━━╯╰╯╰╯╰╯

fclean:
	@rm -rf $(OBJDIR)
	@rm -f $(TARGET) $(TARGET1) $(TARGET2)
	@echo $(RED)╭━━━╮$(BRIGHT_MAGENTA)
	@echo $(RED)┃╭━━╯$(BRIGHT_MAGENTA)
	@echo $(RED)┃╰━━╮$(BRIGHT_MAGENTA) ╭━╮╭╮╱╭━╮╭━━╮╭━┳╮╭━┳╮╭━━╮╭━┳╮╭━━╮
	@echo $(RED)┃╭━━╯$(BRIGHT_MAGENTA) ┃╭╯┃┃╱┃┳╯┃╭╮┃┃┃┃┃┃┃┃┃╰┃┃╯┃┃┃┃┃╭━┫
	@echo $(RED)┃┃ $(BRIGHT_MAGENTA) ╱╱┃╰╮┃╰╮┃┻╮┃┣┫┃┃┃┃┃┃┃┃┃╭┃┃╮┃┃┃┃┃╰╮┃╭╮╭╮╭╮
	@echo $(RED)╰╯ $(BRIGHT_MAGENTA)╱╱ ╰━╯╰━╯╰━╯╰╯╰╯╰┻━╯╰┻━╯╰━━╯╰┻━╯╰━━╯╰╯╰╯╰╯

re: fclean all

.PHONY: all clean fclean re

# color
RESET = "\033[0m"
# 標準色
BLACK = "\033[30m"
RED = "\033[31m"
GREEN = "\033[32m"
YELLOW = "\033[33m"
BLUE = "\033[34m"
MAGENTA = "\033[35m"
CYAN = "\033[36m"
WHITE = "\033[37m"
# 明るい色
BRIGHT_BLACK = "\033[90m"
BRIGHT_RED = "\033[91m"
BRIGHT_GREEN = "\033[92m"
BRIGHT_YELLOW = "\033[93m"
BRIGHT_BLUE = "\033[94m"
BRIGHT_MAGENTA = "\033[95m"
BRIGHT_CYAN = "\033[96m"
BRIGHT_WHITE = "\033[97m"
# 背景色
BG_RED = "\033[41m"
BG_GREEN = "\033[42m"
BG_BLUE = "\033[44m"
BG_WHITE = "\033[47m"
# テキスト属性
BOLD = "\033[1m"
UNDERLINE = "\033[4m"
REVERSE = "\033[7m"

coffee:
	@echo ""
	@echo "                   ("
	@echo "	                     )     ("
	@echo "               ___...(-------)-....___"
	@echo '           .-""       )    (          ""-.'
	@echo "      .-''''|-._             )         _.-|"
	@echo '     /  .--.|   `""---...........---""`   |'
	@echo "    /  /    |                             |"
	@echo "    |  |    |                             |"
	@echo "     \  \   |                             |"
	@echo "      '\ '\ |                             |"
	@echo "        '\ '|                             |"
	@echo "        _/ /\                             /"
	@echo "       (__/  \                           /"
	@echo '    _..---""` \                         /`""---.._'
	@echo " .-'           \                       /          '-."
	@echo ":               '-.__             __.-'              :"
	@echo ':                  ) ""---...---"" (                :'
	@echo "\'._                '"--...___...--"'              _.'"
	@echo '   \""--..__                              __..--""/'
	@echo "     '._     """----.....______.....----"""         _.'"
	@echo '         ""--..,,_____            _____,,..--"""'''
	@echo '                      """------"""'
