# Add executable
add_executable(ocr main.cpp)
find_package(OpenCV REQUIRED)

# Include directories
include_directories (/usr/include/tesseract)
# Link directories
find_package(YARP REQUIRED)
link_directories (/usr/lib)
# Target link libraries
target_link_libraries (ocr lept tesseract)
target_link_libraries(ocr ${OpenCV_LIBS})
target_link_libraries(ocr ${YARP_LIBRARIES})
