CC := g++
OPTIONS := $(shell curl-config --libs)

all: a.out

a.out: predict.c
	curl-config --checkfor 7.56
	$(CC) predict.c $(OPTIONS)

clean:
	rm *.out
