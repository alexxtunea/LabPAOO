# Laborator 2

## Cerinte

Se vor implementa următoarele cerințe:
- două proiecte C++ împreună cu fișierele CMakeLists.txt aferente
- primul dintre proiecte exportă o bibliotecă statică împreună cu un fișier header (.h)
- al doilea proiect face uz de biblioteca statică creată de primul proiect

## Structura

- `lib/` - primul proiect: biblioteca statica `carti` (`include/carti.h` + `src/carti.cpp`)
- `app/` - al doilea proiect: executabilul `lab2`, care include `carti.h` si se linkeaza cu `carti`

## Build

```
cd lab2-cmake
cmake -S . -B build
cmake --build build
./build/app/lab2
```

Dupa build, biblioteca statica se afla in `build/lib/libcarti.a`.
