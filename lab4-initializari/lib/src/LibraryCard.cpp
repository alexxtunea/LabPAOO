#include "LibraryCard.h"
#include <iostream>
#include <utility>

LibraryCard::LibraryCard(std::string owner) : owner(std::move(owner)) {}

void LibraryCard::borrow(const Book& book) {
    ++borrowed;
    std::cout << "  " << owner << " a imprumutat \"" << book.getTitle() << "\"\n";
}

void LibraryCard::print() const {
    std::cout << "  Permisul lui " << owner << ": " << borrowed << " carti imprumutate\n";
}
