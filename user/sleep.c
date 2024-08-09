// Simple grep.  Only supports ^ . * $ operators.

#include "user/user.h"


int main(int argc, char *argv[])
{
  int time;

  if(argc <= 1){
    printf("usage: sleep time(unit?) \n");
    exit(1);
  }

  if(argc <= 2){

    time = atoi(argv[1]);

    sleep(time);
    exit(0);
  }

  return 0;
}

