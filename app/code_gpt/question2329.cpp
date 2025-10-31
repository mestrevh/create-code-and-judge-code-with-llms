/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Friend {
    string name;
    int food;
};

void serve(vector<Friend>& friends, int index) {
    if (index < friends.size()) {
        int foodRequested = friends[index].food;
        while (foodRequested > 0) {
            friends[index].food -= 400;
            cout << friends[index].name << " foi servido(a)." << endl;
            if (friends[index].food > 0) {
                cout << "Fica tranquilo(a), " << friends[index].name << " pode se servir novamente!" << endl;
            }
            foodRequested -= 400;
        }
        serve(friends, index + 1);
    }
}

int main() {
    int N;
    cin >> N;
    vector<Friend> friends(N);
    
    for (int i = 0; i < N; i++) {
        cin >> friends[i].name >> friends[i].food;
    }

    serve(friends, 0);
    
    return 0;
}
