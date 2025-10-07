/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <iomanip>

using namespace std;

int main() {
    int N;
    while (cin >> N) {
        vector<string> words(N);
        for (int i = 0; i < N; ++i) {
            cin >> words[i];
        }

        map<string, int> prefixCount;
        for (const auto& word : words) {
            for (int i = 1; i <= word.size(); ++i) {
                string prefix = word.substr(0, i);
                prefixCount[prefix]++;
            }
        }

        double totalKeyPresses = 0;
        for (const auto& word : words) {
            int neededKeyPresses = 1; 
            for (int i = 1; i < word.size(); ++i) {
                string prefix = word.substr(0, i + 1);
                if (prefixCount[prefix] == 1) {
                    break;
                }
                neededKeyPresses++;
            }
            totalKeyPresses += neededKeyPresses;
        }

        double averageKeyPresses = totalKeyPresses / N;
        cout << fixed << setprecision(2) << averageKeyPresses << endl;
    }
    return 0;
}
