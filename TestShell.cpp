#include <gtest/gtest.h>
#include <iostream>
#include <sstream>

#include "Shell.h"

using namespace std;

TEST(Shell, startup) {
  istringstream in("line one\nline two");
  ostringstream out;
  Shell shell(in, out);
  shell.loop();
  ASSERT_EQ(out.str(), "line one\nline two\n");
}
