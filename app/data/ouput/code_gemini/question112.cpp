/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <sstream>

std::string format_y_label(int num) {
    std::stringstream ss;
    ss << std::setw(3) << std::right << num << " +";
    return ss.str();
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<int> frequencies(10, 0);
    int ignored_count = 0;

    for (int i = 0; i < n; ++i) {
        double value;
        std::cin >> value;

        if (value < 0.0 || value > 10.0) {
            ignored_count++;
        } else if (value == 0.0) {
            frequencies[0]++;
        } else {
            int index = static_cast<int>(ceil(value)) - 1;
            if (index >= 0 && index < 10) {
                frequencies[index]++;
            } else {
                 ignored_count++;
            }
        }
    }

    int max_freq = 0;
    for (int freq : frequencies) {
        if (freq > max_freq) {
            max_freq = freq;
        }
    }

    if (max_freq == 0) {
        max_freq = 1;
    }

    std::vector<int> heights(10);
    for (int i = 0; i < 10; ++i) {
        heights[i] = static_cast<long long>(frequencies[i]) * 20 / max_freq;
    }

    int canvas_height = 23;
    int canvas_width = 60;
    std::vector<std::string> canvas(canvas_height, std::string(canvas_width, ' '));

    int y_axis_col = 5;
    int bar_start_col = 7;

    for (int i = 0; i < 10; ++i) {
        int h = heights[i];
        if (h == 0) continue;

        int bar_x_base = bar_start_col + i * 4;

        for (int y = 1; y <= h; ++y) {
            int row = 21 - y;
            canvas[row][bar_x_base] = '|';
            canvas[row][bar_x_base + 2] = '|';
        }

        canvas[21 - h][bar_x_base + 1] = '_';

        for (int y = 1; y < h; ++y) {
            int row = 21 - y;
            canvas[row][bar_x_base + 1] = '*';
        }
    }

    canvas[0][y_axis_col] = '^';
    for (int row = 1; row <= 20; ++row) {
        canvas[row][y_axis_col] = '|';
    }

    std::string lbl_max = format_y_label(max_freq);
    canvas[1].replace(0, lbl_max.length(), lbl_max);

    std::string lbl_q3 = format_y_label(max_freq * 3 / 4);
    canvas[6].replace(0, lbl_q3.length(), lbl_q3);

    std::string lbl_q2 = format_y_label(max_freq / 2);
    canvas[11].replace(0, lbl_q2.length(), lbl_q2);

    std::string lbl_q1 = format_y_label(max_freq / 4);
    canvas[16].replace(0, lbl_q1.length(), lbl_q1);

    std::string lbl_0 = format_y_label(0);
    canvas[21].replace(0, lbl_0.length(), lbl_0);

    int row_x_axis = 21;
    int tick_5_col = 26;
    int tick_10_col = 45;

    for (int c = y_axis_col + 1; c < tick_5_col; ++c) canvas[row_x_axis][c] = '-';
    canvas[row_x_axis][tick_5_col] = '+';
    for (int c = tick_5_col + 1; c < tick_10_col; ++c) canvas[row_x_axis][c] = '-';
    canvas[row_x_axis][tick_10_col] = '+';
    canvas[row_x_axis][tick_10_col + 1] = '-';
    canvas[row_x_axis][tick_10_col + 2] = '>';

    int row_x_labels = 22;
    canvas[row_x_labels].replace(7, 3, "0.0");
    canvas[row_x_labels].replace(25, 3, "5.0");
    canvas[row_x_labels].replace(43, 4, "10.0");

    for (const std::string& line : canvas) {
        size_t last_char = line.find_last_not_of(' ');
        if (last_char == std::string::npos) {
            std::cout << '\n';
        } else {
            std::cout << line.substr(0, last_char + 1) << '\n';
        }
    }

    std::cout << "Valores ignorados: " << ignored_count << '\n';

    return 0;
}
