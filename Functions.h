/*Dr. Tyson 1437 Programming Fundamentals II
  Chet Lockwood
  24 APRIL 2020
  IDE: Repl.it 
  Program:  Header for Functions
  https://repl.it/@ChetLockwood/Unit5AssignmentLockwood
*/

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "Menu_Item.h"
#include <ctime>
#include <unistd.h>



//POPULATE THE MENU INITIALLY FUNCTION ***********************************************************
void populateMenu(vector<MenuItem> &entireMenu)
{
  //put some default values in our Menu
  const int numItems = 7; 
  MenuItem Item1; 
  MenuItem Item2;
  MenuItem Item3; 
  MenuItem Item4;
  MenuItem Item5;
  MenuItem Item6;
  MenuItem Item7;    

  entireMenu.push_back(Item1); //add to the end of list the Item1
  entireMenu.push_back(Item2); //add to the end of list the Item2
  entireMenu.push_back(Item3); //add to the end of list the Item3
  entireMenu.push_back(Item4); //add to the end of list the Item4
  entireMenu.push_back(Item5); //add to the end of list the Item5
  entireMenu.push_back(Item6); //add to the end of list the Item6
  entireMenu.push_back(Item7); //add to the end of list the Item7

  vector<string> defaultMenuNames = {"Green Tea", "Milk", "Ramen", "Gyoza", "CF Steak", "Snow Crab", "Fried Shrimp"}; 
  vector<char> defaultAddLetters = {'A', 'B', 'C', 'D', 'E', 'F', 'G'}; 
  vector<char> defaultRemoveLetters = {'a', 'b', 'c', 'd', 'e', 'f', 'g'}; 

  for(int i = 0; i < numItems; i++)
  {
    //add each item to the default list efficiently 
    entireMenu[i].setName(defaultMenuNames[i]); 
    entireMenu[i].setAddLetter(defaultAddLetters[i]); 
    entireMenu[i].setRemoveLetter(defaultRemoveLetters[i]); 
    entireMenu[i].setItemCost((3.00 + i)); //set a random starter cost for each item
    entireMenu[i].setDesc("delicious"); //set all default desc to "delicous"
    entireMenu[i].setICount();
  }
    entireMenu[0].setDesc("\x1b[38;5;14m+1 Alert,\x1b[38;5;12m +1 Thirst");
    entireMenu[1].setDesc("\x1b[0m+20 Bone Str,\x1b[38;5;12m +2 Thirst");
    entireMenu[2].setDesc("\x1b[38;5;9m+3 Hunger,\x1b[38;5;12m +3 Thirst");
    entireMenu[3].setDesc("\x1b[38;5;9m+2 Hunger");
    entireMenu[4].setDesc("\x1b[38;5;9m+5 Hunger,\x1b[38;5;3m +4 Muscle");
    entireMenu[5].setDesc("\x1b[38;5;9m+4 Hunger,\x1b[38;5;3m +3 Muscle,\x1b[38;5;13m +1 Mood");
    entireMenu[6].setDesc("\x1b[38;5;9m+4 Hunger,\x1b[38;5;3m +3 Muscle,\x1b[38;5;13m +2 Mood");
}

//POPULATE THE MENU FOR A NEW CUSTOMER FUNCTION **************************************************
void repopulateMenu(vector<MenuItem> &entireMenu)
{
  const int numItems = 7;

  vector<string> defaultMenuNames = {"Green Tea", "Milk", "Ramen", "Gyoza", "CF Steak", "Snow Crab","Fried Shrimp"}; 
  vector<char> defaultAddLetters = {'A', 'B', 'C', 'D', 'E', 'F', 'G'}; 
  vector<char> defaultRemoveLetters = {'a', 'b', 'c', 'd', 'e', 'f', 'g'}; 

  for(int i = 0; i < numItems; i++)
  {
    //add each item to the default list efficiently 
    entireMenu[i].setName(defaultMenuNames[i]); 
    entireMenu[i].setAddLetter(defaultAddLetters[i]); 
    entireMenu[i].setRemoveLetter(defaultRemoveLetters[i]); 
    entireMenu[i].setItemCost((3.00 + i)); //set a random starter cost for each item
    entireMenu[i].setDesc("delicious"); //set all default desc to "delicous"
    entireMenu[i].setICount();
  }
    entireMenu[0].setDesc("\x1b[38;5;14m+1 Alert,\x1b[38;5;12m +1 Thirst");
    entireMenu[1].setDesc("\x1b[0m+20 Bone Str,\x1b[38;5;12m +2 Thirst");
    entireMenu[2].setDesc("\x1b[38;5;9m+3 Hunger,\x1b[38;5;12m +3 Thirst");
    entireMenu[3].setDesc("\x1b[38;5;9m+2 Hunger");
    entireMenu[4].setDesc("\x1b[38;5;9m+5 Hunger,\x1b[38;5;3m +4 Muscle");
    entireMenu[5].setDesc("\x1b[38;5;9m+4 Hunger,\x1b[38;5;3m +3 Muscle,\x1b[38;5;13m +1 Mood");
    entireMenu[6].setDesc("\x1b[38;5;9m+4 Hunger,\x1b[38;5;3m +3 Muscle,\x1b[38;5;13m +2 Mood");
}

