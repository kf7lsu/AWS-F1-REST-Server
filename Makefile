CC := g++
LIBS := $(shell curl-config --libs)
CFLAGS := $(shell curl-config --cflags)

all: main.out

main.out: main.cpp BaseRestClient.o BaseRestClient.h
	@echo "Using" $(shell curl-config --version)
	curl-config --checkfor 7.56 && $(CC) main.cpp BaseRestClient.o $(CFLAGS) $(LIBS) -o main.out

BaseRestClient.o: BaseRestClient.cpp BaseRestClient.h Config.cpp
	@echo "Using" $(shell curl-config --version)
	curl-config --checkfor 7.56 && $(CC) -c BaseRestClient.cpp $(CFLAGS) $(LIBS)

clean:
	rm *.out *.o
