// Pranav Talwar - 3035435462
// Rajat Jain - 3035453684
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
#include "command.h"
using namespace std;


int main()
{
  vector<Command> CommandLog;
  Command new_command;
  clock_t start, end;
  double cpu_time_used;
  string command;
  int status;
  for(;;)
  {
    cout<<"tinyshell>";
    getline(cin, command);
    start = clock();
    int pid = fork();
    if(pid == 0)
    {
      if(removeSpaces(command)=="exit")
      {
        exit(0);
      }
      if(removeSpaces(command)=="history")
      {
        print(CommandLog);
        exit(-1);
      }
      else if(removeSpaces(command)=="history-sbu")
      {
        vector<Command> Sorted_log = CommandLog;
        if(Sorted_log.size() >= 5)
        {
          sort(Sorted_log.end() - 5 , Sorted_log.end(), compare);
        }
        else
        {
          sort(Sorted_log.begin(), Sorted_log.end(), compare);
        }
        print(Sorted_log);
        exit(-1);
      }
      else
      {
        system(command.c_str());
        exit(-1);
      }
    }
    wait(&status);
    if(status == 0)
    {
      exit(0);
    }
    end = clock();
    cpu_time_used = ((double)end-start)/CLOCKS_PER_SEC;

      new_command.command_name = command;
      new_command.execution_time = cpu_time_used;
      CommandLog.push_back(new_command);


  }
}