//MENU DRAW FUNCTION *****************************************************************************
void showMenu(vector<MenuItem> &m)
{
  vector<string> color = {"\x1b[38;5;10m", "\x1b[38;5;7m","\x1b[38;5;10m", "\x1b[38;5;7m","\x1b[38;5;10m", "\x1b[38;5;7m","\x1b[38;5;10m"};
  
  cout << fixed << setprecision(2);//set doubles to 2 decimal places
  cout << cUnderL << "\nDR.T'S HOUSE OF GRUB" << cReset << endl; 
  cout << "ADD  \tNAME \t\tCOST  \tREMOVE\tCOUNT\tDESC"<<endl; 
  for(int i = 0; i < m.size(); i++)
  {
    cout << color[i] << m[i].getAddLetter() << ")\t " << setw(14) << left << m[i].getName() 
    << setw(2) << "$" << m[i].getItemCost() << setw(5) << right << "(" << m[i].getRemoveLetter()
    << ")" << setw(7) << m[i].getCount() << "\t\t" << setw(10) << left << m[i].getDesc() 
    <<endl; 
  }
  cout << cReset;
}

//RECEIPT DRAW FUNCTION ***************************************************************************
void receipt(vector<MenuItem> &m, double tip, double subtotal)
{
  double total = (subtotal + (subtotal * .0825));
 
  cout << cClear;
  cout << "\n\tThank you for placing your order.\n\n" << endl; 

  cout << "\t\t DR.T'S HOUSE OF GRUB\n";
  cout << "\t\tFort Worth, Texas 76102\n";
  cout << "\t\t    (817) 515-8223\n";
  cout << "----------------------------------------\n";
  cout << "\t\t" << asctime(localtime(&result))  << "\n";
  cout << "\t\t\t Ticket Number: " << ticketCount << "\n";
  cout << "========================================\n";
  cout << "QTY\t DESC \t      Price \t\tAmount\n";
  cout << "========================================\n";
  
  for (int i = 0; i < m.size(); i++)
  {
    if(m[i].getCount() > 0)
    {
      cout << m[i].getCount() << "\t" <<  setw(14) << left << m[i].getName() << " " << setw(3) 
      << right << m[i].getItemCost() << "\t\t\t " << setw(10) << left 
      << (m[i].getCount() * m[i].getItemCost()) << endl; 
    }
  }
  cout << "\n\n\t\t\t\t\t\t\t----------";
  cout <<"\n\t\t\t\t\tSub Total\t " << right << setw(5) << subtotal;
  cout <<"\n\t\t\t\t\tSales Tax\t " << right << setw(5) << (subtotal * .0825);
  cout << "\n\t\t\t\t\t\t\t----------";
  cout <<"\n\t\t\t\t\tTotal   \t " << right << setw(5) << total;
  cout <<"\n\t\t\t\t\tTip     \t " << right << setw(5) << tip;
  cout <<"\n\t\t\t\t\tTotal Due\t " << right << setw(5) << (total + tip);
}

//Receipt DRAW TO .TXT FUNCTION ******************************************************************
void receiptPrint(vector<MenuItem> &m, double tip, double subtotal)
{
  fstream receipt;
  receipt.open("receipt.txt", ios::out);

  double total = (subtotal + (subtotal * .0825));
  receipt << fixed << setprecision(2);
 
  receipt << "\t\t\t\t DR.T'S HOUSE OF GRUB\n";
  receipt << "\t\t\t\tFort Worth, Texas 76102\n";
  receipt << "\t\t\t\t    (817) 515-8223\n";
  receipt << "----------------------------------------\n";
  receipt << "\t\t\t\t" << asctime(localtime(&result))  << "\n";
  receipt << "\t\t\t\t\t Ticket Number: " << ticketCount << "\n";
  receipt << "========================================\n";
  receipt << "QTY\t DESC \t      Price \t\t\t\tAmount\n";
  receipt << "========================================\n";
  
  for (int i = 0; i < m.size(); i++)
  {
    if(m[i].getCount() > 0)
    {
      receipt << m[i].getCount() << "\t\t" <<  setw(14) << left << m[i].getName() << " " << setw(3) 
      << right << m[i].getItemCost() << "\t\t\t\t\t " << setw(10) << left 
      << (m[i].getCount() * m[i].getItemCost()) << endl; 
    }
  }
  receipt << "\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t----------";
  receipt <<"\n\t\t\t\t\t\t\t\t\t\t\t\tSub Total\t " << right << setw(5) << subtotal;
  receipt <<"\n\t\t\t\t\t\t\t\t\t\t\t\tSales Tax\t " << right << setw(5) << (subtotal * .0825);
  receipt << "\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t----------";
  receipt <<"\n\t\t\t\t\t\t\t\t\t\t\t\tTotal   \t " << right << setw(5) << total;
  receipt <<"\n\t\t\t\t\t\t\t\t\t\t\t\tTip     \t " << right << setw(5) << tip;
  receipt <<"\n\t\t\t\t\t\t\t\t\t\t\t\tTotal Due\t " << right << setw(5) << (total + tip);

  receipt << "\n\n\nTHANK YOU FOR EATING DR.T'S HOUSE OF GRUB\n";

  receipt.close();
}

