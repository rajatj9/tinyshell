// Pranav Talwar - 3035435462
// Rajat Jain - 3035453684
#include "command.h"
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

void print (const vector<Command> &v)
{
  vector<Command>::const_iterator itr;
  if(v.size() >= 5)
  {
    for(itr=v.end() - 1;itr!=v.end()-6;itr--)
    {
      cout<<(*itr).command_name<<"  "<<(*itr).execution_time << "s"<<endl;
    }
  }
  else
  {
    for(itr=v.end() - 1;itr>=v.begin();itr--)
    {
      cout<<(*itr).command_name<<"  "<<(*itr).execution_time << "s"<<endl;
    }
  }
}
bool compare(const Command &a, const Command &b)
{
  return a.execution_time < b.execution_time;
}
string removeSpaces(string str)
{
    str.erase(remove(str.begin(), str.end(), ' '), str.end());
    return str;
}
