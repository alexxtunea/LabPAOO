#include "Book.h"
#include "Catalog.h"
#include "LibraryCard.h"
#include "Loan.h"
#include <iostream>
#include <type_traits>

// Verificari la compilare: ce functii a scris (sau nu) compilatorul
static_assert(std::is_copy_constructible_v<Book> && std::is_copy_assignable_v<Book>);
static_assert(!std::is_default_constructible_v<Book>);
static_assert(std::is_copy_constructible_v<Loan> && !std::is_copy_assignable_v<Loan>);
static_assert(!std::is_copy_constructible_v<LibraryCard> && !std::is_copy_assignable_v<LibraryCard>);

namespace {
struct CatalogSeeder {
    CatalogSeeder() {
        catalog().push_back(Book("Ion", "Liviu Rebreanu", 1920));
        catalog().push_back(Book("Morometii", "Marin Preda", 1955));
        std::cout << "[inainte de main] catalogul are " << catalog().size() << " carti\n";
    }
} seeder;
}

int main() {
    std::cout << "\n--- Item 4: initializarea obiectelor inainte de folosire ---\n";
    for (const Book& b : catalog())
        b.print();
    Loan loan(catalog()[0], "Ana", 14);
    loan.print();
    std::cout << "Catalogul a fost populat inainte de main din alt fisier .cpp, fara probleme,\n"
                 "pentru ca e un static local construit la primul apel al lui catalog().\n";

    std::cout << "\n--- Item 5: functii scrise si apelate de compilator ---\n";
    Book copy = catalog()[0];  // copy constructor generat
    copy.setTitle("Ion (editia a II-a)");
    Book other("Enigma Otiliei", "George Calinescu", 1938);
    other = copy;  // operator= generat
    catalog()[0].print();
    copy.print();
    other.print();
    Loan loanCopy = loan;  // copy constructor generat si pentru Loan
    loanCopy.print();
    std::cout << "Book nu declara copy constructor, operator= sau destructor, dar le are.\n"
                 "  Book empty;       -> eroare: exista Book(title, author, year), deci nu se genereaza Book()\n"
                 "  loanCopy = loan;  -> eroare: operator= sters (Loan are referinta si membru const)\n";

    std::cout << "\n--- Item 6: interzicerea functiilor generate nedorite ---\n";
    LibraryCard card("Ana");
    card.borrow(catalog()[0]);
    card.borrow(catalog()[1]);
    card.print();
    // LibraryCard clone = card;  // eroare: copy constructor sters (mostenit din Uncopyable)
    // clone = card;              // eroare: operator= sters
    std::cout << "  LibraryCard clone = card;  -> eroare la compilare: copierea e interzisa prin Uncopyable\n";
}
