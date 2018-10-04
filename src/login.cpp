#include <iostream>
#include <string>

#include "login.h"
#include "utility.h"

using namespace std;

string login(){

   string userName = "";
   clearDisplay();
   cout << "\n\nPlease enter your name: ";
   cin >> userName;
   return userName;

}