//Receipt DRAW TO .HTML FUNCTION ******************************************************************
void receiptPrintHTML(vector<MenuItem> &m, double tip, double subtotal)
{
  fstream receipt;
  receipt.open("receipt.html", ios::out);

  double total = (subtotal + (subtotal * .0825));
  receipt << fixed << setprecision(2);
 
  receipt << "<html><head><title>Cool</title></head>";
  receipt << "<body style=\"background-color:#000000; color:#FFFFFF;\">";

  receipt << "<h3>" << "&emsp;&emsp;&emsp;&emsp;&emsp;DR.T'S HOUSE OF GRUB\n" << "</h3>";
  receipt << "<h4>" << "&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;Fort Worth, Texas 76102\n" << "</h4>";
  receipt << "<p>" << "&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;(817) 515-8223\n" << "</p>";
  receipt << "<h4>" << "&emsp;&emsp;&emsp;&emsp;&emsp;----------------------------------------\n" << "</h4>";
  receipt << "<h4>" << "&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;" << asctime(localtime(&result))  << "\n" << "</h4>";
  receipt << "<h4>" << "&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;Ticket Number: " << ticketCount << "\n" << "</h4>";
  receipt << "<h4>" << "==============================================\n" << "</h4>";
  receipt << "<h4>" << "QTY&emsp;&emsp;&emsp;DESC&emsp;&emsp;&emsp;&emsp;&emsp;Price&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;Amount\n" << "</h4>";
  receipt << "<h4>" << "==============================================\n" << "</h4>";
  
  for (int i = 0; i < m.size(); i++)
  {
    if(m[i].getCount() > 0)
    {
      receipt << "<p>&emsp;" << m[i].getCount() << "&emsp;&emsp;&emsp;&emsp;&nbsp;" <<  setw(14) << left << m[i].getName() << "&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;" << setw(3) 
      << right << m[i].getItemCost() << "&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;" << setw(10) << left 
      << (m[i].getCount() * m[i].getItemCost()) << endl << "</p>"; 
    }
  }
  receipt << "<p>" << "\n\n&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;----------" << "</p>";
  receipt << "<p>" << "\n&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;Sub Total&emsp;&emsp;&emsp;&emsp;" << right << setw(5) << subtotal << "</p>";
  receipt << "<p>" << "\n&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;Sales Tax&emsp;&emsp;&emsp;&emsp;" << right << setw(5) << (subtotal * .0825) << "</p>";
  receipt << "<p>" <<  "\n&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;----------" << "</p>";
  receipt << "<p>" << "\n&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;Total&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;" << right << setw(5) << total << "</p>";
  receipt << "<p>" << "\n&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;Tip&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;" << right << setw(5) << tip << "</p>";
  receipt << "<p>" << "\n&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;Total Due&emsp;&emsp;&emsp;&emsp;" << right << setw(5) << (total + tip) << "</p>";

  receipt << "<p>" "\n\n\nTHANK YOU FOR EATING DR.T'S HOUSE OF GRUB\n" << "</p>";

  receipt << "</body></html>"; 

  receipt.close();
}

