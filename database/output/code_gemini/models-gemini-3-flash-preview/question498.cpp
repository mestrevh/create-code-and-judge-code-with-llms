/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int total_book_pages;
    if (!(cin >> total_book_pages)) return 0;

    int last_page = 0;
    int max_daily = 0;
    int current_page = 0;

    for (int i = 0; i < 7; ++i) {
        if (!(cin >> current_page)) break;
        int daily = current_page - last_page;
        if (daily > max_daily) {
            max_daily = daily;
        }
        last_page = current_page;
    }

    cout << last_page << "\n" << max_daily << endl;

    return 0;
}