#include "Catalog.h"

std::vector<Book>& catalog() {
    static std::vector<Book> books;
    return books;
}
