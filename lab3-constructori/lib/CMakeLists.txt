add_library(biblioteca STATIC src/Book.cpp src/Library.cpp)
target_include_directories(biblioteca PUBLIC include)
