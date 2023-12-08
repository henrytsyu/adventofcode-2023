#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <tuple>
#include <vector>

using namespace std;

int cardToStrength(const char c) {
  switch (c) {
    case 'A':
      return 14;
      break;
    case 'K':
      return 13;
      break;
    case 'Q':
      return 12;
      break;
    case 'J':
      return 1;
      break;
    case 'T':
      return 10;
      break;
    default:
      return c - '0';
  }
}

int handToStrength(const string str) {
  map<char, int> freq;
  int joker = 0;
  for (char c : str) {
    if (c == 'J') {
      joker++;
    } else {
      freq[c]++;
    }
  }
  if (joker == 5) {
    return 7;
  }
  vector<int> freqVec;
  for (const auto &pair : freq) {
    freqVec.push_back(pair.second);
  }
  sort(freqVec.begin(), freqVec.end(), std::greater<int>());
  freqVec[0] += joker;
  if (freqVec[0] == 5) return 7;
  if (freqVec[0] == 4) return 6;
  if (freqVec[0] == 3 && freqVec[1] == 2) return 5;
  if (freqVec[0] == 3) return 4;
  if (freqVec[0] == 2 && freqVec[1] == 2) return 3;
  if (freqVec[0] == 2) return 2;
  return 1;
}

void solution(const vector<string> &lines) {
  int sum = 0;
  vector<tuple<int, int, int, int, int, int, int>> strength;
  for (const string &line : lines) {
    strength.push_back(make_tuple(
      handToStrength(line.substr(0, 5)),
      cardToStrength(line[0]),
      cardToStrength(line[1]),
      cardToStrength(line[2]),
      cardToStrength(line[3]),
      cardToStrength(line[4]),
      stoi(line.substr(6))
    ));
  }
  sort(strength.begin(), strength.end());
  for (int i = 0; i < strength.size(); i++) {
    sum += (i + 1) * get<6>(strength[i]);
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
