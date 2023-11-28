#include <iostream>
#include <string>

char digitToHexChar(int digit) {
    if (digit >= 0 && digit <= 9) {
        return '0' + digit;
    }
    else if (digit >= 10 && digit <= 15) {
        return 'A' + (digit - 10);
    }
    return '?';
}

std::string convertToBaseK(int n, int k) {
    if (n == 0) {
        return "0";
    }
    else {
        return convertToBaseK(n / k, k) + digitToHexChar(n % k);
    }
}

int main() {
    int n = 2022;
    int k = 16;

    std::string result = n == 0 ? "0" : convertToBaseK(n, k);
    std::cout << "The number " << n << " in base " << k << " is: " << result << std::endl;

    return 0;
}