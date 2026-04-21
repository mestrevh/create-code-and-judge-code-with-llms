/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int grades[3];
    if (cin >> grades[0] >> grades[1] >> grades[2]) {
        sort(grades, grades + 3);
        cout << grades[0] << "\n" << grades[1] << "\n" << grades[2] << "\n";
    }

    return 0;
}