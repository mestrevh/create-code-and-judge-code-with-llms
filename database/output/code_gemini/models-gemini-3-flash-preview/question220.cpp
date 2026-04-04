/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

const int MAX_REG = 1000000;
static bool seen[MAX_REG + 1];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N)) return 0;

    int unique_students = 0;
    int registration;

    for (int i = 0; i < N; ++i) {
        if (!(cin >> registration)) break;
        
        if (registration >= 0 && registration <= MAX_REG) {
            if (!seen[registration]) {
                seen[registration] = true;
                unique_students++;
            }
        }
    }

    cout << unique_students << "\n";

    return 0;
}