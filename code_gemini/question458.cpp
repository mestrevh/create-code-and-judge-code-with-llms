/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <iomanip>
#include <cctype>
#include <vector>

std::string normalize(const std::string& input) {
    std::string result = "";
    for (size_t i = 0; i < input.length(); ++i) {
        unsigned char current_char = input[i];

        if (current_char < 128) {
            result += tolower(current_char);
        } else if (current_char == 0xc3) { 
            if (i + 1 < input.length()) {
                unsigned char next_char = input[i + 1];
                i++; 

                switch (next_char) {
                    case 0xa0: case 0xa1: case 0xa2: case 0xa3: // à, á, â, ã
                    case 0x80: case 0x81: case 0x82: case 0x83: // À, Á, Â, Ã
                        result += 'a';
                        break;
                    case 0xa7: case 0x87: // ç, Ç
                        result += 'c';
                        break;
                    case 0xa8: case 0xa9: case 0xaa: case 0xab: // è, é, ê, ë
                    case 0x88: case 0x89: case 0x8a: case 0x8b: // È, É, Ê, Ë
                        result += 'e';
                        break;
                    case 0xac: case 0xad: case 0xae: case 0xaf: // ì, í, î, ï
                    case 0x8c: case 0x8d: case 0x8e: case 0x8f: // Ì, Í, Î, Ï
                        result += 'i';
                        break;
                    case 0xb2: case 0xb3: case 0xb4: case 0xb5: // ò, ó, ô, õ
                    case 0x92: case 0x93: case 0x94: case 0x95: // Ò, Ó, Ô, Õ
                        result += 'o';
                        break;
                    case 0xb9: case 0xba: case 0xbb: case 0xbc: // ù, ú, û, ü
                    case 0x99: case 0x9a: case 0x9b: case 0x9c: // Ù, Ú, Û, Ü
                        result += 'u';
                        break;
                    default:
                        break;
                }
            }
        }
    }
    return result;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string package_input, payment_input;
    std::getline(std::cin, package_input);
    std::getline(std::cin, payment_input);

    std::string package_norm = normalize(package_input);
    std::string payment_norm = normalize(payment_input);

    double price = 0.0;
    int channels = 0;

    if (package_norm.find("basico") != std::string::npos) {
        price = 80.80;
        channels = 32;
    } else if (package_norm.find("entretenimento") != std::string::npos) {
        price = 100.40;
        channels = 55;
    } else if (package_norm.find("multicultural") != std::string::npos) {
        price = 130.23;
        channels = 70;
    } else if (package_norm.find("completo") != std::string::npos) {
        price = 215.50;
        channels = 112;
    }

    if (payment_norm.find("debito automatico") != std::string::npos) {
        if (package_norm.find("basico") != std::string::npos || package_norm.find("entretenimento") != std::string::npos) {
            price *= 0.95;
            channels += 6;
        } else {
            price *= 0.90;
            channels += 11;
        }
    }

    std::cout << std::fixed << std::setprecision(2) << price << std::endl;
    std::cout << channels << std::endl;

    return 0;
}
