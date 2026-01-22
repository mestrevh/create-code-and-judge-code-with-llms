/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int main() {
    int N;
    cin >> N;
    int total_time = 0;
    bool found = false;
    int baú_encontrado = 0, item_encontrado = 0;

    for (int i = 0; i < N; ++i) {
        int K;
        string item;
        cin >> K;
        vector<string> items(4);
        for (int j = 0; j < 4; ++j) {
            cin >> items[j];
        }

        for (int j = 0; j < 4; ++j) {
            total_time += 5;
            if (items[j] == "lampada") {
                found = true;
                baú_encontrado = K;
                item_encontrado = j + 1;
                break;
            }
        }
        total_time += 30;
        if (found) break;
    }

    if (found) {
        int minutes = total_time / 60;
        int seconds = total_time % 60;
        cout << "Encontrei a lâmpada em " << minutes << "m" << seconds << "s! É o item " << item_encontrado << " do baú " << baú_encontrado << "!" << endl;
    } else {
        int minutes = total_time / 60;
        int seconds = total_time % 60;
        cout << "Perdi " << minutes << "m" << seconds << "s da minha vida e não encontrei. Desisto!" << endl;
    }
    return 0;
}
