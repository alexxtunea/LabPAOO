#pragma once
#include "Book.h"
#include "Uncopyable.h"
#include <string>

class LibraryCard : private Uncopyable {
public:
    explicit LibraryCard(std::string owner);
    void borrow(const Book& book);
    void print() const;

private:
    std::string owner;
    int borrowed = 0;  // Item 4: initializare implicita a membrului, valabila pentru orice constructor
};
