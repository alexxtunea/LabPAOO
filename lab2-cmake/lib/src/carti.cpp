#include "carti.h"

std::string formateazaCarte(const std::string& titlu, const std::string& autor, int an) {
    return "\"" + titlu + "\" - " + autor + " (" + std::to_string(an) + ")";
}

int celMaiVechiAn(const int* ani, int n) {
    int minim = ani[0];
    for (int i = 1; i < n; i++)
        if (ani[i] < minim)
            minim = ani[i];
    return minim;
}
