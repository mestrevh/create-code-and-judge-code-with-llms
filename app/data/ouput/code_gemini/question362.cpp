/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/4>thought
I need to write a C++ program for a competitive programming problem.

Here's a thinking process that leads to the final C++ code:

1.  **Deconstruct the Request:**
    *   **Role:** Competitive programming expert in C++.
    *   **Task:** Write a C++ program for the "Copa do Mundo" (World Cup) problem.
    *   **Input Format:** A string with HTML tags. I need to parse this to understand the problem.
    *   **Output Format:** ONLY the C++ code, no comments, no extra text.
    *   **Constraint:** 1-second time limit. This isn't a major concern for this problem, as the input size is fixed and small.

2.  **Analyze the Problem Description (from the HTML):**
    *   **Title:** Copa do Mundo (World Cup).
    *   **Topics:** `obi`, `array`, `função` (function). This hints that an array-based solution, possibly using functions, is expected. `obi` stands for Olimpíada Brasileira de Informática, a Brazilian competitive programming contest, so the problem is likely straightforward and well-defined.
    *   **Core Logic:** The problem describes a 16-team single-elimination tournament (like the knockout stage of the World Cup). There are 15 games in total. I'm given the results of these 15 games in a specific order and need to determine the final champion.
    *   **The Bracket:** The image is crucial. It shows the structure of the tournament.
        *   **Round of 16 (Oitavas de final):**
            *   Game 1: Team A vs. Team B
            *   Game 2: Team C vs. Team D
            *   Game 3: Team E vs. Team F
            *   Game 4: Team G vs. Team H
            *   Game 5: Team I vs. Team J
            *   Game 6: Team K vs. Team L
            *   Game 7: Team M vs. Team N
            *   Game 8: Team O vs. Team P
        *   **Quarter-finals (Quartas de final):**
            *   Game 9: Winner of Game 1 vs. Winner of Game 2
            *   Game 10: Winner of Game 3 v.s Winner of Game 4
            *   Game 11: Winner of Game 5 vs. Winner of Game 6
            *   Game 12: Winner of Game 7 vs. Winner of Game 8
        *   **Semi-finals (Semifinais):**
            *   Game 13: Winner of Game 9 vs. Winner of Game 10
            *   Game 14: Winner of Game 11 vs. Winner of Game 12
        *   **Final:**
            *   Game 15: Winner of Game 13 vs. Winner of Game 14
    *   **Input Format:**
        *   15 lines of input.
        *   Each line has two integers, `M` and `N`.
        *   `M` is the score of the team on the left side of the bracket for that game.
        *   `N` is the score of the team on the right side of the bracket for that game.
        *   The lines correspond to the games in order: line 1 is game 1, line 2 is game 2, ..., line 15 is game 15.
        *   There are no ties. If `M > N`, the left team wins. If `N > M`, the right team wins.
    *   **Output Format:**
        *   A single character representing the winning team (from 'A' to 'P').
        *   Followed by a newline.

3.  **Develop a Solution Strategy:**
    *   I need to simulate the tournament round by round.
    *   A good way to represent the teams is with their initial labels: 'A', 'B', 'C', ..., 'P'.
    *   I can use a data structure to hold the teams currently in the tournament. A `std::vector` or `std::queue` would work well. Let's go with a `std::queue` as it naturally models the "first-in, first-out" nature of processing pairs of teams for a match.
    *   **Initial State:** Create a queue and populate it with the 16 teams: 'A', 'B', 'C', ..., 'P'.
    *   **Simulation Loop:** The tournament proceeds in rounds.
        *   **Round of 16:** 8 games.
        *   **Quarter-finals:** 4 games.
        *   **Semi-finals:** 2 games.
        *   **Final:** 1 game.
        *   Total games = 8 + 4 + 2 + 1 = 15. This matches the input.
    *   **Processing a Round:**
        *   I'll need a second queue (or a temporary vector) to store the winners of the current round. Let's call it `winners`.
        *   As long as the main queue (`teams`) is not empty, I'll:
            1.  Dequeue two teams, let's call them `team1` and `team2`.
            2.  Read the next game's score from the input (`M` and `N`).
            3.  If `M > N`, `team1` wins. Add `team1` to the `winners` queue.
            4.  If `N > M`, `team2` wins. Add `team2` to the `winners` queue.
        *   After processing all the games in the round, the `teams` queue will be empty. The `winners` queue now contains the teams for the next round. I can swap the contents or assign `winners` back to `teams` and clear `winners` for the next round.
    *   **Looping through all games:** Instead of thinking in rounds, I can just process the 15 games sequentially. I'll need a way to manage the teams advancing.
        *   Let's use a queue of characters.
        *   Initialize the queue with 'A' through 'P'.
        *   Loop 15 times (for the 15 games).
        *   In each iteration:
            *   Read the scores `M` and `N`.
            *   Pop the first team from the queue (`team1`).
            *   Pop the second team from the queue (`team2`).
            *   If `M > N`, push `team1` back onto the queue.
            *   Else (`N > M`), push `team2` back onto the queue.
    *   **Final Result:** After the loop finishes (after 15 games), the queue will contain exactly one element: the champion. I just need to print this character.

