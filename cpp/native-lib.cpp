#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
using namespace std;

// Function to convert Decimal to Binary
string decimalToBinary(int decimal) {
    string binary = "";
    // Special case for zero
    if (decimal == 0) return "0";
    // Loop until the decimal number is reduced to zero
    while (decimal > 0) {
        // Prepend the remainder (0 or 1) to the binary string
        binary = to_string(decimal % 2) + binary;
        decimal /= 2;  // Divide decimal by 2
    }
    return binary;
}

// Function to convert Decimal to Octal
string decimalToOctal(int decimal) {
    string octal = "";
    // Special case for zero
    if (decimal == 0) return "0";
    // Loop until the decimal number is reduced to zero
    while (decimal > 0) {
        // Prepend the remainder (0-7) to the octal string
        octal = to_string(decimal % 8) + octal;
        decimal /= 8;  // Divide decimal by 8
    }
    return octal;
}

// Function to convert Decimal to Hexadecimal
string decimalToHex(int decimal) {
    stringstream ss;
    // Convert to hexadecimal and capitalize letters A-F
    ss << hex << uppercase << decimal;
    return ss.str();
}

// Function to convert Binary to Decimal
int binaryToDecimal(string binary) {
    int decimal = 0;
    int base = 1;  // Start with 2^0
    // Loop through the binary string from right to left
    for (int i = binary.length() - 1; i >= 0; i--) {
        // Add the value of each binary digit multiplied by its base
        if (binary[i] == '1') {
            decimal += base;
        }
        base *= 2;  // Move to the next power of 2
    }
    return decimal;
}

// Function to convert Octal to Decimal
int octalToDecimal(string octal) {
    int decimal = 0;
    int base = 1;  // Start with 8^0
    // Loop through the octal string from right to left
    for (int i = octal.length() - 1; i >= 0; i--) {
        // Add the value of each octal digit multiplied by its base
        decimal += (octal[i] - '0') * base;
        base *= 8;  // Move to the next power of 8
    }
    return decimal;
}

// Function to convert Hexadecimal to Decimal
int hexToDecimal(string hex) {
    int decimal = 0;
    int base = 1;  // Start with 16^0
    // Loop through the hexadecimal string from right to left
    for (int i = hex.length() - 1; i >= 0; i--) {
        // Check if the character is a digit or a letter
        if (hex[i] >= '0' && hex[i] <= '9') {
            decimal += (hex[i] - '0') * base;  // For digits 0-9
        } else if (hex[i] >= 'A' && hex[i] <= 'F') {
            decimal += (hex[i] - 'A' + 10) * base;  // For letters A-F
        }
        base *= 16;  // Move to the next power of 16
    }
    return decimal;
}

// Function to convert Binary to Octal via Decimal
string binaryToOctal(string binary) {
    int decimal = binaryToDecimal(binary);  // Convert binary to decimal first
    return decimalToOctal(decimal);  // Then convert decimal to octal
}

// Function to convert Binary to Hexadecimal via Decimal
string binaryToHex(string binary) {
    int decimal = binaryToDecimal(binary);  // Convert binary to decimal first
    return decimalToHex(decimal);  // Then convert decimal to hexadecimal
}

// Function to convert Octal to Binary via Decimal
string octalToBinary(string octal) {
    int decimal = octalToDecimal(octal);  // Convert octal to decimal first
    return decimalToBinary(decimal);  // Then convert decimal to binary
}

// Function to convert Octal to Hexadecimal via Decimal
string octalToHex(string octal) {
    int decimal = octalToDecimal(octal);  // Convert octal to decimal first
    return decimalToHex(decimal);  // Then convert decimal to hexadecimal
}

// Function to convert Hexadecimal to Binary via Decimal
string hexToBinary(string hex) {
    int decimal = hexToDecimal(hex);  // Convert hex to decimal first
    return decimalToBinary(decimal);  // Then convert decimal to binary
}

// Function to convert Hexadecimal to Octal via Decimal
string hexToOctal(string hex) {
    int decimal = hexToDecimal(hex);  // Convert hex to decimal first
    return decimalToOctal(decimal);  // Then convert decimal to octal
}

// Function to prompt user for input and perform conversions
void performConversions() {
    string inputNumber;
    string inputType, outputType;

    // Asking user for input number
    cout << "Enter the number you want to convert: ";
    cin >> inputNumber;

    // Asking user for the type of input number
    cout << "Enter the input type (decimal/binary/octal/hexadecimal): ";
    cin >> inputType;

    // Asking user for the desired output type
    cout << "Enter the output type (decimal/binary/octal/hexadecimal): ";
    cin >> outputType;

    // Conversion logic based on input and output types
    int decimalValue;
    string result;

    // Convert input number to decimal based on its type
    if (inputType == "decimal") {
        decimalValue = stoi(inputNumber);  // Convert string to integer
    } else if (inputType == "binary") {
        decimalValue = binaryToDecimal(inputNumber);  // Convert binary to decimal
    } else if (inputType == "octal") {
        decimalValue = octalToDecimal(inputNumber);  // Convert octal to decimal
    } else if (inputType == "hexadecimal") {
        decimalValue = hexToDecimal(inputNumber);  // Convert hexadecimal to decimal
    } else {
        cout << "Invalid input type." << endl;
        return;  // Exit if invalid type
    }

    // Convert decimal value to the desired output type
    if (outputType == "decimal") {
        result = to_string(decimalValue);  // Decimal output
    } else if (outputType == "binary") {
        result = decimalToBinary(decimalValue);  // Convert decimal to binary
    } else if (outputType == "octal") {
        result = decimalToOctal(decimalValue);  // Convert decimal to octal
    } else if (outputType == "hexadecimal") {
        result = decimalToHex(decimalValue);  // Convert decimal to hexadecimal
    } else {
        cout << "Invalid output type." << endl;
        return;  // Exit if invalid type
    }

    // Display the result
    cout << "The converted value is: " << result << endl;
}

int main() {
    // Call the function to perform conversions
    performConversions();
    return 0;
}
