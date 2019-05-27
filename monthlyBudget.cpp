/***********************************************************************
* Program:
*    Project 03, Monthly Budget          (e.g. Assignment 10, Hello World)
*    Brother Foushee, CS124
* Author:
*    Adam Tipton
* Summary: 
*    This project is an example of a monthly budget. It will ask for
*    budget income and expenditures, and how much was actually made
*    and spent. The results will be displayed in the console. 
*
*    Estimated:  2.0 hrs   
*    Actual:     5.0 hrs
*      At first I couldn't figure out what I was doing wrong in main. I 
*      had the functions looping through twice for some reason. I didn't
*      realize the variable initialization also called the function.
*      The Display function was the next problem I had. From formatting
*      issues to missing data-types, I had a heck of a time getting it
*      all straightened out. I was also confused by the instructions, 
*      there should be a lesson on how to read the outlines.   
************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

//Setting the function prototypes
double getIncome();
double getBudgetLiving();
double getActualLiving();
void   display(double,double,double,double,double,double);
double getActualOther();
double getActualTithing();
double getActualTax();
double computeTithing(double);
double computeTax(double);




/**********************************************************************
 * This is the main function. 
 * It will call the get functions, display(), and hold input values.
 ***********************************************************************/
int main()
{
   //Display greeting and get user input
   cout << "This program keeps track of your monthly budget\n";
   cout << "Please enter the following:\n";




   // Set up variables
   double income        = getIncome();   
   double budgetLiving  = getBudgetLiving();
   double actualLiving  = getActualLiving();
   double actualTax     = getActualTax();
   double actualTithing = getActualTithing();
   double actualOther   = getActualOther();  

   // Call the display() function.   
   display(income, budgetLiving, actualTax, actualTithing,
                               actualLiving, actualOther);
   

   return 0;              //Return 0 for the win! 
}

/******************************************************************
* DISPLAY()                                                      **
*    Gather input from functions and set up an easy to read      **
*    display for main.                                           **
******************************************************************/
void display(double income,       double budgetLiving,
             double actualTax,    double actualTithing,
             double actualLiving, double actualOther)
{

   // Configure display
   cout.setf(ios::fixed);       //No scientific notations
   cout.setf(ios::showpoint);   //Show us the decimal point
   cout.precision(2);           //Set it to 2 places right of decimal

   /***************************************************************
   * SET VALUES and VARIABLES    **********************************
   ***************************************************************/
   double budgetTax        = computeTax(income);
   double budgetTithing    = computeTithing(income);
   double budgetOther      = (income - budgetTax - budgetTithing 
                             - budgetLiving);
   
   double budgetDifference = 0.00;           //We want it balanced
   double actualDifference = (income - actualTax - actualTithing 
                             - actualLiving - actualOther);

   /****************************************************************
   * Header of columns                                            **
   *    Gives the user an expense report.                         **
   *    Displays "Item" "Budget" "Actual" spaced along the top.   ** 
   ***************************************************************** 
   ****************************************************************/
   cout << "\nThe following is a report on your monthly expenses\n"
        << "\tItem                  Budget          Actual\n";  
      

   //Top divider
   cout << "\t=============== =============== ===============\n";

   //***************************************************************

   //Displays a list of categories with input data from our functions.

   cout << "\tIncome          $"
        << setw(11)
        << income              //This is our "INCOME" category
        << "    $"
        << setw(11)
        << income
        << endl;    

   cout << "\tTaxes           $"
        << setw(11)
        << budgetTax           //This is is our "TAX" category
        << "    $"             //budgetTax and actualTax
        << setw(11)
        << actualTax
        << endl; 

   cout << "\tTithing         $"
        << setw(11)
        << budgetTithing       //this is our "TITHING" category
        << "    $"             //budgetTithing and actualTithing
        << setw(11)
        << actualTithing
        << endl; 

   cout << "\tLiving          $"
        << setw(11)
        << budgetLiving        //this is our "LIVING" category
        << "    $"             //budgetLiving and actualLiving
        << setw(11)
        << actualLiving
        << endl;
 
   cout << "\tOther           $"
        << setw(11)
        << budgetOther         //This is our "OTHER" category
        << "    $"             //budgetOther and actualOther
        << setw(11)
        << actualOther
        << endl;

    

//******************************************************************

   //Bottom divider
   cout << "\t=============== =============== ===============\n";
   
   //Difference Category
   cout << "\tDifference      $"
        << setw(11)
        << budgetDifference         //This is our "DIFFERENCE" category
        << "    $"                  //budgetOther and actualOther
        << setw(11)
        << actualDifference
        << endl; 



}

