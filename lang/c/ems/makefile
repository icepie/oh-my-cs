ifeq ($(OS),Windows_NT)
 CCFLAGS += -D WIN32
 CLEANC=del /Q /F *.o ems*
 ifeq ($(PROCESSOR_ARCHITECTURE),AMD64)
 CCFLAGS += -D AMD64
 endif
 ifeq ($(PROCESSOR_ARCHITECTURE),x86)
 CCFLAGS += -D IA32
 endif
else
 CLEANC=rm -rf *.o ems*
 UNAME_S := $(shell uname -s)
 ifeq ($(UNAME_S),Linux)
 CCFLAGS += -D LINUX
 endif
 ifeq ($(UNAME_S),Darwin)
 CCFLAGS += -D OSX
 endif
 UNAME_P := $(shell uname -p)
 ifeq ($(UNAME_P),x86_64)
 CCFLAGS += -D AMD64
 endif
 ifneq ($(filter %86,$(UNAME_P)),)
 CCFLAGS += -D IA32
 endif
 ifneq ($(filter arm%,$(UNAME_P)),)
 CCFLAGS += -D ARM
 endif
endif

CC = gcc
CPPFLAGS+=-w

all: main
	@echo OS: $(CCFLAGS)

main: main.c  input.o mod.o menus.o search_sort.o del.o view.o
	$(CC) main.c input.o mod.o menus.o search_sort.o del.o view.o $(CPPFLAGS) -o ems

input: input.c
	$(CC)  -c $(CPPFLAGS) input.c

mod: mod.c
	$(CC)  -c $(CPPFLAGS) mod.c

menus: menus.c
	$(CC)  -c $(CPPFLAGS) menus.c

search_sort: search_sort.c
	$(CC)  -c $(CPPFLAGS) search_sort.c

del: del.c
	$(CC)  -c $(CPPFLAGS) del.c

view: view.c
	$(CC)  -c $(CPPFLAGS) view.c

clean: 
	@echo Cleaning... 
	$(CLEANC)
	@echo Done!