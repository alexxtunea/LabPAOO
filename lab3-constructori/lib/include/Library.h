#pragma once
#include "Book.h"
#include <vector>

class Library {
public:
    void add(Book book);
    void print() const;

private:
    std::vector<Book> books;
};
