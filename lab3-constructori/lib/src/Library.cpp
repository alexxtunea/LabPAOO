#include "Library.h"
#include <iostream>
#include <utility>

void Library::add(Book book) {
    books.push_back(std::move(book));
}

void Library::print() const {
    std::cout << "Biblioteca are " << books.size() << " carti:\n";
    for (const Book& b : books)
        b.print();
}
