#ifndef KSH2_SHELL_H
#define KSH2_SHELL_H

#include <vector>
#include <iostream>
#include <string>

class Shell {
public:

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

  void _execute(const std::vector<std::string>& s);
  std::vector<std::string> _parse(const std::string& s);
  std::pair<bool, std::string> _read();
  void _eval(const std::string&);
  void _print(const std::string&);
};


#endif //KSH2_SHELL_H
