#include <iostream>
#include "Shell.h"

int main() {
  Shell shell(std::cin, std::cout);
  shell.loop();
}