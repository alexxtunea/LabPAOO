#include "Book.h"
#include <iostream>
#include <utility>

Book::Book(std::string title, std::string author, int year)
    : title(std::move(title)), author(std::move(author)), year(year) {}

const std::string& Book::getTitle() const { return title; }
void Book::setTitle(const std::string& newTitle) { title = newTitle; }

void Book::print() const {
    std::cout << "  \"" << title << "\" - " << author << " (" << year << ")\n";
}
