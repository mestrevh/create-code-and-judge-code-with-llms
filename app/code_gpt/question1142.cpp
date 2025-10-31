/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>

using namespace std;

bool isFunnyLaughter(const string& str) {
    string vowels;
    for (char ch : str) {
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            vowels += ch;
        }
    }
    string reversedVowels = vowels;
    reverse(reversedVowels.begin(), reversedVowels.end());
    return vowels == reversedVowels;
}

int main() {
    string laughter;
    cin >> laughter;
    
    cout << (isFunnyLaughter(laughter) ? "S" : "N") << endl;
    return 0;
}
