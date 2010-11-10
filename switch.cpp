// File: switch.cpp
// Written by Joshua Green

#include <iostream>
#include <string>

#include "stopwatch.h"
using namespace std;

#define ITERATIONS      100000000
#define CASE_COUNT      100
#define SWITCH_INCLUDE "100_switch_cases._cpp"
#define IFELSE_INCLUDE "100_ifelse_cases._cpp"

int main() {
  stopwatch timer;
  int trivial_op = 0;

  cout << "Testing " << CASE_COUNT << "x" << ITERATIONS << " switch cases..." << endl;

  timer.start();
  for (int i=0;i<ITERATIONS;i++) {
    #include SWITCH_INCLUDE
  }
  timer.stop();
  timer.print();
  double switch_time = timer.elapsed();

  cout << endl << "Testing " << CASE_COUNT << "x" << ITERATIONS << " if/else cases..." << endl;

  timer.start();
  for (int i=0;i<ITERATIONS;i++) {
    #include IFELSE_INCLUDE
  }
  timer.stop();
  timer.print();
  double ifelse_time = timer.elapsed();

  if (switch_time == ifelse_time) cout << "There is no difference." << endl;
  else {
    if (switch_time < ifelse_time) cout << "Switch ";
    else cout << "If/Else sift ";

    cout << "is faster by " << fabs(switch_time-ifelse_time) << " seconds." << endl;
  }

  char c;
  cin >> c;

  return 0;
}
