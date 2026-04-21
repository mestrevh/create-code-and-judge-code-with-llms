/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> numbers(10);
    for (int i = 0; i < 10; ++i) {
        if (!(cin >> numbers[i])) break;
    }

    int last_number = numbers[9];
    int count = 0;

    for (int i = 0; i < 10; ++i) {
        if (numbers[i] == last_number) {
            count++;
        }
    }

    cout << "O numero " << last_number << " apareceu " << count << " vezes" << endl;

    return 0;
}