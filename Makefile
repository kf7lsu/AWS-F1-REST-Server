CC := g++
OPTIONS := $(shell curl-config --libs)
CFLAGS := $(shell curl-config --cflags)

all: a.out

a.out: predict.c
	@echo "Using" $(shell curl-config --version)
	curl-config --checkfor 7.56 && $(CC) predict.c $(CFLAGS) $(OPTIONS)

clean:
	rm *.out
