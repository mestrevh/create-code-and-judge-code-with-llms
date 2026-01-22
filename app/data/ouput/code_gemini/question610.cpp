/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

std::ostream& operator<<(std::ostream& os, __int128_t value) {
    if (value == 0) {
        return os << "0";
    }
    std::string s = "";
    bool neg = value < 0;
    if (neg) {
        value = -value;
    }
    while (value > 0) {
        s += (char)((value % 10) + '0');
        value /= 10;
    }
    if (neg) {
        s += '-';
    }
    std::reverse(s.begin(), s.end());
    return os << s;
}

using int128 = __int128_t;

struct Point {
    int128 x, y;
};

int128 cross(const Point& a, const Point& b) {
    return a.x * b.y - a.y * b.x;
}

int N;
std::vector<Point> p;
std::vector<int128> prefix_cross;

int128 get_2_area(int i, int j) {
    return (prefix_cross[j] - prefix_cross[i]) + cross(p[j], p[i]);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> N;
    p.resize(2 * N);
    for (int i = 0; i < N; ++i) {
        long long px, py;
        std::cin >> px >> py;
        p[i] = {px, py};
    }
    for (int i = 0; i < N; ++i) {
        p[i + N] = p[i];
    }

    prefix_cross.resize(2 * N, 0);
    for (int i = 0; i < 2 * N - 1; ++i) {
        prefix_cross[i + 1] = prefix_cross[i] + cross(p[i], p[i + 1]);
    }

    int128 total_2_area = 0;
    for (int i = 0; i < N; ++i) {
        total_2_area += cross(p[i], p[(i + 1) % N]);
    }

    int128 carol_max_gain_2 = 0;
    int j = 1;

    for (int i = 0; i < N; ++i) {
        j = std::max(j, i + 1);

        while (j + 1 < i + N - 1 && get_2_area(i, j + 1) * 2 <= total_2_area) {
            j++;
        }

        int128 current_carol_min_gain_2 = -1;

        if (j >= i + 2 && j <= i + N - 2) {
            int128 area1 = get_2_area(i, j);
            int128 gain1 = std::max(area1, total_2_area - area1);
            current_carol_min_gain_2 = gain1;
        }

        if (j + 1 >= i + 2 && j + 1 <= i + N - 2) {
            int128 area2 = get_2_area(i, j + 1);
            int128 gain2 = std::max(area2, total_2_area - area2);
            if (current_carol_min_gain_2 == -1 || gain2 < current_carol_min_gain_2) {
                current_carol_min_gain_2 = gain2;
            }
        }
        
        if (current_carol_min_gain_2 != -1) {
            carol_max_gain_2 = std::max(carol_max_gain_2, current_carol_min_gain_2);
        }
    }
    
    int128 carol_vol = carol_max_gain_2;
    int128 carla_vol = total_2_area - carol_vol;
    
    std::cout << carol_vol << " " << carla_vol << std::endl;

    return 0;
}