//ORDERING AND RECEIPT FUNCTION ******************************************************************
void acceptOrder(vector<MenuItem> &m)
{
  char option = '\0';// the user-selected menu item
  double subtotal = 0.0; 
  double tip = 0.0;
  ticketCount++;
  
  do
  {
    cout << cReset;
    cout << "\nPlease choose an item (x to Exit): ";
    cin >> option; 

    for(int i=0; i < m.size(); i++)
    {
      int count = 0;
      if(option == m[i].getAddLetter())
      {
        cout << "\nMenu Item " << m[i].getAddLetter() << " selected."; 
        m[i].setCount(1); //increment the count by 1
        cout << "\033[2J\033[1;1H"; //clear screen 
        cout << "\n1 UP on " << m[i].getName() << endl;
        subtotal += m[i].getItemCost(); //increment the subtotal by the cost of the item 
        showMenu(m); //show the updated menu
        cout << "\nSubtotal: $" << subtotal << endl;  
      }
      else if(option == m[i].getRemoveLetter())
      {
        cout << "\nRemove Item " << m[i].getRemoveLetter() << " selected."; 
        if(m[i].getCount() > 0) //subtract if and only if the count is > 0
        {
          m[i].setCount(-1); //decrement the count by 1
          cout << "\033[2J\033[1;1H"; //clear screen 
          cout << "\n1 DOWN on " << m[i].getName() << endl;
          subtotal -= m[i].getItemCost(); //decrement the subtotal by the cost of the item
          showMenu(m); //show the updated menu
          cout << "\nSubtotal: $" << subtotal << endl;  
        }
        else //tell the user why you blocked item removal 
        {
            
            cout << "\nItem count must be > 0 to remove: " << m[i].getName() << endl;
        }
      }
      //test for all of my valid inputs
      else if(option != m[i].getAddLetter() && option != m[i].getRemoveLetter() && option != 'x' && option != 'X') 
      {
        if(i == 0)
        {
          cout << "\nInvalid input (" << option << "). Please try again." << endl; 
        }  
      }
    }
  }while(option != 'x' && option != 'X'); 

  double total = (subtotal + (subtotal * .0825));
  receipt(m, tip, subtotal);
  int tinput = 0;
  int minput = 0;
  
  do
  {
    do
    {
      cout << cClear;
      receipt(m, tip, subtotal);
      cout << "\n\n\nWould you like to leave a tip?\n\n";
      cout << "1 - NO TIP\n";
      cout << "2 - 10% - " << subtotal * .1 << "\n";
      cout << "3 - 15% - " << subtotal * .15 << "\n";
      cout << "4 - 20% - " << subtotal * .2 << "\n";
      cout << "5 - Custom Tip\n\n";

      validateInt(minput);

      if (minput == 1)
      {
        tip = 0;
        receipt(m, tip, subtotal);
      }

      else if (minput == 2)
      {
        tip = subtotal * .1;
        receipt(m, tip, subtotal);
      }

      else if (minput == 3)
      {
        tip = subtotal * .15;
        receipt(m, tip, subtotal);
      }

      else if (minput == 4)
      {
        tip = subtotal * .2;
        receipt(m, tip, subtotal);
      }

      else if (minput == 5)
      {
        double ctip = 0.0;
        cout << "What percentage do you want to tip?\n";
        validateDouble(ctip);
        tip = subtotal * (ctip /100);
        receipt(m, tip, subtotal);
      }
      else
        cout << "Not a valid tip option\n";

    }while (minput > 0 && minput > 5);

  cout << "\n\nIs this right? (1 for yes, 0 for no)\n\n";
  validateInt(tinput);

  }while (tinput != 1);

  receiptPrint(m, tip, subtotal);
  receiptPrintHTML(m, tip, subtotal);
  cout << cClear;
  receipt(m, tip, subtotal);

  cout << "\n\nHow woul you like to pay for this? (1 for cash, 2 for credit)\n\n";
  validateInt(minput);


  if (minput == 1)
  {
    double payment = 0.0;
    
    do
    {
      cout << cClear;
      receipt(m, tip, subtotal);

      cout << "\n\nhow much money are you paying with\n\n";
      validateDouble(payment);

      cout << cClear;
      receipt(m, tip, subtotal);

      if((payment + .0075) >= ((subtotal + (subtotal * .0825)) + tip))
      {
        cout << "\n\nYour Change is: " << (payment - ((subtotal + (subtotal * .0825)) + tip));
        cout << "\n\nThank you for your patronage";
      }

      if((payment + .0075) < ((subtotal + (subtotal * .0825)) + tip))
      {
        cout << "\n\nYou have to give more money than you owe";
        cout.flush();
        sleep(2);
      }
    }while ((payment + .0075) < ((subtotal + (subtotal * .0825)) + tip) );
  }

  if (minput == 2)
  {
    cout << cClear;
    receipt(m, tip, subtotal);
    cout << "\n\nProcessing.";
    cout.flush();
    sleep(1);

    cout << cClear;
    receipt(m, tip, subtotal);
    cout << "\n\nProcessing..";
    cout.flush();
    sleep(1);

    cout << cClear;
    receipt(m, tip, subtotal);
    cout << "\n\nProcessing...";
    cout.flush();
    sleep(1);

    cout << cClear;
    receipt(m, tip, subtotal);
    cout << "\n\nThank you for your patronage";
  }
}
#endif