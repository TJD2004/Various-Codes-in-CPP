#include<iostream>
using namespace std;
int main()
{
  int ***r, **q, *p, i=8;
  p = &i;
  (*p)++;
  q = &p;
  (**q)++;
  r = &q;
  cout<<*p << " " <<**q << " "<<***r;
  return 0;
}

/*
    Solution description
    The code increments the value of i twice using pointers, changing it from 8 to 10. So, the output of the cout statement is 10 10 10, as all   
    pointers ultimately point to i.     
*/