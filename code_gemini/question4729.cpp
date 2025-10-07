/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <list>

using namespace std;

int main() {
    int n;
    cin >> n;

    list<int> balls;
    for (int i = 0; i < n; ++i) {
        int ball;
        cin >> ball;
        balls.push_back(ball);
    }

    int m;
    cin >> m;

    for (int i = 0; i < m; ++i) {
        int pos, val;
        cin >> pos >> val;

        auto it = balls.begin();
        advance(it, pos - 1);
        balls.insert(it, val);

        it = balls.begin();
        advance(it, pos);

        int current_val = *it;
        int count = 0;
        auto start = it;
        auto end = it;

        while (start != balls.begin() && *prev(start) == current_val) {
            --start;
            ++count;
        }
        ++count;
        while (next(end) != balls.end() && *next(end) == current_val) {
            ++end;
            ++count;
        }

         if (it != balls.begin() && *prev(it) == current_val) {
            balls.erase(start, next(end));
        } else if (next(it) != balls.end() && *next(it) == current_val) {
            balls.erase(start, next(end));
         }


    }

    for (int ball : balls) {
        cout << ball << " ";
    }
    cout << endl;

    return 0;
}
