##		TEXT COLOR			##
C_RESET				:= \033[0m
C_PENDING			:= \033[0;36m
C_SUCCESS			:= \033[0;32m

##		TARGET EXEC			##
NAME	=	main

##		COMPIL FLAGS		##
C++		=	c++
FLAGS	=	-Wall -Werror -Wextra
STD		=	-std=c++98

##		DIRECTORY			##
HEADIR	=	heads
SRCDIR	=	sources
OBJDIR	=	obj

##		SOURCES				##
HEADFILES	=	Literal.hpp

SRCFILES	=	Literal.cpp

##		INCLUDE FILES		##
HEAD	=	$(HEADFILES:%=$(HEADIR)/%)

##		SOURCE FILES		##
SRCS	=	$(SRCFILES:%=$(SRCDIR)/%)

##		OBJECT FILES		##
OBJS	=	$(SRCFILES:%.cpp=$(OBJDIR)/%.o)
OBJS	+=	$(OBJDIR)/main.o

#	#	#	RULES	#	#	#

all		:	$(NAME)

$(NAME)	:	$(HEAD) obj $(OBJS)
			@echo -n "--  "
			$(C++) $(FLAGS) $(STD) -o $@ $(OBJS)
			@echo "$(C_SUCCESS)🮱   Compilation done !$(C_RESET)"

obj		:
			@mkdir obj

$(OBJDIR)/main.o	:	main.cpp
			@echo -n "--  "
			$(C++) $(FLAGS) $(STD) -c $^ -o $@

$(OBJDIR)/%.o	:	$(SRCDIR)/%.cpp
			@echo -n "--  "
			$(C++) $(FLAGS) $(STD) -c $^ -o $@

clean	:
			@echo "$(C_PENDING)⌛  Cleaning sources...$(C_RESET)"
			@rm -rf $(OBJDIR)
			@rm -rf vgcore.*

fclean	:	clean
			@echo "$(C_PENDING)⌛  Cleaning executable...$(C_RESET)"
			@rm -rf $(NAME)

re		:	fclean all