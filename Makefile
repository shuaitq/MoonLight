PROJECT = MoonLight
CPP = g++
CPPFLAGS = -std=c++11 -Wall -lpthread
ifdef DEBUG
CPPFLAGS += -g
else
CPPFLAGS += -O2
endif
SRCS = MoonLight.cpp Tracer/Tracer.cpp

OBJS = $(SRCS:.cpp=.o)

$(PROJECT): $(OBJS)
	$(CPP) $(CPPFLAGS) -o $@ $^

%.o: %.cpp
	$(CPP) $(CPPFLAGS) -c -o $@ $<

.PHONY: clean
clean:
	rm -f $(OBJS)