/******************************************************************
*******************************************************************
*GETINCOME()
*    Prompt the user to input income and then return it to main()
******************************************************************/
double getIncome()
{
   
   //Set variable for input
   double income;             //Dealing with money we need a double.
   
   //Prompt the user
   cout << "\tYour monthly income: ";
   cin  >> income; 
   
   return (income);           //Return income to main

}

/******************************************************************
*******************************************************************
*GETBUDGETLIVING()
*    Prompt the user to input budgeted living expenses and then 
*    return it to main()
******************************************************************/
double getBudgetLiving()
{
   
   //Set variable for input
   double budgetLiving;       //Dealing with money we need a double.
   
   //Prompt the user
   cout << "\tYour budgeted living expenses: ";
   cin  >> budgetLiving;                        //Budgeted living

   return (budgetLiving);    //Return livingBudgeted to main

} 

/******************************************************************
*******************************************************************
*GETACTUALLIVING()
*    Prompt the user to input budgeted living expenses and then 
*    return it to main()
******************************************************************/
double getActualLiving()
{
   
   //Set variable for input
   double actualLiving;       //Dealing with money we need a double.
   
   //Prompt the user
   cout << "\tYour actual living expenses: ";  
   cin  >> actualLiving;                        //Actual living

   return (actualLiving);      //Return livingBudgeted to main

}

/******************************************************************
*******************************************************************
*GETACTUALTAX()
*    Prompt the user to input actual tax withholding and then 
*    return it to main()
******************************************************************/
double getActualTax()
{
   
   //Set variable for input  
   double actualTax;          //Dealing with money we need a double.

   //Prompt the user
   cout << "\tYour actual taxes withheld: ";
   cin  >> actualTax;                           //Actual tax
   

   return (actualTax);         //Return taxActual to main

}

/******************************************************************
*******************************************************************
*GETACTUALTITHING()
*    Prompt the user to input actual tithing offerings and then 
*    return it to main()
******************************************************************/
double getActualTithing()
{

   //Set variable for input
   double actualTithing;      //Dealing with money we need a double.

   //Prompt the user
   cout << "\tYour actual tithe offerings: ";
   cin  >> actualTithing;                       //Actual tithing


   return (actualTithing);     //Return tithingActual to main

}

/******************************************************************
*******************************************************************
*GETACTUALOTHER()
*    Prompt the user to input actual other expenses and then 
*    return it to main()
******************************************************************/
double getActualOther()
{
   
   //Set variable for input
   double actualOther;        //Dealing with money we need a double.

   //Prompt the user
   cout << "\tYour actual other expenses: ";
   cin  >> actualOther;                         //Actual other


   return (actualOther);       //Return otherActual to main

}

/******************************************************************
*******************************************************************
*COMPUTETITHING()
*    Compute tithing to determine how much a full tithe is.
*    Will take 10% of income
******************************************************************/
double computeTithing(double income)
{
   
   //Compute tithing and return results.
   return (income * .1);

}

/******************************************************************
*******************************************************************
*COMPUTETAX()            TO-DO
*    This will compute taxes.
******************************************************************/
double computeTax(double income)
{

   // To be finished in future project
   return 0.00;
}













