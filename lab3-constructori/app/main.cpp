#include "Book.h"
#include "Library.h"
#include <iostream>
#include <utility>

int main() {
    std::cout << "--- 1. Constructor ---\n";
    Book b1("Ion", "Liviu Rebreanu", 1920);

    std::cout << "\n--- 2. Copy constructor ---\n";
    Book b2 = b1;
    b2.setTitle("Ion (editia a II-a)");
    b1.print();
    b2.print();
    std::cout << "Cu copy constructor-ul implicit, b1 si b2 ar fi avut acelasi pointer title.\n"
                 "setTitle pe b2 ar fi sters textul lui b1, iar la final delete[] s-ar fi\n"
                 "apelat de doua ori pe aceeasi adresa -> double free / crash.\n";

    std::cout << "\n--- 3. Move constructor ---\n";
    Book b3 = std::move(b1);
    b1.print();
    b3.print();
    std::cout << "b3 a preluat memoria lui b1 fara nicio alocare noua.\n"
                 "Fara move constructor s-ar fi apelat copy constructor-ul (new + strcpy inutile).\n";

    std::cout << "\n--- 4. Biblioteca ---\n";
    Library lib;
    lib.add(Book("Morometii", "Marin Preda", 1955));
    lib.add(std::move(b3));
    lib.add(b2);
    lib.print();

    std::cout << "\n--- 5. Destructori (iesire din main) ---\n";
}
