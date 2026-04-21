/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x;
    vector<int> numbers;
    while (cin >> x) {
        numbers.push_back(x);
    }

    if (numbers.empty()) {
        return 0;
    }

    sort(numbers.begin(), numbers.end());

    for (size_t i = 0; i < numbers.size(); ++i) {
        cout << numbers[i] << " ";
    }
    cout << "\n";

    int odd_number = 0;
    int n = numbers.size();
    for (int i = 0; i < n; ) {
        int j = i;
        while (j < n && numbers[j] == numbers[i]) {
            j++;
        }
        if ((j - i) % 2 != 0) {
            odd_number = numbers[i];
            break;
        }
        i = j;
    }

    cout << odd_number << endl;

    return 0;
}