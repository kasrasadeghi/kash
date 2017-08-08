
#include "Shell.h"
#include <algorithm>
#include <utility>
#include <string>
#include <sstream>
#include <vector>

#include <unistd.h>   // fork, chdir, getcwd
#include <sys/wait.h> // wait

using std::vector;
using std::string;
using std::pair;
using std::cin;
using std::cout;
using std::endl;

void Shell::loop() {
  pair<bool, string> read = _read();
  while(read.first) {
    _eval(read.second);
    read = _read();
  }
  cout << endl;
}

pair<bool, string> Shell::_read() {
  cout << get_current_dir_name() << endl;
  cout << " $ ";
  string result;
  const auto& temp = std::getline(cin, result);
  return std::make_pair(static_cast<bool>(temp), result);
}

vector<string> Shell::_parse(const string& s) {
  vector<string> split;
  string acc;
  for (char c : s) {
    if (isspace(c)) {
      if (acc == "") continue; 
      split.push_back(acc);
      acc = "";
    } else {
      acc += c;
    }
  }
  if (acc.length() != 0) split.push_back(acc);
  return split;
}

void Shell::_eval(const string& s) {
  
  vector<string> split = _parse(s);

  if (split.size() == 0) {
    return;
  }

  if (_builtin(split)) {
    _exec_builtin(split);
    return;
  }
  
  _exec_program(split);
}

bool Shell::_builtin(const vector<string>& split) {
  return split[0] == "cd" or split[0] == "l";
}

void Shell::_exec_builtin(const vector<string>& split) {
  if (split[0] == "cd") {
    if (split.size() != 2) {
      //TODO set error message somehow and then do perror
      return;
    }
    chdir(split[1].c_str());
    return;
  }
  
  if (split[0] == "l") {
    vector<string> colored_ls;
    colored_ls.push_back("ls");
    colored_ls.push_back("--color");
    colored_ls.push_back("-F");
    if (split.size() > 1) {
      std::copy(split.begin() + 1, split.end(), back_inserter(colored_ls));
    }
    _exec_program(colored_ls);
    return;
  }
}

void Shell::_exec_program(const vector<string>& split) {
  int rc = fork();
  if (rc < 0) {
    cout << "fork failed" << endl;
    exit(1);
  } else if (rc == 0) {
    // TODO check for input pipe
    // cout << "STDOUT_FILENO: " << STDOUT_FILENO << endl;
    // cout << "STDIN_FILENO: " << STDIN_FILENO << endl;
    // close(STDOUT_FILENO);
    
    size_t count = split.size();
    char* args[count + 1];
    for (size_t i = 0; i < count; ++i) {
      args[i] = const_cast<char*>(split[i].c_str());
    }
    
    args[count] = 0;
    int result = execvp(args[0], args);
    if (result < 0) {
      perror("kash");
      exit(0); 
    }
  } else {
    wait(0);
  }
  
}

void Shell::_print(const string& s) {
  cout << s << endl;
}

void Shell::script() {
  //TODO impl
}
