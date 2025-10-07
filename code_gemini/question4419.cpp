/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    char dir;
    int dist;
    int pos = 10;
    vector<string> mapa(10, "....................");

    while (cin >> dir && dir != 'x') {
        cin >> dist;
        if (dir == 'd') {
            for (int i = 0; i < dist; ++i) {
                mapa[pos - 1][10 + i] = '>';
            }
            pos--;
        } else if (dir == 'e') {
            for (int i = 0; i < dist; ++i) {
                mapa[pos -1][10 - i -1] = '<';
            }
            pos++;

        } else if (dir == 'f') {
           for(int i = 0; i < dist; ++i) {
               mapa[pos - 1 - (i+1)][10 + (pos < 11? 10-pos: pos -11)] = '|';

           }
        }
    }
     mapa[pos - 1][10 + (pos < 11? 10-pos: pos -11)] = 'x';
    for (const string& line : mapa) {
        cout << line << endl;
    }

    return 0;
}
