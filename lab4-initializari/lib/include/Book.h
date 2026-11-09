#pragma once
#include <string>

class Book {
public:
    Book(std::string title, std::string author, int year);

    const std::string& getTitle() const;
    void setTitle(const std::string& newTitle);
    void print() const;

private:
    std::string title;
    std::string author;
    int year;
};
