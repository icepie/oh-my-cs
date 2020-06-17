ifeq ($(OS),Windows_NT)
 CCFLAGS += -D WIN32
 CLEANC=del /Q /F *.o stums*
 ifeq ($(PROCESSOR_ARCHITECTURE),AMD64)
 CCFLAGS += -D AMD64
 endif
 ifeq ($(PROCESSOR_ARCHITECTURE),x86)
 CCFLAGS += -D IA32
 endif
else
 CLEANC=rm -rf *.o stums*
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

CC = g++
CPPFLAGS+=-w

all: main
	@echo OS: $(CCFLAGS)

main: main.cpp  class.o function.o 
	$(CC) main.cpp class.o function.o $(CPPFLAGS) -o stums

function: function.cpp
	$(CC)  -c $(CPPFLAGS) function.cpp

class: class.cpp 
	$(CC)  -c $(CPPFLAGS) class.cpp

clean: 
	@echo Cleaning... 
	$(CLEANC)
	@echo Done!