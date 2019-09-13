/****************************************
* Contestant number 04-0207-0001
****************************************/

#include <iostream>
#include <cstdio>
#include <string>

#include "Input.h"

using namespace std;

// This method gets input and processes, then returns pay value.
int getInput(void)
{
     string input;  // Actual input string
     int hours[7];  // Array holding processed hours throughout week
     float pay = 0;     // Pay sum
     
     // Get user input
     cout << ">";
     cin >> input;
     
     int j = 0;   // Represents position of last comma
     int k = 0;   // Represents position in hours array
     // Loop for each character in string
     for(int i = 0; i < input.size(); i++)
     {
             // If character is comma, reached end of last number
             if(input[i] == ',')
             {
                         // Get substring and assign number
                         int ans = atoi(input.substr(j, i - j).c_str());
                         
                         // Move j to new comma
                         j = i + 1;
                         
                         // Add number to hours, then increase counter
                         hours[k] = ans;
                         k++;
             }
     }
     // For last number, as there is no comma to end the string
     hours[6] = atoi(input.substr(j, input.size() - j).c_str());
     
     // If all zeros were entered, return 0 reresents quit
     if(hours[0] == 0 && hours[1] == 0 && hours[2] == 0 && hours[3] == 0 && hours[4] == 0 && hours[5] == 0 && hours[6] == 0)
     {
                 return 0;
     }
     
     int hourSum = 0;   // For if work hours > 40
     for(int i = 0; i < 7; i++)
     {
             hourSum += hours[i]; // Accumulate hours into total
             float factorRate = 10;  // Standard factor rate (pay) of $10
             
             // If hours worked are more than 8
             if(hours[i] > 8)
                  factorRate += 1.50;
             // If more than 40 hours a week worked
             if(hourSum > 40)
                        factorRate += 2.50;
             // If working on Sunday
             if(i == 0 && hours[i] > 0)
                  factorRate *= 1.5;
             // If working on Saturday
             if(i == 6 && hours[i] > 0)
                  factorRate *= 2.25;
             
             // Add to pay
             pay += hours[i] * factorRate;
     }
     // Display with .00 format
     printf("$%.2f", pay);
     cout << endl;
     
     // Successful, return 1 represents continue
     return 1;
}
