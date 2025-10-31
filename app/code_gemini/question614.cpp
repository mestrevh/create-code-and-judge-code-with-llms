/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

void setup_io() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
}

struct Point {
    long long x, y;
};

struct Plant {
    long long x, y;
    int val;
};

struct Event {
    long long x;
    int y1_idx, y2_idx;
    int type; // 0 for plant, 1 for edge
    int val;

    bool operator<(const Event& other) const {
        if (x != other.x) {
            return x < other.x;
        }
        return type < other.type;
    }
};

std::vector<int> bit;
int bit_size;

void update(int idx, int delta) {
    for (; idx <= bit_size; idx += idx & -idx) {
        bit[idx] += delta;
    }
}

int query(int idx) {
    int sum = 0;
    for (; idx > 0; idx -= idx & -idx) {
        sum += bit[idx];
    }
    return sum;
}

int main() {
    setup_io();

    int p_count, v_count;
    std::cin >> p_count >> v_count;

    std::vector<Plant> plants(p_count);
    std::vector<long long> all_y;
    all_y.reserve(p_count + v_count);
    
    for (int i = 0; i < p_count; ++i) {
        std::cin >> plants[i].x >> plants[i].y;
        plants[i].val = i + 1;
        all_y.push_back(plants[i].y);
    }

    std::vector<Point> vertices(v_count);
    for (int i = 0; i < v_count; ++i) {
        std::cin >> vertices[i].x >> vertices[i].y;
        all_y.push_back(vertices[i].y);
    }

    std::sort(all_y.begin(), all_y.end());
    all_y.erase(std::unique(all_y.begin(), all_y.end()), all_y.end());

    auto get_y_idx = [&](long long y) {
        return std::lower_bound(all_y.begin(), all_y.end(), y) - all_y.begin();
    };

    std::vector<Event> events;
    events.reserve(p_count + v_count);

    for (const auto& plant : plants) {
        events.push_back({plant.x, static_cast<int>(get_y_idx(plant.y)), 0, 0, plant.val});
    }

    for (int i = 0; i < v_count; ++i) {
        Point p1 = vertices[i];
        Point p2 = vertices[(i + 1) % v_count];
        if (p1.x == p2.x) {
            long long y_min = std::min(p1.y, p2.y);
            long long y_max = std::max(p1.y, p2.y);
            events.push_back({p1.x, static_cast<int>(get_y_idx(y_min)), static_cast<int>(get_y_idx(y_max)), 1, 0});
        }
    }

    std::sort(events.begin(), events.end());

    bit_size = all_y.size();
    if (bit_size > 0) {
        bit.assign(bit_size + 1, 0);
    }
    
    long long total_outside_value = 0;

    for (const auto& e : events) {
        if (e.type == 0) {
            int crossings = query(e.y1_idx + 1);
            if (crossings % 2 == 0) {
                total_outside_value += e.val;
            }
        } else {
            update(e.y1_idx + 1, 1);
            update(e.y2_idx + 1, -1);
        }
    }

    std::cout << total_outside_value << std::endl;

    return 0;
}
