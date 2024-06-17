#include <stdio.h>
#include <stdlib.h>

/*The code does not handle the cases where we raise a number to 0, instead of returning 1, it returns the number itself which is wrong.
  I first compiled the code with these flags: -Wall -Wextra -Werror, to see if it does compile successfully and it actually did. I then 
  used print statement in the while loop to check how the intergers x,y, and r are changing. I then used some test cases like setting 
  y = 0, for any number, which was supposed to return 1, but did not. So I introduced an if statement to check that. 
  I also realized, by logic, the return statement is incorrect because it multiplies the r with x outside of the while loop. 
  So when the loop terminates, x will still contain the value that was halfed repetedly, but it hasn't been raised to the correct power.*/

int power(int x, int y) {
  if (y == 0){
    return 1;
  }
  int r = 1;
  while (y > 0) {
    if (y % 2 == 1) {
      r = x * r; 
      }
    x = x * x;
    y = y / 2;
    printf("%d,%d,%d\n", y,x,r);
  }
  return r;
}

int main(){
    int res = power(7,0);
    printf("%d\n", res);
    return 0;
}