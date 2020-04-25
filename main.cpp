/*Dr. Tyson 1437 Programming Fundamentals II
  Chet Lockwood
  24 APRIL 2020
  IDE: Repl.it 
  Program:  Unit 5 Assignment Menu/Receipt program
  https://repl.it/@ChetLockwood/Unit5AssignmentLockwood
*/

#include "Functions.h"

int main() 
{
  vector<MenuItem> objectMenu;
  char input = '\0';
  
  populateMenu(objectMenu);

  do
  {
    repopulateMenu(objectMenu);
    cout << cClear;
    showMenu(objectMenu);
    acceptOrder(objectMenu);
    cout << "\n\n\nPress any key to start a new customer (press X or x to exit)\n";
    validateChar(input);
  }while (input != 'x' && input !='X');

  cout << cClear << "\n\nHave a good Day!";
  return 0;
}