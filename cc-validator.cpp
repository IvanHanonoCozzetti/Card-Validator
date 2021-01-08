#include <iostream>
#include <string>
//#include <cstdio>

// Luhn Algorithm
bool checkLuhn(const std::string& cardNo) {

    int nDigits = cardNo.length();
    int nSum = 0, isSecond = false;
    for(int i = nDigits - 1; i >= 0; i--) {

        int d = cardNo[i] - '0';

        if(isSecond == true)
           d = d * 2;

        nSum += d / 10;
        nSum += d % 10;

        isSecond = !isSecond;
    }
    return (nSum % 10 == 0);
}

// User Input and Validation
int main() {
    
    std::cout << "Please enter the card number:" << std::endl;
    std::string cardNo;
    std::cin >> cardNo;

    if(checkLuhn(cardNo)) {
        std::cout << "This is a valid card number." << std::endl;
    } else {
        std::cout << "This is not a valid card number." << std::endl;
    }

    std::cin.get();
    std::cout << "--------------------------------------------------" << std::endl;
    std::cout << "Press ENTER to exit the program." << std::endl;
    std::cin.get();
    // Or using C -> std::getchar();

    return 0;
}
