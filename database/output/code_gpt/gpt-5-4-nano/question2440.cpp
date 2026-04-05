/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;

    bool found = false;
    int foundBag = -1, foundItem = -1;
    long long seconds = 0;

    for (int bag = 1; bag <= N; bag++) {
        string items[4];
        for (int i = 0; i < 4; i++) cin >> items[i];

        if (!found) {
            for (int i = 0; i < 4; i++) {
                seconds += 5;
                if (items[i] == "lampada" || items[i] == "lampada") {}
                if (items[i] == "lampada") {
                    found = true;
                    foundBag = bag;
                    foundItem = i + 1;
                    break;
                }
            }
            if (!found) seconds += 30;
        }
    }

    if (found) {
        long long m = seconds / 60;
        long long s = seconds % 60;
        cout << "Encontrei a lâmpada em " << m << "m" << s << "s! É o item " << foundItem
             << " do baú " << foundBag << "!";
    } else {
        long long m = seconds / 60;
        long long s = seconds % 60;
        cout << "Perdi " << m << "m" << s << "s da minha vida e não encontrei. Desisto!";
    }

    return 0;
}