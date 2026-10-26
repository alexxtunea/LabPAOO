project(app LANGUAGES CXX)

add_executable(lab2 main.cpp)
target_link_libraries(lab2 PRIVATE carti)
