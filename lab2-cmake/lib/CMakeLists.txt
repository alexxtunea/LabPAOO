project(carti LANGUAGES CXX)

add_library(carti STATIC src/carti.cpp)
target_include_directories(carti PUBLIC include)
