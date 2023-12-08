#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solution(const vector<string> &lines) {
  int sum = 0;
  for (const string &line : lines) {
    for (char c : line) {
      if (isdigit(c)) {
        sum += 10 * (c - '0');
        break;
      }
    }
    for (auto it = line.rbegin(); it != line.rend(); ++it) {
      char c = *it;
      if (isdigit(c)) {
        sum += c - '0';
        break;
      }
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
