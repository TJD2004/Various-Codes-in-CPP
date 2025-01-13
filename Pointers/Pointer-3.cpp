#include <iostream>
using namespace std;
int main()
{ 
  char *ptr; 
  char Str[] = "abcdefg";
  ptr = Str;
  ptr += 5;
  cout << ptr;
  return 0;
}

/*
        Initially ptr will point to 'a'. But as soon as we write ptr+=5, ptr will shift 5 addresses ahead that is it will point to 'f' and thus 
        when we are printing ptr, it will print all the characters starting from 'f' till it encounter NULL character, so output is "fg".
*/