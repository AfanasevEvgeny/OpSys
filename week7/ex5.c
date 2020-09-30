#include <stdio.h>
int main(int argc, char const *argv[]) {
  char **s;
  char foo[] = "Hello World";
  s = malloc(sizeof(foo) );
  *s = foo;
  printf("s is %s\n",s);
  s[0] = foo;
  printf("s[0] is %s\n", s[0]);
  return (0);
}