#include <iostream>
#include <iomanip>
using namespace std;

#include "ShoppingCart.h"

void PrintMenu() {
   cout << "MENU" << endl;
   cout << "d - Remove item from cart" << endl;
   cout << "c - Change item quantity" << endl;
   cout << "i - Output items' descriptions" << endl;
   cout << "o - Output shopping cart" << endl;
   cout << "q - Quit" << endl;
}

void ExecuteMenu(char option, ShoppingCart& theCart) {
   bool repeat = true;
    while(repeat == true){
        switch(option){
            case 'o':
                // add code
                break;
            default:
                repeat = false;
                break;
        }
    }
}

int main() {
   string customerName, date, description;
    char choice;

    cout << "Enter customer's name:" << endl;
    getline(cin, customerName);
    cout << "Enter today's date:" << endl;
    getline(cin, date);

    cout << endl;
    cout << "Customer name: " << customerName << endl;
    cout << "Today's date: " << date << endl;
    ShoppingCart cart(customerName, date);

    PrintMenu();
    cin >> choice;
    switch(choice){
        case 'a': case 'd': case 'c': case 'i': case 'o': case 'q':
            while(choice != 'q'){
                ExecuteMenu(choice, &cart);
            }
            break;
        default:
            cin >> choice;
    }
   
   return 0;
}
