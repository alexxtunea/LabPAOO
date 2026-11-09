# Laborator 4 - Initializari si functii generate de compilator
Aplicatie de gestiune a cartilor dintr-o biblioteca, care ilustreaza item-urile 4, 5 si 6 din *Effective C++* (Scott Meyers).

## Cerinte
Sa se scrie un proiect C++ care sa acopere principalele probleme descrise in urmatoarele item-uri din cartea Effective C++:
- Item 4: Make sure that objects are initialized before they're used.
- Item 5: Know what functions C++ silently writes and calls.
- Item 6: Explicitly disallow the use of compiler generated functions you do not want.

## Structura
- `lib/` - biblioteca statica `biblioteca`:
  - `Book` - clasa fara functii speciale declarate (Item 5)
  - `Catalog` - catalog global implementat ca static local (Item 4)
  - `Loan` - imprumut cu membru referinta si membru `const` (Item 4 + 5)
  - `Uncopyable`, `LibraryCard` - permis de biblioteca care nu poate fi copiat (Item 6)
- `app/` - aplicatia care foloseste biblioteca (`main.cpp`)

## Build

```
cd lab4-initializari
cmake -S . -B build
cmake --build build
./build/app/lab4
```
