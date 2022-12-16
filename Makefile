CC=g++
CFLAGS=-g -Wall

SRCDIR=src
HEADERDIR=include
BINDIR=bin
LIBDIR=lib
OBJDIR=obj
BIN=$(BINDIR)/main

SRCS=$(wildcard $(SRCDIR)/*.cpp)
OBJS=$(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SRCS))
LIBS=$(LIBDIR) -l sfml-graphics -l sfml-window -l sfml-system -l sfml-audio

all:$(BIN)

release: CFLAGS=-O2 -DNDEBUG
release: clean
release:$(BIN)


#Link .o files and sfml lib files
$(BIN): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@ -L $(LIBS)

#Compile .cpp files
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CC) $(CFLAGS) -I $(HEADERDIR) -c $< -o $@

#Run exe
run:
	$(BIN)

#Clean obj dir
clean:
	powershell rm -r $(OBJDIR)/*.o
