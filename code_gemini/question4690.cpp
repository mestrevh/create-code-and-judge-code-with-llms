/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> arr;
    int num;
    while (cin >> num) {
        arr.push_back(num);
    }

    for (int i = 0; i < arr.size(); ++i) {
        for (int j = 0; j < arr.size(); ++j) {
            cout << arr[j] << " ";
        }
        cout << endl;

        for (int j = i; j > 0; --j) {
            if (arr[j] < arr[j - 1]) {
                swap(arr[j], arr[j - 1]);

                for (int k = 0; k < arr.size(); ++k) {
                    cout << arr[k] << " ";
                }
                cout << endl;
            } else {
                break;
            }
        }
    }
    return 0;
}
