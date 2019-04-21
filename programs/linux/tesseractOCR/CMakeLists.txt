# tesseractOCR
add_executable(tesseractOCR main.cpp)
find_package(OpenCV REQUIRED)
# Include directories
include_directories (/usr/include/tesseract)
# Link directories
find_package(YARP REQUIRED)
link_directories (/usr/lib)
# Target link libraries
target_link_libraries (tesseractOCR lept tesseract)
target_link_libraries(tesseractOCR ${OpenCV_LIBS})
target_link_libraries(tesseractOCR ${YARP_LIBRARIES})
