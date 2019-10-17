INCLUDE_DIR=./include
CXXFLAGS=-Wall -Werror -O3 -I$(INCLUDE_DIR)
VPATH=./src

TARGETS=parabolic_battle

DEPENDENCIES=main.cpp canvas.cpp system.cpp map.cpp object.cpp

build: $(TARGETS)

$(TARGETS): $(DEPENDENCIES) -lSDL2
	$(CXX) $(CXXFLAGS) -o $@ $^

.PHONY: clean
clean:
	-rm -f $(TARGETS)
