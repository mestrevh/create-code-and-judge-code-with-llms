/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

bool isValid(string plate) {
    if (plate.length() != 7) {
        return false;
    }
    if (!isalpha(plate[0]) || !isalpha(plate[1]) || !isalpha(plate[2])) {
        return false;
    }
    if (!isdigit(plate[3])) {
        return false;
    }
    if (!isalpha(plate[4])) {
        return false;
    }
    if (!isdigit(plate[5]) || !isdigit(plate[6])) {
        return false;
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    int count = 0;
    for (int i = 0; i < n; i++) {
        string plate;
        cin >> plate;
        if (!isValid(plate)) {
            count++;
        }
    }
    cout << count << endl;
    return 0;
}
