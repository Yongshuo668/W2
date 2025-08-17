#include <iostream>
#include <string>

// Binary addition
std::string binaryAdd(std::string bin1, std::string bin2) {
    std::string result;
    int carry = 0, i = bin1.size() - 1, j = bin2.size() - 1;
    while (i >= 0 || j >= 0 || carry > 0) {
        int sum = carry;
        if (i >= 0) sum += bin1[i--] - '0';
        if (j >= 0) sum += bin2[j--] - '0';
        result = std::to_string(sum % 2) + result;
        carry = sum / 2;
    }
    return result;
}

// Binary subtraction (assuming bin1 >= bin2)
std::string binarySub(std::string bin1, std::string bin2) {
    std::string result;
    int borrow = 0, i = bin1.size() - 1, j = bin2.size() - 1;
    while (i >= 0) {
        int sub = (bin1[i--] - '0') - borrow;
        if (j >= 0) sub -= (bin2[j--] - '0');
        if (sub < 0) {
            sub += 2;
            borrow = 1;
        } else {
            borrow = 0;
        }
        result = std::to_string(sub) + result;
    }
    // Remove leading zeros
    size_t start = result.find_first_not_of('0');
    if (start == std::string::npos) return "0";
    return result.substr(start);
}

// Binary left shift
std::string binaryLeftShift(std::string bin, int shifts) {
    if (bin == "0") return "0";
    return bin + std::string(shifts, '0');
}

// Binary right shift
std::string binaryRightShift(std::string bin, int shifts) {
    if (bin == "0" || shifts >= bin.size()) return "0";
    return bin.substr(0, bin.size() - shifts);
}

int main() {
    std::string bin1 = "1010", bin2 = "110";
    
    std::cout << "Binary Addition: " << binaryAdd(bin1, bin2) << std::endl;
    std::cout << "Binary Subtraction: " << binarySub(bin1, bin2) << std::endl;
    std::cout << "Left Shift (2 shifts): " << binaryLeftShift(bin1, 2) << std::endl;
    std::cout << "Right Shift (1 shift): " << binaryRightShift(bin1, 1) << std::endl;

    return 0;
}