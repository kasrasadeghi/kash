#ifndef KSH2_SHELL_H
#define KSH2_SHELL_H

#include <vector>
#include <iostream>
#include <string>

using std::string;
using std::vector;
using std::pair;

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
  pair<bool, string> _read   ();
  void               _eval   (const string&);

  vector<string>     _split  (const string& s);
  
  bool               _builtin(const vector<string>& cmd);
  void          _exec_builtin(const vector<string>& cmd);
  
  void               _parse  (vector<string>& s);
  void          _exec_program(vector<string>& cmd);
  
  void               _print  (const string&);
};


#endif //KSH2_SHELL_H
