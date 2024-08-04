# Define the Build directory and executable name 
BUILD_DIR := build
EXECUTABLE := brompton 
DOCS_DIR := docs

# Determine the operating system
UNAME_S := $(shell uname -s)

# Define the target all
all: $(BUILD_DIR)/Makefile
	$(MAKE) -C $(BUILD_DIR)

# Generate the Makefile using CMake
$(BUILD_DIR)/Makefile:
	@mkdir -p $(BUILD_DIR)
	cmake -S . -B $(BUILD_DIR) 

# Run tests using CTest
test: all
	$(MAKE) -C $(BUILD_DIR) test

# Create the updated documentation 
# Open the html documentaion on the broswer
docs:
	doxygen Doxyfile
	@echo "Documentation generated."

	# Open the HTML documentation based on the OS
	@if [ "$(UNAME_S)" = "Linux" ]; then \
		xdg-open docs/html/index.html; \
	elif [ "$(UNAME_S)" = "Darwin" ]; then \
		open docs/html/index.html; \
	elif [ "$(UNAME_S)" = "Windows_NT" ]; then \
		start docs\\html\\index.html; \
	else \
		echo "Unsupported OS: $(UNAME_S)"; \
	fi

# Clean the build directory
clean:
	@rm -rf $(BUILD_DIR) $(DOCS_DIR) 

.PHONY: all test clean docs