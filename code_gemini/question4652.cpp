/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string line;
    getline(cin, line);

    int start = 0;
    while (start < line.length() && line[start] == ' ') {
        start++;
    }

    int end = line.length() - 1;
    while (end >= 0 && line[end] == ' ') {
        end--;
    }

    if (start <= end) {
        cout << line.substr(start, end - start + 1) << endl;
    } else {
        cout << "" << endl;
    }

    return 0;
}
