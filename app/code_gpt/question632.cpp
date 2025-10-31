/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <sstream>

using namespace std;

struct Cube {
    vector<int> faces;

    Cube(vector<int> f) : faces(f) {}

    vector<vector<int>> possibilities() const {
        vector<vector<int>> rotations;
        for (int top = 0; top < 6; ++top) {
            for (int front = 0; front < 4; ++front) {
                vector<int> current(6);
                current[0] = faces[top];
                int back = (top + 3) % 6;
                current[1] = faces[back];
                int left = (top + 1) % 6;
                current[2] = faces[left];
                int right = (top + 5) % 6;
                current[3] = faces[right];
                current[4] = faces[front == 0 ? left : (front == 1 ? right : (front == 2 ? back : top))];
                current[5] = faces[front == 3 ? left : (front == 0 ? right : (front == 1 ? back : top))];

                rotations.push_back(current);
            }
            rotate(faces.begin(), faces.begin() + top + 1, faces.end());
        }
        return rotations;
    }

    bool operator<(const Cube& other) const {
        auto rotations1 = possibilities();
        auto rotations2 = other.possibilities();
        for (const auto& r1 : rotations1) {
            for (const auto& r2 : rotations2) {
                if (r1 == r2) return true;
            }
        }
        return false;
    }
};

int main() {
    int N;
    while (cin >> N && N != 0) {
        set<Cube> uniqueCubes;
        for (int i = 0; i < N; ++i) {
            vector<int> faces(6);
            cin >> faces[0] >> faces[1] >> faces[2] >> faces[3];
            cin >> faces[4] >> faces[5];
            Cube cube(faces);
            uniqueCubes.insert(cube);
        }
        cout << uniqueCubes.size() << endl;
    }
    return 0;
}
