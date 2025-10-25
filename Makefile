CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g
TARGET = number_guesser
SRCDIR = NumGuesser
OBJDIR = obj

SOURCES = $(SRCDIR)/main.c \
          $(SRCDIR)/UserInput.c \
          $(SRCDIR)/RNG_Module.c \
          $(SRCDIR)/FileHandling.c \
          $(SRCDIR)/Scoring.c

OBJECTS = $(SOURCES:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

$(shell mkdir -p $(OBJDIR))

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(TARGET)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR) $(TARGET) *.txt

test: $(TARGET)
	./$(TARGET) test_save.txt

.PHONY: all clean test
