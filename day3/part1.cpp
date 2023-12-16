#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solution(const vector<string> &lines) {
  for (const string &line : lines) {
    cout << line << endl;
  }
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
