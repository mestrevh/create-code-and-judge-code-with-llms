/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Wire {
    char color;
    char label;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<Wire> connected;
    char c;
    for (int i = 0; i < 6; ++i) {
        if (!(cin >> c)) break;
        if (c != 'x') {
            connected.push_back({c, (char)('a' + i)});
        }
    }

    int n = connected.size();
    char result = ' ';

    if (n == 4) {
        bool has_red = false;
        for (const auto& w : connected) {
            if (w.color == 'r') {
                has_red = true;
                break;
            }
        }
        if (!has_red) {
            result = connected[1].label;
        } else if (connected.back().color == 'b') {
            result = connected.back().label;
        } else {
            result = connected[0].label;
        }
    } else if (n == 5) {
        if (connected[0].color == 'y' && connected[1].color == 'y') {
            result = connected[0].label;
        } else {
            result = connected[1].label;
        }
    } else if (n == 6) {
        int green_count = 0;
        char green_label = ' ';
        for (const auto& w : connected) {
            if (w.color == 'g') {
                green_count++;
                green_label = w.label;
            }
        }
        if (green_count == 1) {
            result = green_label;
        } else {
            result = connected[4].label;
        }
    }

    if (result != ' ') {
        cout << "corta " << result << endl;
    }

    return 0;
}