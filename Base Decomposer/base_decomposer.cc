//  Copyright 2019 by Victoria Condos
#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::string;
using std::to_string;

string decomposer(string digits) {
  string components = "";  // create a string to store parts of sequence
    for (unsigned int i = 0; i < digits.length() ; ++i) {
      components.append(digits.substr(i, 1));
      for (unsigned int j = digits.length()-1 ; j > i ; --j) {  // add 0s
        if (digits.substr(i, 1).compare("0") == 0) {
        // don't append more zeros if the digit is 0
         } else {
          components.append("0");
         }
      }
      if (i != digits.length() - 1) {
        components.append(" + ");  //  add the plus sign at end
      }
    }
  return components;  // return string at the end
  return 0;
}

int main() {
  int user_value;
  // Prompt user & store in variable
  // cout << "Enter Integer: ";
  cin >> user_value;
  string user_digits;  // copy before manipulating
  // check if value is positive or negative
  if (user_value > 0) {
     user_digits = to_string(user_value);  // convert user value to string
     cout << decomposer(user_digits);
  } else {
    user_value *= -1;  // make user value positive
    user_digits = to_string(user_value);  // convert user value to string
    cout << "-(";
    cout << decomposer(user_digits);  // call decomposer function here
    cout << ")";
  }
  return 0;
}
                    
