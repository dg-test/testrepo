#
# Cross Platform Makefile
# Coded by FL1NE (https://fl1ne.rtx1911.net)
#
#
# You will need GLFW3 (http://www.glfw.org)
# and GLEW (http://glew.sourceforge.net)
#

#CXX = g++

EXE = hogeGL
OBJS = src/main.o

UNAME_S := $(shell uname -s)


ifeq ($(UNAME_S), Linux) #Linux Build
	ECHO_MESSAGE = "Linux"
	LIBS = -lGL `pkg-config --static --libs glfw3` -lglew

	CXXFLAGS = -Isrc/ `pkg-config --cflags glfw3`
	CXXFLAGS += -Wall -Wformat
	CFLAGS = $(CXXFLAGS)
endif


ifeq ($(UNAME_S), Darwin) #Mac OS X Build
	ECHO_MESSAGE = "Mac OS X"
	LIBS = -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo
	LIBS += -L/usr/local/lib -lglfw3 -lglew

	CXXFLAGS = -Isrc/ -I/usr/local/include
	CXXFLAGS += -Wall -Wformat
	CFLAGS = $(CXXFLAGS)
endif


ifeq ($(UNAME_S), MINGW64_NT-6.3) #MinGW Windows (May not work)
	ECHO_MESSAGE = "Windows"
	LIBS = -lglfw3 -lopengl32 -lglew
	#LIBS += -lgdi32 limm32

	CXXFLAGS = -Isrc/ `pkg-config --cflags glfw3`
	CXXFLAGS += -Wall -Wformat
	CFLAGS = $(CXXFLAGS)
endif


.cpp.o:
	$(CXX) $(CXXFLAGS) -c -o $@ $<

all: $(EXE)
	@echo Build complete for $(ECHO_MESSAGE)

$(EXE): $(OBJS)
ifeq ($(UNAME_S), Darwin)
	mkdir -p bin/$(EXE).app/Contents/MacOS
	$(CXX) -o bin/$(EXE).app/Contents/MacOS/$(EXE) $(OBJS) $(CXXFLAGS) $(LIBS)
	ln -sf ./bin/$(EXE).app/Contents/MacOS/$(EXE) $(EXE)
else
	$(CXX) -o bin/$(EXE) $(OBJS) $(CXXFLAGS) $(LIBS)
endif

clean:
ifeq ($(UNAME_S), Darwin)
	rm -r bin/$(EXE).app
	rm $(OBJS) $(EXE)
else
	rm bin/$(EXE) $(OBJS)
endif

