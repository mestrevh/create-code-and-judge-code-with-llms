/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

int calculateC(vector<int> digits) {
    int evenSum = 0;
    int oddSum = 0;
    for (int i = 0; i < (int)digits.size(); ++i) {
        if (i % 2 == 0) {
            evenSum += digits[i];
        } else {
            oddSum += digits[i];
        }
    }
    return (evenSum * 3 + oddSum) % 10;
}

int calculateR(vector<int> digits) {
    if (digits.empty()) return 0;
    int maxR = 0;
    int currentR = 0;
    for (int i = 0; i < (int)digits.size(); ++i) {
        if (i > 0 && digits[i] == digits[i - 1]) {
            currentR++;
        } else {
            currentR = 1;
        }
        if (currentR > maxR) {
            maxR = currentR;
        }
    }
    return maxR;
}

string generateBaseWord(string word) {
    string base = "";
    for (int i = 0; i < (int)word.length(); ++i) {
        char c = word[i];
        char upperC = (char)toupper((unsigned char)c);
        if (upperC != 'A' && upperC != 'E' && upperC != 'I' && upperC != 'O' && upperC != 'U') {
            base += upperC;
        }
    }
    if (base.empty()) {
        return "VOID";
    }
    return base;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N)) return 0;

    vector<int> digits(N);
    for (int i = 0; i < N; ++i) {
        char d;
        cin >> d;
        digits[i] = d - '0';
    }

    string word;
    cin >> word;

    int C = calculateC(digits);
    int R = calculateR(digits);
    string base = generateBaseWord(word);

    cout << C << " " << R << "\n";
    cout << "codigo: " << base << C << R << "\n";

    return 0;
}