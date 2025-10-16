#include "TasMax/TasMax.hpp"
#include "TasMin/TasMin.hpp"
#include <iostream>

int main() {
    TasMin tas;

    std::cout << "=== Insertion des elements dans le Tas Min ===" << std::endl;
    tas.insert(27);
    tas.insert(12);
    tas.insert(8);
    tas.insert(45);
    tas.insert(17);
    tas.insert(63);
    tas.insert(100);
    tas.insert(5);
    tas.insert(75);
    tas.insert(90);
    tas.insert(26);
    tas.insert(32);
    tas.insert(188);
    tas.insert(95);

    std::cout << "\n--- Tas Min initial ---" << std::endl;
    tas.display();

    std::cout << "\n--- Extraction du plus petit element ---" << std::endl;
    int min1 = tas.extractMin();
    std::cout << "Valeur minimale extraite : " << min1 << std::endl;

    std::cout << "\n--- Tas apres la premiere extraction ---" << std::endl;
    tas.display();

    std::cout << "\n--- Deuxieme extraction du plus petit element ---" << std::endl;
    int min2 = tas.extractMin();
    std::cout << "Valeur minimale extraite : " << min2 << std::endl;

    std::cout << "\n--- Tas apres la deuxieme extraction ---" << std::endl;
    tas.display();

    std::cout << "\n=== Fin du test Tas Min ===" << std::endl;
    return 0;
}
