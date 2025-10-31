/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int a, g, p;
    cin >> a >> g >> p;
    
    int distance = 0, speed = 0, time = 0;

    while (g > 0) {
        distance += speed;
        g -= speed;
        speed += a;
        time++;
    }
    distance += speed;
    
    cout << distance << endl;
    cout << (distance >= p ? "S" : "N") << endl;
    
    return 0;
}
