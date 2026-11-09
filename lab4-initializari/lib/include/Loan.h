#pragma once
#include "Book.h"
#include <string>

class Loan {
public:
    Loan(const Book& book, const std::string& member, int days);
    void print() const;

private:
    const Book& book;
    const std::string member;
    int days; 
};
