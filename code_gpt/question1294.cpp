/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string decimalToBinary(int n) {
    if (n == 0) return "0";
    return decimalToBinary(n / 2) + to_string(n % 2);
}

int binaryToDecimal(const string& bin) {
    if (bin.empty()) return 0;
    return (bin.back() - '0') + 2 * binaryToDecimal(bin.substr(0, bin.size() - 1));
}

int main() {
    int N;
    cin >> N;
    vector<string> results;

    for (int i = 0; i < N; ++i) {
        string operation, number;
        cin >> operation >> number;

        if (operation == "dec") {
            int decNumber = stoi(number);
            results.push_back(decimalToBinary(decNumber));
        } else if (operation == "bin") {
            results.push_back(to_string(binaryToDecimal(number)));
        } else {
            results.push_back("comando invalido.");
        }
    }

    for (const string& result : results) {
        cout << result << endl;
    }
    
    return 0;
}
