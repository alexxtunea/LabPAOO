add_library(biblioteca STATIC src/Book.cpp src/Catalog.cpp src/Loan.cpp src/LibraryCard.cpp)
target_include_directories(biblioteca PUBLIC include)
