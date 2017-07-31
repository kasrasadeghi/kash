//
// Created by kasra on 7/28/17.
//

#ifndef KSH2_SHELL_H
#define KSH2_SHELL_H


#include <iostream>
#include <string>

class Shell {
public:
  Shell(std::istream& in, std::ostream& out): _in(in), _out(out) {}

  /**
   * the standard looping behaviour with cin and cout
   *
   * loops until end of cin
   */
  void loop();

  /**
   * //TODO MAYBE
   * runs a script with a filename
   */
  void script();

  /**
   * //TODO MAYBE
   * returns the result that the output stream maybe hold
   */
  std::string result();

private:

  std::pair<bool, std::string> _read();
  void _eval();
  void _print();

  std::istream& _in = std::cin;
  std::ostream& _out = std::cout;
};


#endif //KSH2_SHELL_H
