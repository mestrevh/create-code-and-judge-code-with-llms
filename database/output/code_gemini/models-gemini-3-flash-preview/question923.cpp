/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string answers[5];
    int positive_count = 0;

    for (int i = 0; i < 5; ++i) {
        if (!(cin >> answers[i])) break;
        if (answers[i] == "True") {
            positive_count++;
        }
    }

    cout << "Telefonou para a vitima?" << "\n";
    cout << "Esteve no local do crime?" << "\n";
    cout << "Mora perto da vitima?" << "\n";
    cout << "Devia para a vitima?" << "\n";
    cout << "Ja trabalhou com a vitima?" << "\n";

    if (positive_count == 5) {
        cout << "Assassino" << endl;
    } else if (positive_count == 3 || positive_count == 4) {
        cout << "Cumplice" << endl;
    } else if (positive_count == 2) {
        cout << "Suspeita" << endl;
    } else {
        cout << "Inocente" << endl;
    }

    return 0;
}