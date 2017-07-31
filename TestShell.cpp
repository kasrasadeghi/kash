#include <gtest/gtest.h>
#include <iostream>
#include <sstream>

#include "Shell.h"

using namespace std;

TEST(Shell, startup) {
  istringstream in("");
  ostringstream out;
  Shell shell(in, out);
  shell.loop();
}