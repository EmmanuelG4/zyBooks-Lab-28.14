#include <iostream>
#include <iomanip>
using namespace std;

#include "ShoppingCart.h"

void PrintMenu(){
    cout << "MENU" << endl;
    cout << "a - Add item to cart" << endl;
    cout << "d - Remove item from cart" << endl;
    cout << "c - Change item quantity" << endl;
    cout << "i - Output items' descriptions" << endl;
    cout << "o - Output shopping cart" << endl;
    cout << "q - Quit" << endl;
}

void ExecuteMenu(char option, ShoppingCart& theCart){
    bool repeat = true;
    string name, description;
    int price, quantity;
    ItemToPurchase item(name, description, price, quantity);
    while(repeat == true){
        switch(option){
            case 'a':
                cout << "ADD ITEM TO CART" << endl;
                cout << "Enter the item name:" << endl;
                cin >> name;
                cout << "Enter the item description:" << endl;
                getline(cin, description);
                cout << "Enter the item price:" << endl;
                cin >> price;
                cout << "Enter the item quantity:" << endl;
                cin >> quantity;
                theCart.AddItem(item);
                break;
            case 'd':
                cout << "REMOVE ITEM FROM CART" << endl;
                cout << "Enter name of item to remove:" << endl;
                getline(cin, name);
                theCart.RemoveItem(name);
                break;
            case 'c':
                cout << "CHANGE ITEM QUANTITY" << endl;
                cout << "Enter the item name:" << endl;
                getline(cin, name);
                cout << "Enter the new quantity:" << endl;
                cin >> quantity;
                item.SetName(name);
                item.SetQuantity(quantity);
                theCart.ModifyItem(item);
                break;
            case 'i':
                cout << "OUTPUT ITEMS' DESCRIPTIONS" << endl;
                theCart.PrintDescriptions(); 
                break;
            case 'o':
                cout << "OUTPUT SHOPPING CART" << endl;
                theCart.PrintTotal();
                break;
            default:
                repeat = false;
                break;
        }
    }
}

int main(){
    string customerName, date, description;
    char choice;

    cout << "Enter customer's name:" << endl;
    getline(cin, customerName);
    cout << "Enter today's date:" << endl;
    getline(cin, date);

    cout << endl;
    cout << "Customer name: " << customerName << endl;
    cout << "Today's date: " << date << endl;
    cout << endl;
    ShoppingCart cart(customerName, date);

    PrintMenu();
    cout << endl;
    cout << "Choose an option:" << endl;
    cin >> choice;
    while(choice != 'q'){
        switch(choice){
            case 'a': case 'd': case 'c': case 'i': case 'o': case 'q':
                ExecuteMenu(choice, cart);
                break;
            default:
                cout << "Choose an option:" << endl;
                cin >> choice;
        }
    }

    return 0;
}
