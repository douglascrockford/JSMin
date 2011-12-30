# Application name
JSMIN = jsmin

# Source files
jsmin_SOURCES = jsmin.c

# Preprocessor flags
jsmin_CPPFLAGS =

# Compiler flags
jsmin_CFLAGS = -g -O2 -Wall -Wextra

# Linker flags
jsmin_LDFLAGS =

# Object files
jsmin_OBJECTS = $(jsmin_SOURCES:%.c=%.o)

# Installation prefix
prefix = /usr/local

# Application installation directory
bindir = $(prefix)/bin

all: $(JSMIN)

%.o: %.c
	$(quiet_CC)$(CC) $(CPPFLAGS) $(jsmin_CPPFLAGS) $(CFLAGS) $(jsmin_CFLAGS) -o $@ -c $<

$(JSMIN): $(jsmin_OBJECTS)
	$(quiet_LINK)$(CC) $(jsmin_OBJECTS) -o $@ $(LDFLAGS) $(jsmin_LDFLAGS)

install: $(JSMIN)
	$(quiet_INSTALL)install -t $(bindir) $<

uninstall:
	rm -f $(bindir)/$(JSMIN)

clean:
	rm -f $(JSMIN) $(jsmin_OBJECTS)

.PHONY: all clean install uninstall

# Quiet by default
VERBOSE ?= 0

# Printf macro for "quiet_" macros
quiet__v_printf = @printf "  %-8s%s\n"

# Quiet C compiler
quiet_CC = $(quiet__v_CC_$(V))
quiet__v_CC_ = $(quiet__v_CC_$(VERBOSE))
quiet__v_CC_0 = $(quiet__v_printf) CC $(@F);

# Quiet linker
quiet_LINK = $(quiet__v_LINK_$(V))
quiet__v_LINK_ = $(quiet__v_LINK_$(VERBOSE))
quiet__v_LINK_0 = $(quiet__v_printf) LINK $(@F);

# Quiet install
quiet_INSTALL = $(quiet__v_INSTALL_$(V))
quiet__v_INSTALL_ = $(quiet__v_INSTALL_$(VERBOSE))
quiet__v_INSTALL_0 = $(quiet__v_printf) INSTALL $<;
