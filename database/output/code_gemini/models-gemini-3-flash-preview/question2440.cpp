/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N)) return 0;

    long long current_total_time = 0;
    bool found = false;
    int found_item_index = 0;
    int found_chest_id = 0;
    long long final_time = 0;

    for (int i = 0; i < N; ++i) {
        int K;
        cin >> K;
        for (int j = 1; j <= 4; ++j) {
            string item;
            cin >> item;
            if (!found) {
                current_total_time += 5;
                if (item == "lampada") {
                    found = true;
                    found_item_index = j;
                    found_chest_id = K;
                    final_time = current_total_time;
                }
            }
        }
        if (!found) {
            current_total_time += 30;
        }
    }

    if (found) {
        long long minutes = final_time / 60;
        long long seconds = final_time % 60;
        cout << "Encontrei a lâmpada em " << minutes << "m" << seconds << "s! É o item " << found_item_index << " do baú " << found_chest_id << "!" << endl;
    } else {
        long long minutes = current_total_time / 60;
        long long seconds = current_total_time % 60;
        cout << "Perdi " << minutes << "m" << seconds << "s da minha vida e não encontrei. Desisto!" << endl;
    }

    return 0;
}