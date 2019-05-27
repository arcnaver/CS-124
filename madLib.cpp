/***********************************************************************
* Program:
*    Project 10, Mad Lib II       (e.g. Assignment 10, Hello World)
*    Brother Foushee, CS124
* Author:
*    Adam J Tipton
* Summary: 
*    This project will create a Mad Lib game. Madlib is a word game that
*    replaces certain words in a given text with replacement values 
*    given by the player. The stories are often funny when read back by
*    children. 
*    This program will have 7 functions outside of MAIN to create the
*    game.
*
*    Estimated: 10.0 hrs   
*    Actual:    12.0 hrs
*     It is hard to pick any one difficulty. I had difficulty across the
*     board with this. One huge issue was my buffers. I kept having to 
*     increase MAXWORDLENGTH from 32 to 256. I'm at a loss as to understand
*     what is going on there. I had severe difficulty in formatting 
*     punctuation and preventing \n where they don't belong. 
************************************************************************/

#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

#define MAXWORDS 256
#define MAXWORDLENGTH 256

int  readFile    (char story[MAXWORDS][MAXWORDLENGTH]);
void getFilename (char fileName[]);
void askQuestion (char text[]);
char playAgain   ();
void displayStory(char story[MAXWORDS][MAXWORDLENGTH], int length);
bool isPunc      (char character[]);
void formatPunc  (char textOne[], char textTwo[]);



/**********************************************************************
 *MAIN
 *      Will run the program by calling readFile, displayStory, and
 *      playAgain.
 ***********************************************************************/
int main()
{
   //Create Story array
   char story[MAXWORDS][MAXWORDLENGTH];

   //Get length and read the file
   //   by assigning int length to readFile
   int length = readFile(story);
   
   //Display TO Finish
   displayStory(story, length);
   
   //Ask to play again
   char resume = playAgain();
   while (resume == 'y')
   {
      length =    readFile(story);
      displayStory(story, length);
      resume =        playAgain();
   }

   cout << "Thank you for playing.\n";
  
   return 0;
}

/***********************************************************************
* READ FILE
*       This function will read the file, check it for errors: 
*            It will call ASKQUESTION and add up and return numWords. 
***********************************************************************/
int readFile(char story[][MAXWORDLENGTH])
{
   //Get the file name
   char fileName[MAXWORDS];                  //Create container for filename
   getFilename(fileName);

   //Start ifstream
   ifstream fin(fileName);
   //check for file reading error
   if (fin.fail())
   {
      cout << "Unable to open file: "
           << fileName
           << endl;
      return 0;
   }
   
   //Get the length and ask questions
   int numWords = 0;
   while (numWords < MAXWORDLENGTH && fin >> story[numWords])
   {                
      //Ask Questions and pray we
      //   get the right answers. 
      askQuestion(story[numWords]);
      
      numWords++;                       //Increment them words!!
      
   }
     
   cout << endl;
       
   //Gotta close that file!
   fin.close();
   
   //All is well in Zion if this point is reached.
   //   Now return them words!!
   return numWords;
}

/***********************************************************************
* GET FILENAME
*       This function will get the filename to be used.
*       Note that caller creates the variable container that GET FILENAME
*       uses.
***********************************************************************/
void getFilename(char fileName[])
{
   //Prompt user for the allusive file
   cout << "Please enter the filename of the Mad Lib: ";

   cin  >> fileName;
   
   cin.ignore(); 
}

/**********************************************************************
* ASK QUESTION
*       This function will ask the questions needed for the game and 
*       sort through the text, replacing what needs to be replaced in
*       the given text.
**********************************************************************/
void askQuestion(char text[])
{
   //Check for prompt char, return back to readFile
   if (text[0] != ':' || !isalpha(text[1]))
   {      
      return;
   }
      
   //Upper Case First Letter
   cout << "\t" << (char)toupper(text[1]);

   //To format the question
   for (int iText = 2; text[iText] != '\0'; iText++)
   {
      //Get rid of '_' for spaces.
      if (text[iText] == '_')
      {
         cout << " ";
      }

      //Otherwise display and tolower-case the text
      else
      {
         cout << (char)tolower(text[iText]);
      }
   }

   //Display the ':' and get input
   cout << ": ";                        //Notice the space
   
   cin.getline(text, 256);
   
                
}

/*********************************************************************
* PLAY AGAIN
*       This function will determine if the user wants to play again.
*********************************************************************/
char playAgain()
{
   //Ask user if they want to play again.
   cout << "Do you want to play again (y/n)? ";
   char answer;
   cin  >> answer;   

   //Check values
   switch (answer)
   {
      case 'y':
      case 'Y':
         return 'y';
         break;
      default:
         return 'n';
   }
}

/********************************************************************
* DISPLAY STORY
*       This is the display function for the game. The story will be
*       output.
********************************************************************/
void displayStory(char story[][MAXWORDLENGTH], int length)
{ 
   //Create word counter
   int wordCounter = 0;
   for (wordCounter = 0; wordCounter < length;)
   {
      if (isalpha(story[wordCounter][0]) && isalpha(story[wordCounter + 1][0]))
      {
         cout << story[wordCounter] << " ";
      }
      //If its : send it to formatPunc
      else if (story[wordCounter][0] == ':' && isPunc(story[wordCounter])) 
      {
         formatPunc(story[wordCounter], story[wordCounter + 1]);
      }
      else    
      {
         cout << story[wordCounter];
      }

      //Increment the counter
      wordCounter++;
   }
   cout << endl;
}

/********************************************************************
* IS PUNC
*       This function figures out what the special characters are
*       and does something about them.
********************************************************************/
bool isPunc(char character[])
{
   //create a switch to determine what 
   //each token equates too.
   switch (character[1])
   {
      case '!':                         //If ! new line.
         return true;
         break;
      case '<':                         //If < open quotes.
         return true;
         break;
      case '>':                         //If > closed quotes.
         return true;
         break;
      case '.':                         //If . period.
         return true;
         break;
      case ',':                         //If , comma.
         return true;
         break;
      default:
         return false;
   }   
   
}

/****************************************************************************
*FORMAT PUNC
*       This function will format the punctuation.
*****************************************************************************/
void formatPunc  (char textOne[], char textTwo[])
{
   switch (textOne[1])
   {
      case '!':                         //If ! new line.
         cout << endl;         
         break;
      case '<':                         //If < open quotes.
         cout << " \"";
         break;
      case '>':                         //If > closed quotes.
         cout << "\" ";
         break;
      case '.':                         //If . period.
         if (isalpha(textTwo[0]))       // if its followed by alpha space after
         {                              
            cout << ". ";
         }
         else
         {
            cout << ".";                 //If not no space.
         }
         break;
      case ',':                         //If , comma.
         if (isalpha(textTwo[0]))       // If its followed by alpha space after
         {                              
            cout << ", ";
         }
         else                           //If not no space.
         {
            cout << ",";
         }
         break;
   }      
}
