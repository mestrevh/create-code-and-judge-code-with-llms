/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    unordered_map<int, int> frequency;
    int value;
    int max_freq = 0;
    int mode = 0;

    while (cin >> value) {
        frequency[value]++;
        if (frequency[value] > max_freq) {
            max_freq = frequency[value];
            mode = value;
        }
    }

    cout << "Moda = " << mode << endl;

    return 0;
}