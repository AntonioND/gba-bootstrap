# SPDX-License-Identifier: CC0-1.0
#
# SPDX-FileContributor: Antonio Niño Díaz, 2022

NAME		:= gbafix

CC		:= gcc
RM		:= rm -rf

# `make V=` builds the binary in verbose build mode
V		:= @

CFLAGS		:= -Wall -O3

.PHONY: all clean

all: $(NAME)

$(NAME): gbafix.c
	@echo "  HOSTCC  $<"
	$(V)$(CC) $(CFLAGS) -o $@ $<

clean:
	@echo "  CLEAN"
	$(V)$(RM) $(NAME)
