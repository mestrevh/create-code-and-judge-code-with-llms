/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> dominos(n);
    for (int i = 0; i < n; ++i) {
        cin >> dominos[i];
    }

    int a, b;
    cin >> a >> b;

    string action_code;
    cin >> action_code;

    string num_str = action_code.substr(action_code.length() - 6);
    int num1 = stoi(num_str.substr(0, 3));
    int num2 = stoi(num_str.substr(3, 3));
    int x = num1 / num2;

    string action = action_code.substr(0, action_code.length() - 6);

    bool possible = false;

    if (action == "manbr") {
        for (int domino : dominos) {
            int d1 = domino / 10;
            int d2 = domino % 10;
            if ((d1 == x && d2 == a) || (d1 == x && d2 == b) || (d2 == x && d1 == a) || (d2 == x && d1 == b)) {
                possible = true;
                break;
            }
        }
    } else if (action == "rpf") {
        for (int domino : dominos) {
            int d1 = domino / 10;
            int d2 = domino % 10;
            if (d1 == x || d2 == x) {
                possible = true;
                break;
            }
        }
    } else if (action == "rrs") {
        for (int domino : dominos) {
            int d1 = domino / 10;
            int d2 = domino % 10;
            if (d1 != x && d2 != x) {
                possible = true;
                break;
            }
             if (d1 != x || d2 != x) {
                possible = true;
                break;
            }
        }

    } else if (action == "dsfs") {
        for (int domino : dominos) {
            int d1 = domino / 10;
            int d2 = domino % 10;
            if ((d1 == a && d2 == b) || (d1 == b && d2 == a)) {
                possible = true;
                break;
            }
        }
    }

    if (possible) {
        cout << "ai maezinha" << endl;
    } else {
        cout << "cade o douze" << endl;
    }

    return 0;
}
