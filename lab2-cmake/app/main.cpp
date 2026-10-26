#include "carti.h"
#include <iostream>

int main() {
    std::cout << formateazaCarte("Ion", "Liviu Rebreanu", 1920) << "\n";
    std::cout << formateazaCarte("Morometii", "Marin Preda", 1955) << "\n";

    int ani[] = {1920, 1955, 1883};
    std::cout << "Cea mai veche carte e din " << celMaiVechiAn(ani, 3) << "\n";
}
