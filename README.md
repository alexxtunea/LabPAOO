# PAOO - Laboratoare

| Folder | Subiect |
|--------|---------|
| - | Laboratorul 1: crearea repository-ului git (acest repo) |
| [`lab2-cmake/`](lab2-cmake/) | Biblioteca statica + aplicatie care o foloseste, cu CMake |
| [`lab3-constructori/`](lab3-constructori/) | Gestiunea cartilor dintr-o biblioteca: incapsulare, constructori, destructor, copy si move constructor |

Toate laboratoarele au aceeasi structura:

```
labN-subiect/
├── README.md        # cerinte, structura, build
├── CMakeLists.txt   # proiectul principal: add_subdirectory(lib) + add_subdirectory(app)
├── lib/             # biblioteca statica (include/ + src/)
└── app/             # executabilul care foloseste biblioteca
```
