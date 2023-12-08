#include <cstdlib>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

void solution(const vector<string> &lines) {
  string instr = lines[0];
  map<string, pair<string, string>> map;
  for (size_t i = 2; i < lines.size(); i++) {
    string line = lines[i];
    map[line.substr(0, 3)] = make_pair(line.substr(7, 3), line.substr(12, 3));
  }

  int steps = 0;
  string cur = "AAA";
  while (cur != "ZZZ") {
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
  cout << steps << endl;
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
