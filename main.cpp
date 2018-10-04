//
// Demonstration progrm to demo some use of C++
// Cash Register Program
//

#include <iostream>
#include <string>
#include <stdlib.h>
#include <cctype>

// May require: sudo apt-get install sqlite3 libsqlite3-dev
// link with g++ -l sqlite3
#include <sqlite3.h>

// Cash Register Machine States
#include "register_states.h"
#include "utility.h"
#include "login.h"
#include "uuid.h"

using namespace std;

// Function prototypes
const void   displayMenu(int state)     ; //
const void   enterItem(int orderNumber) ; //

// **************
// *** main() ***
// **************
int main(int argc, char*  argv[]){

   /* Dictionary of Variables
   Type   | Name          | Value | Description       */
   int     registerState  = 0x00  ; // State of the cash register
   bool    gotInteger     = false ; // Flag to set if the correct menu choice is made
   string  answer         = ""    ; // Menu selection from user
   int     integerAnswer  = 0     ; // menu selection as an integer
   bool    errorCondition = false ; // Flag used to display error messages
   string  user           = ""    ; // The name of the user
   bool    shutdown       = false ; // Flag to set to shutdown the register
   string order_ID        = ""    ; // Unique Order ID

   // Main Executions loop
   do{


      // Get Menu Selection for the user and process the selection
      do{

         clearDisplay();

         cout << "\n\n**********\nSTUFF MART\n**********\n\nRegister 3\n\n";
         if (registerState > LOGGED_OUT){
            cout << "Cashier is " << user << "\n\n";
         }
         cout << currentDateTime() << "\n\n";

         if(registerState == ORDER_OPENED){
            cout << "Order: " << order_ID << "\n\n";
         }

         displayMenu(registerState);

         if(errorCondition){
            cout << "\n\nERROR -- Please select a number from the menu above..\n\n";
         }

         cout << "\n\nEnter Selection from the menu above: ";
         cin >> answer;

         // strtol() converts as much of the input string to an
         // integer as possible.  chk points to the first character
         // in the string that is not an integer digit.  If this
         // character is anything other than ASCII nul (0) or
         // whitespace, then the input string is not a properly
         // formatted integer.  The '10' parameter indicates that
         // we're interested in base-10 numbers, so hex inputs such
         // as 0x1A2B will be rejected.
         //
         char *chk;
         integerAnswer = (int) strtol (answer.c_str(), &chk, 10);

         if (*chk == '\0' || isspace (*chk))
         {
            gotInteger = true;
         }else{
            errorCondition = true;
         }

       } while(!gotInteger);

      //  Process the user's selection
      switch(integerAnswer){
         case 1:
             user = login();
             registerState = LOGGED_IN;
             break;
         case 2:
             // Clear the list of items iin the order
             // Generate teh unique Order ID
             order_ID = generate_uuid();
             // Set the state of the cash register to opder opened
             registerState = ORDER_OPENED;
             break;
         case 3:
            // Call to enterItem()
            break;
         case 4:
             // Print the receipt
             // Set the state of hte register to logged in
             registerState = ORDER_CLOSED;
             break;
         case 5:
             break;
         case 6:
             break;
         case 7:
             break;
         case 8:
             registerState = LOGGED_OUT;
             break;
         case 9:
             shutdown = true;
             break;
         default:
             break;
      } /* end switch(integerAnswer)*/


   } while(!shutdown);/* while not shutdown */


   return 0;

} /* End main() */


// Displaty the menu choices based onthe state of the cash register
const void  displayMenu(int state){

   switch(state){
      case LOGGED_IN :
         cout << "2 - Start an order\n"
              << "8 - Log out\n";
         break;
      case ORDER_OPENED :
         cout << "3 - Enter Item\n"
              << "4 - Close Order\n"
              << "8 - Log out\n";
         break;
      case ORDER_CLOSED :
         cout << "2 - Start an order\n"
              << "5 - Reopen closed order\n"
              << "8 - Log out\n";
         break;
      default :
         cout << "1 - Log in \n"
              << "9 - Shutdown\n";
         break;
   } /* end switch(state */

} /* end  displayMenu()*/
