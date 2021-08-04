TARGET := tp1
LIBS := -lm
CFLAGS := -g -O3 -Wno-unused-result
#CFLAGS := -g -O3 
OBJDIR := obj/
SRCDIR := src/
INCLUDEDIR := include/
INCLUDE_PATHS := -Iinclude
CLI := client/main.c
CC := gcc

all: $(TARGET)

SRC = $(wildcard $(SRCDIR)*.c)
HEADERS = $(wildcard $(INCLUDEDIR)*.h)

CLIENT = $(OBJDIR)$(basename $(notdir $(CLI)))

OBJECTS := $(SRC:$(SRCDIR)%.c=$(OBJDIR)%.o)
OBJECTS += $(CLIENT).o

$(OBJDIR)%.o: $(SRCDIR)%.c $(HEADERS)
	@ mkdir -p $(OBJDIR)
	$(CC) $(INCLUDE_PATHS) $(CFLAGS) -c -o $@ $<

$(CLIENT).o: $(CLI)
	$(CC) $(INCLUDE_PATHS) $(CFLAGS) -c -o $@ $<


$(TARGET): $(OBJECTS)
	$(CC) $(INCLUDE_PATHS) $(OBJECTS) $(LIBS) -o $@

clean:
	-rm -f -r obj
	-rm -f *.o
	-rm -f $(TARGET)
	
test:
	./tp1 10 z-inputs/Entrada/acoustic-hits.txt z-inputs/Entrada/eletrica.txt z-inputs/Entrada/eletronica.txt z-inputs/Entrada/heavymetal.txt z-inputs/Entrada/metal.txt z-inputs/Entrada/nacional.txt z-inputs/Entrada/sert.txt z-inputs/Entrada/sertanejo.txt z-inputs/Entrada/playlists.txt z-inputs/Entrada/amizade.txt