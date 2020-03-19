CXX      := emcc
CXXFLAGS := -std=c++11 #-pedantic-errors -Wall -Wextra
LDFLAGS  := -std=c++11 
BUILD    := ./bin
SRC_DIR      := src
OBJ_DIR  := $(BUILD)/objects
APP_DIR  := $(BUILD)/apps
JGE_DIR  := ..
TARGET   := index.js
INCLUDE := -I$(JGE_DIR)/include 
EMCC_FLAGS  := -s WASM=1 -s USE_SDL=2 -s USE_SDL_MIXER=2 -s USE_LIBPNG=1 -s ALLOW_MEMORY_GROWTH=1 --use-preload-plugins --preload-file $(BUILD)/assets@/ 
LIBS 	 := $(JGE_DIR)/build/lib/libjge.a

SOURCES := $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS := $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SOURCES))

all: build $(APP_DIR)/$(TARGET)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(EMCC_FLAGS) $(INCLUDE) -o $@ -c $<

$(APP_DIR)/$(TARGET): $(OBJECTS) $(LIBS) shaders
	@mkdir -p $(@D)
	$(CXX) $(OBJECTS) $(LDFLAGS) $(EMCC_FLAGS) $(LIBS) -o $(APP_DIR)/$(TARGET)

.PHONY: all build clean debug release

build:
	@mkdir -p $(APP_DIR)
	@mkdir -p $(OBJ_DIR)

debug: EMCC_FLAGS += -g4 --source-map-base -v -s ASSERTIONS=1  -s SAFE_HEAP=1 -s STACK_OVERFLOW_CHECK=1 -s DEMANGLE_SUPPORT=1 -s SOCKET_DEBUG=1
debug: all

release: EMCC_FLAGS += -O3
release: all

clean:
	-@rm -rvf $(OBJ_DIR)/*

shaders:
	cp -a $(JGE_DIR)/shaders/. $(BUILD)/assets/

server:
	cd $(APP_DIR) && python3 -m http.server 80