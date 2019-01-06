// Pranav Talwar - 3035435462
// Rajat Jain - 3035453684
#ifndef COMMAND_H
#define COMMAND_H
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <unistd.h>
#include <iostream>
#include <time.h>
#include <string>
#include <sys/wait.h>
#include <vector>
#include <algorithm>
using namespace std;
class Command{
public:
  string command_name;
  double execution_time;
};
void print (const vector<Command> &v);
bool compare(const Command &a, const Command &b);
string removeSpaces(string command);
#endif
