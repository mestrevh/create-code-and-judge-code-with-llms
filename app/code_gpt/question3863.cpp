/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<string> strings(N);
    vector<char> directions(N);
    string P;

    for (int i = 0; i < N; ++i) {
        cin >> directions[i] >> strings[i];
    }
    cin >> P;

    string result;
    for (int i = 0; i < N; ++i) {
        string half = strings[i];
        if (directions[i] == 'd') {
            result += half.substr(0, 6); // read right side
        } else {
            result += string(half.begin() + 6, half.end()); // read left side reversed
        }
    }

    int count = 0;
    for (size_t i = 0; i <= result.size() - P.size(); ++i) {
        if (result.substr(i, P.size()) == P) {
            count++;
        }
    }

    cout << P << count << endl;
    return 0;
}
