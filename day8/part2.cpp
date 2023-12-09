#include <cstdlib>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using ll = long long;
using namespace std;

ll gcd(ll a, ll b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}

ll lcm(ll a, ll b) { return (a * b) / gcd(a, b); }

void solution(const vector<string> &lines) {
  string instr = lines[0];
  map<string, pair<string, string>> map;
  for (size_t i = 2; i < lines.size(); i++) {
    string line = lines[i];
    map[line.substr(0, 3)] = make_pair(line.substr(7, 3), line.substr(12, 3));
  }

  vector<string> curs;
  for (const auto &pair : map) {
    string f = pair.first;
    if (f[2] == 'A') {
      curs.push_back(f);
    }
  }

  vector<int> stepsVec;
  for (int i = 0; i < curs.size(); i++) {
    int steps = 0;
    string cur = curs[i];
    while (cur[2] != 'Z') {
      auto it = map.find(cur);
      if (it == map.end()) {
        cout << "Key invalid" << endl;
        exit(EXIT_FAILURE);
      }
      if (instr[steps % instr.size()] == 'L') {
        cur = it->second.first;
      } else {
        cur = it->second.second;
      }
      steps++;
    }
    stepsVec.push_back(steps);
  }

  ll mult = 1;
  for (int steps : stepsVec) {
    mult = lcm(mult, steps);
  }
  cout << endl << mult << endl;
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
