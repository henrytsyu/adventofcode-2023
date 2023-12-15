#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using ll = long long;
using namespace std;

bool all_zeros(const vector<int> &v) {
  for (int i : v) {
    if (i != 0) return false;
  }
  return true;
}

void solution(const vector<string> &lines) {
  ll sum = 0;
  for (const string &line : lines) {
    vector<vector<int>> sequences;
    string s;
    stringstream ss(line);
    vector<int> v;
    while (getline(ss, s, ' ')) {
      v.push_back(stoi(s));
    }
    sequences.push_back(v);
    while (!all_zeros(sequences.back())) {
      vector<int> u;
      vector<int> back = sequences.back();
      for (int i = 1; i < back.size(); i++) {
        u.push_back(back[i] - back[i - 1]);
      }
      sequences.push_back(u);
    }
    for (int i = sequences.size() - 2; i > 0; i--) {
      sequences[i - 1].push_back(sequences[i - 1].back() + sequences[i].back());
    }
    sum += sequences[0].back();
  }
  cout << sum << endl;
}

int main() {
  ifstream file("input.txt");

  if (!file.is_open()) {
    cout << "Unable to open file" << endl;
    return EXIT_FAILURE;
  }

  vector<string> lines;

  string line;
  while (getline(file, line)) {
    lines.push_back(line);
  }

  file.close();

  solution(lines);

  return EXIT_SUCCESS;
}
