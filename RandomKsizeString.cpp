#include <iostream>
#include <string>
#include <random>

std::string generateRandomString(int k) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 25); // 'a' is ASCII 97, 'z' is ASCII 122

    std::string random_string;
    random_string.reserve(k);

    for (int i = 0; i < k; ++i) {
        char random_char = 'a' + dis(gen);
        random_string.push_back(random_char);
    }

    return random_string;
}

int main() {
    int k;
    std::cout << "Enter the length of the random string: ";
    std::cin >> k;

    if (k > 0) {
        std::string random_string = generateRandomString(k);
        std::cout << k << std::endl;
        std:: cout << random_string << std::endl;
    } else {
        std::cout << "Length should be a positive integer." << std::endl;
    }

    return 0;
}
