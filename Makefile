CXX = g++

INCDIR = include
SRCDIR = src
OBJDIR = obj
TARGETDIR = lib

CFLAGS = -Wall -std=c++11 -O3 -march=native -I$(INCDIR)/

INCLUDES := $(wildcard $(INCDIR)/*.h)
SOURCES := $(wildcard $(SRCDIR)/*.cpp)
OBJECTS := $(SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

build: static

$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.cpp $(INCLUDES)
	@mkdir -p $(dir $@)
	@echo -n "Compiling "$<"... "
	@$(CXX) $(CFLAGS) -c $< -o $@
	@echo "DONE"

static: $(OBJECTS)
	@mkdir -p $(TARGETDIR)
	@ar rcs $(TARGETDIR)/liblogger.a $(OBJECTS)
	@echo "$(TARGETDIR)/liblogger.a compilation completed."

.PHONY: build clean
clean:
	@rm -Rf $(OBJDIR)
	@echo "Cleanup complete."
