#include "Book.h"
#include <cstring>
#include <iostream>
#include <utility>

static char* copyStr(const char* s) {
    char* p = new char[std::strlen(s) + 1];
    std::strcpy(p, s);
    return p;
}

// fara lista de initializare, title/author ar avea adrese random si destructorul ar face delete[] pe ele
Book::Book(const char* title, const char* author, int year)
    : title(copyStr(title)), author(copyStr(author)), year(year) {
    std::cout << "[constructor] " << this->title << "\n";
}

Book::Book(const Book& other)
    : title(copyStr(other.title)), author(copyStr(other.author)), year(other.year) {
    std::cout << "[copy constructor] " << title << "\n";
}

Book::Book(Book&& other) noexcept
    : title(std::exchange(other.title, nullptr)),
      author(std::exchange(other.author, nullptr)),
      year(other.year) {
    std::cout << "[move constructor] " << title << "\n";
}

Book::~Book() {
    std::cout << "[destructor] " << (title ? title : "(obiect mutat)") << "\n";
    delete[] title;
    delete[] author;
}

const char* Book::getTitle() const { return title; }
const char* Book::getAuthor() const { return author; }
int Book::getYear() const { return year; }

void Book::setTitle(const char* newTitle) {
    char* copy = copyStr(newTitle);
    delete[] title;
    title = copy;
}

void Book::print() const {
    if (!title) {
        std::cout << "  (carte goala - resursele au fost mutate)\n";
        return;
    }
    std::cout << "  \"" << title << "\" - " << author << " (" << year << ")\n";
}