4.  **Refine the Implementation Details (C++):**
    *   **Includes:** I'll need `<iostream>` for input/output and `<queue>` for the queue data structure. Maybe `<vector>` if I chose that instead, but queue seems more elegant.
    *   **Main function:** `int main() { ... }`
    *   **Input/Output Speed:** For competitive programming, it's good practice to speed up I/O, although for this small problem, it's not strictly necessary. `std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);`
    *   **Initialization:**
        ```cpp
        std::queue<char> teams;
        for (char team = 'A'; team <= 'P'; ++team) {
            teams.push(team);
        }
        ```
    *   **Game Loop:**
        ```cpp
        for (int i = 0; i < 15; ++i) {
            int m, n;
            std::cin >> m >> n;
            char team1 = teams.front();
            teams.pop();
            char team2 = teams.front();
            teams.pop();
            if (m > n) {
                teams.push(team1);
            } else {
                t
eams.pus
h(team2);
            }
        }
        ```
    *   **Output:**
        ```cpp
        std::cout << teams.front() << std::endl;
        ```
    *   **Putting it all together:**

        ```cpp
        #include <iostream>
        #include <queue>

        int main() {
            std::ios_base::sync_with_stdio(false);
            std::cin.tie(NULL);

            std::queue<char> teams;
            for (char team = 'A'; team <= 'P'; ++team) {
                teams.push(team);
            }

            for (int i = 0; i < 15; ++i) {
                int m, n;
                std::cin >> m >> n;
                char team1 = teams.front();
                teams.pop();
                char team2 = teams.front();
                teams.pop();
                if (m > n) {
                    teams.push(team1);
                } else {
                    teams.push(team2);
                }
            }

            std::cout << teams.front() << std::endl;

            return 0;
        }
        ```

5.  **Final Review:**
    *   Does this code solve the problem? Yes, it correctly simulates the tournament bracket game by game. The order of games in the input matches the order in which teams are pulled from the queue.
    *   Does it meet the output format? Yes, it prints a single character followed by a newline.
    *   Is it efficient? Yes, the time complexity is O(1) because the number of operations is constant (15 games, 16 teams). It will easily pass within the 1-second time limit.
    *   Does it follow the request to be "only the code"? Yes. I will remove the comments and any extra text before outputting the final answer. The `ios_base` lines are good practice and can be kept.

This thought process directly leads to the provided C++ solution. The logic is simple, and the `std::queue` data structure is a perfect fit for modeling the progression of teams through the bracket.<ctrl95>```cpp
#include <iostream>
#include <queue>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::queue<char> teams;
    for (int i = 0; i < 16; ++i) {
        teams.push('A' + i);
    }
    for (int i = 0; i < 15; ++i) {
        int m, n;
        std::cin >> m >> n;
        char team1 = teams.front();
        teams.pop();
        char team2 = teams.front();
        teams.pop();
        if (m > n) {
            teams.push(team1);
        } else {
            teams.push(team2);
        }
    }
    std::cout << teams.front() << std::endl;
    return 0;
}
