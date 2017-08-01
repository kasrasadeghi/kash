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

private:

  std::pair<bool, std::string> _read();
  std::string _eval(const std::string&);
  void _print(const std::string&);

  std::istream& _in = std::cin;
  std::ostream& _out = std::cout;
};


#endif //KSH2_SHELL_H
