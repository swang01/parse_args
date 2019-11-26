#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char ** parse_args(char * line){
  char ** args = malloc(5 * sizeof(char *));
  char * curr = line;
  int i = 0;
  while (line != NULL){
    args[i] = strsep(&line," ");
    i++;
  }
  args[i] = NULL;
  return args;
}

int main(){
  char line[100] = "ls -a -l";
  char ** args = parse_args(line);
  execvp(args[0], args);
  return 0;
}
