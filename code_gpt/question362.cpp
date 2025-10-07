/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> score(5, 0);
    int M, N;

    for (int i = 0; i < 15; ++i) {
        cin >> M >> N;
        if (M > N) score[i % 4]++; // vitória para a equipe da esquerda
        else if (N > M) score[i % 4 + 1]++; // vitória para a equipe da direita
    }

    int champion = (score[0] >= score[1] && score[0] >= score[2] && score[0] >= score[3]) ? 0 :
                   (score[1] >= score[0] && score[1] >= score[2] && score[1] >= score[3]) ? 1 :
                   (score[2] >= score[0] && score[2] >= score[1] && score[2] >= score[3]) ? 2 : 3);
    
    cout << (char)('A' + champion) << endl;

    return 0;
}
