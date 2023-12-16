#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define R_MAX 12
#define G_MAX 13
#define B_MAX 14

#define C_TO_MAX(c) (c == 'r' ? R_MAX : c == 'g' ? G_MAX : B_MAX)

void solution(const vector<string> &lines) {
  int sum = 0;
  for (const string &line : lines) {
    size_t cur = line.find(':');
    int line_num = stoi(line.substr(5, cur - 5));
    bool valid = true;
    // skip blank
    cur += 2;
    while (cur != line.npos + 1) {
      size_t int_pos = line.find(' ', cur);
      int amount = stoi(line.substr(cur, int_pos - cur));
      char colour = line.at(int_pos + 1);
      if (amount > C_TO_MAX(colour)) {
        valid = false;
        break;
      }
      cur = line.find(' ', int_pos + 1) + 1;
    }
    if (valid) {
      sum += line_num;
    }
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
