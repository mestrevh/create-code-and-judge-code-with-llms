/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>

struct Cube {
    std::vector<int> f;

    Cube(const std::vector<int>& faces) : f(faces) {}

    void turn() {
        int t2 = f[2], t3 = f[3], t4 = f[4], t5 = f[5];
        f[2] = t4;
        f[5] = t2;
        f[3] = t5;
        f[4] = t3;
    }

    void roll() {
        int t0 = f[0], t1 = f[1], t2 = f[2], t3 = f[3];
        f[0] = t2;
        f[2] = t1;
        f[1] = t3;
        f[3] = t0;
    }
};

std::vector<int> get_canonical(const std::vector<int>& initial_faces) {
    std::set<std::vector<int>> all_orientations;
    std::queue<std::vector<int>> q;

    all_orientations.insert(initial_faces);
    q.push(initial_faces);

    while (!q.empty()) {
        std::vector<int> current_faces = q.front();
        q.pop();
        
        Cube current(current_faces);

        Cube rolled = current;
        rolled.roll();
        if (all_orientations.find(rolled.f) == all_orientations.end()) {
            all_orientations.insert(rolled.f);
            q.push(rolled.f);
        }

        Cube turned = current;
        turned.turn();
        if (all_orientations.find(turned.f) == all_orientations.end()) {
            all_orientations.insert(turned.f);
            q.push(turned.f);
        }
    }
    
    return *all_orientations.begin();
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N;
    while (std::cin >> N && N != 0) {
        std::set<std::vector<int>> distinct_cubes;
        for (int i = 0; i < N; ++i) {
            std::vector<int> faces(6);
            std::cin >> faces[0];
            std::cin >> faces[2] >> faces[5] >> faces[3] >> faces[4];
            std::cin >> faces[1];
            distinct_cubes.insert(get_canonical(faces));
        }
        std::cout << distinct_cubes.size() << std::endl;
    }
    return 0;
}
