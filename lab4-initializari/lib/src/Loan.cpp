#include "Loan.h"
#include <iostream>

// Varianta cu atribuiri in corpul constructorului nu compileaza:
//   Loan::Loan(...) { this->book = book; this->member = member; }  // eroare: referinta / const
// Membrii se initializeaza in ordinea declararii din clasa, nu in ordinea din lista,
// de aceea lista respecta aceeasi ordine (altfel -Wreorder).
Loan::Loan(const Book& book, const std::string& member, int days)
    : book(book), member(member), days(days) {}

void Loan::print() const {
    std::cout << "  " << member << " a imprumutat \"" << book.getTitle() << "\" pentru " << days << " zile\n";
}
