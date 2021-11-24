#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>

struct Person
{
   
};

void appendData();
void showAllData();
void findData();
void deleteData();
void displayMenu();

int main()
{
   
}


void appendData()
{
      
}

void showAllData()
{
      
}

void findData()
{
     
     
}
void deleteData()
{
	 
}
void displayMenu()
{   
   

    switch(choice)
    {
         case '1' : //call append record
            appendData();
            goto mainMenu;
         case '2' : //call find record
            findData();
            goto mainMenu;
         case '3' : //Read all record
            showAllData();
            goto mainMenu;
         case '4' :
         	deleteData();
         	goto mainMenu;
         case '5':
            break;
         default:
            goto mainMenu;
    }
}
