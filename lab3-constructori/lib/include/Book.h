#pragma once

class Book {
public:
    Book(const char* title, const char* author, int year);
    Book(const Book& other);
    Book(Book&& other) noexcept;
    ~Book();

    const char* getTitle() const;
    const char* getAuthor() const;
    int getYear() const;
    void setTitle(const char* newTitle);
    void print() const;

private:
    char* title;
    char* author;
    int year;
};
