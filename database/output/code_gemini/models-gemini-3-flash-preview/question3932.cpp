/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <cctype>
#include <vector>

using namespace std;

/**
 * Problem: Lukkity vs Os Textos Napoleônicos
 * Description: Extract ASCII-encoded words from brackets [xxx-yyy-], 
 * convert them to either all uppercase or all lowercase based on 
 * which case appears more in the decoded word, and replace the bracket 
 * notation in the original text.
 * Complexity: O(N) where N is the length of the text.
 */

int main() {
    // Optimize I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string line;
    // Read input line by line to handle potential multi-line text blocks
    while (getline(cin, line)) {
        string result = "";
        for (size_t i = 0; i < line.length(); ++i) {
            // Check for the start of an encoded word
            if (line[i] == '[') {
                size_t closingBracket = line.find(']', i);
                if (closingBracket != string::npos) {
                    // Extract the content inside the brackets
                    string content = line.substr(i + 1, closingBracket - i - 1);
                    string decodedWord = "";
                    string currentNum = "";
                    
                    // Parse ASCII codes separated by '-'
                    for (char c : content) {
                        if (isdigit(static_cast<unsigned char>(c))) {
                            currentNum += c;
                        } else if (c == '-') {
                            if (!currentNum.empty()) {
                                decodedWord += static_cast<char>(stoi(currentNum));
                                currentNum = "";
                            }
                        }
                    }
                    
                    // Count uppercase and lowercase letters
                    int upperCount = 0;
                    int lowerCount = 0;
                    for (char c : decodedWord) {
                        if (isupper(static_cast<unsigned char>(c))) {
                            upperCount++;
                        } else if (islower(static_cast<unsigned char>(c))) {
                            lowerCount++;
                        }
                    }
                    
                    // Convert the word based on the case count rule
                    // Rule: more uppercase -> all uppercase, more lowercase -> all lowercase
                    if (upperCount > lowerCount) {
                        for (char &c : decodedWord) {
                            c = static_cast<char>(toupper(static_cast<unsigned char>(c)));
                        }
                    } else {
                        // The problem guarantees upperCount != lowerCount
                        for (char &c : decodedWord) {
                            c = static_cast<char>(tolower(static_cast<unsigned char>(c)));
                        }
                    }
                    
                    // Append translated word and skip the processed block
                    result += decodedWord;
                    i = closingBracket;
                } else {
                    // If no closing bracket is found, treat '[' as a normal character
                    result += line[i];
                }
            } else {
                result += line[i];
            }
        }
        // Output the processed line
        cout << result << "\n";
    }

    return 0;
}