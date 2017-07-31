
#include "Shell.h"
#include <utility>
#include <string>

void Shell::loop() {
  while(_read().first) {
    _eval();
    _print();
  }
}

std::pair<bool, std::string> Shell::_read() {
  std::string result;
  return std::pair<bool, std::string>(static_cast<bool>(std::getline(_in, result)), result);
}

void Shell::_eval() {

}

void Shell::_print() {

}

void Shell::script() {

}

std::string Shell::result() {

}