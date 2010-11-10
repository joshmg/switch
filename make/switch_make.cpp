// File: switch_make.cpp
// Written by Joshua Green

#include <iostream>
#include <string>

#include "fileio/fileio.h"
#include "str/str.h"
using namespace std;

int main() {
  bool switch_case;
  cout << "Switch or If/Else? (Switch/If) ";
  string c;
  getline(cin, c);
  switch_case = (c[0] == 'S') || (c[0] == 's');

  if (switch_case) cout << "Building Switch code..." << endl;
  else cout << "Building If/Else code..." << endl;

  int num_cases;
  cout << "Number of cases: ";
  cin >> num_cases;

  if (num_cases < 1) num_cases = 1;

  string filename(itos(num_cases));
  if (switch_case) filename += "_switch";
  else filename += "_ifelse";
  filename += "_cases._cpp";
  fileio output;
  output.open(filename, "w");

  /*
  int trivial_op = 0;
  switch (value) {
    case \i: { ++trivial_op; } break;
    default: { } break;
  }
  */

  string header = "  int ";
  if (switch_case) header += "switch";
  else header += "ifelse";
  header += "_value = ";
  header += itos(num_cases-1);
  header += ";\n";
  output.write(header);


  if (switch_case) {
    output.write("  int s_trivial_op;\n");
    output.write("  switch (switch_value) {\n");
    for (int i=0;i<num_cases;i++) {
      string data = "    case ";
      data += itos(i);
      data += ": { s_trivial_op = ";
      data += itos(i);
      data += "; } break;\n";
      output.write(data);
    }
    output.write("}\n");
  }
  else {
    output.write("  int i_trivial_op;\n");
    output.write("  if (ifelse_value == 0) i_trivial_op = 0;\n");
    for (int i=0;i<num_cases;i++) {
      string data = "  else if (ifelse_value == ";
      data += itos(i);
      data += ") i_trivial_op = ";
      data += itos(i);
      data += ";\n";
      output.write(data);
    }
  }

  return 0;
}
