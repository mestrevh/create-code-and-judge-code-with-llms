/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string s;
    cin >> s;

    int connected_count = 0;
    for (char c : s) {
        if (c != 'x') {
            connected_count++;
        }
    }

    if (connected_count == 4) {
        bool has_red = false;
        for (char c : s) {
            if (c == 'r') {
                has_red = true;
                break;
            }
        }

        if (!has_red) {
            int count = 0;
            for (int i = 0; i < 6; ++i) {
                if (s[i] != 'x') {
                    count++;
                    if (count == 2) {
                        cout << "corta " << (char)('a' + i) << endl;
                        return 0;
                    }
                }
            }
        } else {
            if (s[5] == 'b') {
                cout << "corta f" << endl;
                return 0;
            } else {
                for (int i = 0; i < 6; ++i) {
                    if (s[i] != 'x') {
                        cout << "corta " << (char)('a' + i) << endl;
                        return 0;
                    }
                }
            }
        }
    } else if (connected_count == 5) {
        if (s[0] == 'y' && s[1] == 'y') {
            cout << "corta a" << endl;
            return 0;
        } else {
            int count = 0;
            for (int i = 0; i < 6; ++i) {
                if (s[i] != 'x') {
                    count++;
                    if (count == 2) {
                        cout << "corta " << (char)('a' + i) << endl;
                        return 0;
                    }
                }
            }
        }
    } else if (connected_count == 6) {
        int green_count = 0;
        for (char c : s) {
            if (c == 'g') {
                green_count++;
            }
        }

        if (green_count == 1) {
            for (int i = 0; i < 6; ++i) {
                if (s[i] == 'g') {
                    cout << "corta " << (char)('a' + i) << endl;
                    return 0;
                }
            }
        } else {
            int count = 0;
            for (int i = 0; i < 6; ++i) {
                if (s[i] != 'x') {
                    count++;
                    if (count == 5) {
                        cout << "corta " << (char)('a' + i) << endl;
                        return 0;
                    }
                }
            }
        }
    }

    return 0;
}
