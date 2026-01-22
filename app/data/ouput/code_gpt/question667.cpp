/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int A, C;
    while (cin >> A >> C, A != 0 || C != 0) {
        vector<int> heights(C);
        for (int i = 0; i < C; ++i) 
            cin >> heights[i];
        
        int laser_count = 0;
        for (int i = 0; i < C; ++i) {
            if (heights[i] < A) {
                laser_count += A - heights[i];
            }
        }
        cout << laser_count << endl;
    }
    return 0;
}
