# Add executable
add_executable(ocr main.cpp)
# Include directories
include_directories (/usr/include/tesseract)
# Link directories
link_directories (/usr/lib)
# Target link libaries
target_link_libraries (ocr lept tesseract)
