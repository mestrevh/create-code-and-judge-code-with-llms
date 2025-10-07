/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    int position = 1, rolls = 0, die = 1;
    
    while (position < N) {
        rolls++;
        position += die;
        die = die % 6 + 1;
        if (position > N) {
            position = position - N;
        }
    }
    
    cout << rolls << endl;
    return 0;
}
