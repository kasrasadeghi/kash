
#include "Shell.h"
#include <utility>
#include <string>
#include <sstream>

#include <unistd.h>

using std::string;
using std::pair;

void Shell::loop() {
  // string line;
  // while (std::getline(_in, line)) {
    // std::cout << line << std::endl;
  // }
  pair<bool, string> read = _read();
  while(read.first) {
    string eval = _eval(read.second);
    _print(eval);
    read = _read();
  }
}

pair<bool, string> Shell::_read() {
  string result;
  const auto& temp = std::getline(_in, result);
  return std::make_pair(static_cast<bool>(temp), result);
}

string Shell::_eval(const string& s) {
  //TODO fancy eval
  
  return s;
}

void Shell::_print(const string& s) {
  _out << s << std::endl;
}

void Shell::script() {
  //TODO impl
}

// std::string Shell::result() {
//   std::stringstream o;
//   o << _out.rdbuf();
//   return o.str();
// }
