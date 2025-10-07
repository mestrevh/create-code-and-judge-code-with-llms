/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    int x, y, z;
    cin >> x >> y >> z;

    int octant = 0;
    if (x >= 0 && y >= 0 && z >= 0) {
        octant = 1;
    } else if (x < 0 && y >= 0 && z >= 0) {
        octant = 2;
    } else if (x < 0 && y < 0 && z >= 0) {
        octant = 3;
    } else if (x >= 0 && y < 0 && z >= 0) {
        octant = 4;
    } else if (x >= 0 && y >= 0 && z < 0) {
        octant = 5;
    } else if (x < 0 && y >= 0 && z < 0) {
        octant = 6;
    } else if (x < 0 && y < 0 && z < 0) {
        octant = 7;
    } else {
        octant = 8;
    }

    int closest_octant = octant;
    int min_dist = 1000000;

    for (int i = 1; i <= 8; i++) {
        int current_x = x, current_y = y, current_z = z;
        int current_octant = 0;

        if (i == 1) {
             current_x = abs(current_x);
             current_y = abs(current_y);
             current_z = abs(current_z);
        } else if (i == 2) {
             current_x = -abs(current_x);
             current_y = abs(current_y);
             current_z = abs(current_z);
        } else if (i == 3) {
             current_x = -abs(current_x);
             current_y = -abs(current_y);
             current_z = abs(current_z);
        } else if (i == 4) {
             current_x = abs(current_x);
             current_y = -abs(current_y);
             current_z = abs(current_z);
        } else if (i == 5) {
             current_x = abs(current_x);
             current_y = abs(current_y);
             current_z = -abs(current_z);
        } else if (i == 6) {
             current_x = -abs(current_x);
             current_y = abs(current_y);
             current_z = -abs(current_z);
        } else if (i == 7) {
             current_x = -abs(current_x);
             current_y = -abs(current_y);
             current_z = -abs(current_z);
        } else if (i == 8) {
             current_x = abs(current_x);
             current_y = -abs(current_y);
             current_z = -abs(current_z);
        }


        int dist = abs(current_x - x) + abs(current_y -y) + abs(current_z - z);

        if (dist < min_dist) {
            min_dist = dist;
            closest_octant = i;
        }
    }
    cout << closest_octant << endl;

    return 0;
}
