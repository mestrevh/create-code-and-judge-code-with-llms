/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long books, students;
    if (!(cin >> books >> students)) return 0;

    if (books == 0) {
        cout << "D" << endl;
        return 0;
    }

    long long ratio = students / books;

    if (ratio <= 8) {
        cout << "A" << endl;
    } else if (ratio <= 12) {
        cout << "B" << endl;
    } else if (ratio <= 18) {
        cout << "C" << endl;
    } else {
        cout << "D" << endl;
    }

    return 0;
}