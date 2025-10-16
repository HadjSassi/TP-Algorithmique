#include "iostream"
using namespace std;


static int max(int firstValue, int secondValue) {
    return (firstValue > secondValue) ? firstValue : secondValue;
}

static int min(int firstValue, int secondValue) {
    return (firstValue < secondValue) ? firstValue : secondValue;
}

static int isPrime(int number, int divisor = 2) {
    if (number <= 1)
        return 0;
    if (divisor * divisor > number)
        return 1;
    if (number % divisor == 0)
        return 0;
    return isPrime(number, divisor + 1);
}

static int computePGCD(int x, int y) {
    if (isPrime(x))
        return x;
    if (isPrime(y))
        return y;
    return computePGCD(
        max(x, y) - min(x, y),
        min(x, y));
}

int main() {
    cout << computePGCD(35,45) << endl;
    return 0;
}
