TARGET   = logger-sample

CXX      = g++

INCDIR   = include
SRCDIR   = src
OBJDIR   = obj

CFLAGS   = -Wall -std=c++11 -O0 -I$(INCDIR)/
LDFLAGS	 = -lpthread

INCLUDES := $(wildcard $(INCDIR)/*.h)
SOURCES  := $(wildcard $(SRCDIR)/*.cpp)
OBJECTS  := $(SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

build: $(TARGET)

$(TARGET): $(OBJECTS)
	@mkdir -p $(dir $@)
	@$(CXX) -o $@ $(CFLAGS) $(OBJECTS) $(LDFLAGS)
	@echo "Compilation complete!"

$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.cpp $(INCLUDES)
	@mkdir -p $(dir $@)
	@$(CXX) $(CFLAGS) -c $< -o $@
	@echo "Compiled "$<" successfully."

.PHONY: build clean
clean:
	@rm -Rf $(OBJDIR)
	@echo "Cleanup complete."
