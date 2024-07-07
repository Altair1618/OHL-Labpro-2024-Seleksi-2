# Define compiler
JAVAC=javac

# Define source files
SOURCES=LinkedList.java Node.java Main.java

# Define class files (output)
CLASSES=$(SOURCES:.java=.class)

# Default target
all: build run

build: $(CLASSES)

# Compile source files
%.class: %.java
	$(JAVAC) $<

# Clean up
clean:
	@rm -f $(CLASSES)

# Run the program
run: 
	java Main