/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <queue>

using namespace std;

void process_case(int N, int M) {
    unordered_map<string, vector<string>> prerequisites;
    set<string> all_courses;
    unordered_map<string, int> indegree;
    vector<string> ordered_courses;
    
    for (int i = 0; i < N; ++i) {
        string course;
        cin >> course;
        int K;
        cin >> K;
        all_courses.insert(course);
        ordered_courses.push_back(course);
        indegree[course] = 0;
        while (K--) {
            string prereq;
            cin >> prereq;
            prerequisites[prereq].push_back(course);
            indegree[course]++;
            all_courses.insert(prereq);
        }
    }

    vector<string> semester_courses;
    queue<string> q;
    for (const auto& course : all_courses) {
        if (indegree[course] == 0) {
            q.push(course);
        }
    }
    
    int semesters = 0;
    vector<vector<string>> output;
    
    while (!q.empty()) {
        semesters++;
        vector<string> current_semester;
        while (!q.empty() && current_semester.size() < M) {
            string course = q.front();
            q.pop();
            current_semester.push_back(course);
            for (const string& next : prerequisites[course]) {
                indegree[next]--;
                if (indegree[next] == 0) {
                    q.push(next);
                }
            }
        }
        sort(current_semester.begin(), current_semester.end());
        output.push_back(current_semester);
    }

    cout << "Formatura em " << semesters << " semestres" << endl;
    for (int i = 0; i < output.size(); ++i) {
        cout << "Semestre " << (i + 1) << " :";
        for (const string& course : output[i]) {
            cout << " " << course;
        }
        cout << endl;
    }
}

int main() {
    while (true) {
        int N, M;
        cin >> N >> M;
        if (N == 0 && M == 0) break;
        process_case(N, M);
    }
    return 0;
}
