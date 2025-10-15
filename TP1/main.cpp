#include "TasMax/TasMax.hpp"

int main() {
    TasMax tas;
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
    tas.display();
    tas.extractMax();
    tas.extractMax();
    tas.display();
    return 0;
}
