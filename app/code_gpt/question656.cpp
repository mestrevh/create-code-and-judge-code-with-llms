/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <tuple>
#include <algorithm>

using namespace std;

tuple<int, int> parseCard(const string& line) {
    static unordered_map<string, int> numberMap = {{"um", 1}, {"dois", 2}, {"tres", 3}};
    static unordered_map<string, int> shapeMap = {{"circulo", 0}, {"circulos", 0}, {"quadrado", 1}, {"quadrados", 1}, {"triangulo", 2}, {"triangulos", 2}};
    auto words = line.substr(0, line.find('\n'));
    return make_tuple(numberMap[words.substr(0, words.find(' '))], shapeMap[words.substr(words.find(' ') + 1)]);
}

bool isSet(const tuple<int, int>& a, const tuple<int, int>& b, const tuple<int, int>& c) {
    auto [num1, shape1] = a;
    auto [num2, shape2] = b;
    auto [num3, shape3] = c;
    return (num1 + num2 + num3) % 3 == 0 && (shape1 ^ shape2 ^ shape3) == (shape1 + shape2 + shape3);
}

int main() {
    string line;
    while (true) {
        int N;
        cin >> N;
        if (N == 0) break;

        vector<tuple<int, int>> cards(N);
        cin.ignore();
        for (int i = 0; i < N; i++) {
            getline(cin, line);
            cards[i] = parseCard(line);
        }

        int maxSets = 0;
        vector<bool> used(N, false);
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                for (int k = j + 1; k < N; k++) {
                    if (isSet(cards[i], cards[j], cards[k])) {
                        used[i] = used[j] = used[k] = true;
                        maxSets++;
                    }
                }
            }
        }

        cout << maxSets << endl;
    }
    return 0;
}
