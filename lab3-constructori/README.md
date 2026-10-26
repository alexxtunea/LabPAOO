# Laborator 3 - Constructori si destructori

Aplicatie simpla de gestiune a cartilor dintr-o biblioteca.

## Cerinte

Tema constă într-o aplicație scrisă în c++ în cadrul căreia să se abordeze următoarele subiecte discutate:
1. build folosind cmake respectând structura discutată la laborator
2. încapsulare
3. inițializarea membrilor din constructor
4. eliberarea heap-ului în cadrul destructorului
5. suprascrierea copy constructor-ului
6. crearea unui move constructor

Pentru subpunctele 3-6 trebuie să ilustrați exemple reprezentative, care indică clar nevoia implementării acestor concepte (e.g., arătați de ce este nevoie de copy constructor și ce se poate întâmpla dacă nu este suprascris).

## Structura

- `lib/` - biblioteca statica `biblioteca` (`include/` cu header-ele, `src/` cu implementarea claselor `Book` si `Library`)
- `app/` - aplicatia care foloseste biblioteca (`main.cpp`)

## Build

```
cd lab3-constructori
cmake -S . -B build
cmake --build build
./build/app/lab3
```

## Concepte

- **Incapsulare** - `Book` are membrii privati, accesati doar prin getteri / `setTitle`.
- **Initializare in constructor** - membrii sunt initializati in lista de initializare; altfel pointerii ar avea valori random si destructorul ar elibera adrese invalide.
- **Destructor** - `title` si `author` sunt alocate cu `new[]`, deci destructorul face `delete[]` (altfel memory leak).
- **Copy constructor** - cel implicit copiaza doar pointerii (shallow copy): doua obiecte ar partaja acelasi buffer, iar la distrugere s-ar face `delete[]` de doua ori. Varianta suprascrisa face deep copy.
- **Move constructor** - preia pointerii obiectului sursa si ii pune pe `nullptr`, fara alocari noi. E folosit la `std::move` si de `std::vector` cand se realoca (de aceea e `noexcept`).
