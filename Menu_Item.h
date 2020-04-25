/*Dr. Tyson 1437 Programming Fundamentals II
  Chet Lockwood
  24 APRIL 2020
  IDE: Repl.it 
  Program:  Header for Menu Items
  https://repl.it/@ChetLockwood/Unit5AssignmentLockwood
*/

#ifndef MENU_ITEM_H
#define MENU_ITEM_H

#include "Input_Validation_Extended.h"
#include <vector>
#include <fstream>

//Global variable to keep track of ticket count 
//Makes sense to place this here to alliviate confusion and issues of having to pass 
//Especially if ticket cancellation was implemented (or someother ticket count mutator)
int ticketCount = 0; 
time_t result = time(&result);

class MenuItem
{
  private:
    string name;
    double itemCost;
    string desc;
    char addLetter;
    char removeLetter;
    int count;
  public:
    MenuItem()
    {
      count = 0;
    }
    void setName(string n) {name = n;}
    void setItemCost(double ic) {itemCost = ic;}
    void setDesc(string d) {desc = d;}
    void setAddLetter(char al) {addLetter = al;}
    void setRemoveLetter(char rl) {removeLetter = rl;}
    void setICount (){count = 0;}
    void setCount(int c) {count += c;}

    string getName() const {return name;}
    double getItemCost() const {return itemCost;}
    string getDesc() const {return desc;}
    char getAddLetter() const {return addLetter;}
    char getRemoveLetter() const {return removeLetter;}
    int getCount() const {return count;}
};
#endif