#include <iostream>
#include "ShoppingCart.h"

using namespace std;

//default constructor
ShoppingCart::ShoppingCart(){
  customeName = "none";
  currentDate = "January 1, 2016";
}

//constructor with parameters 
ShoppingCart::ShoppingCart(string name, string date){
  name = customerName;
  date = currentDate;
}

string ShoppingCart::GetCustomerName(){ return customerName; }

string ShoppingCart::GetDate(){ return currentDate; }

void ShoppingCart::AddItem(string ItemToPurchase){
  cartItems.push_back(ItemToPurchase);
}

void ShoppingCart::RemoveItem(string ItemToRemove){
  bool found = false;
  for(int i = 0; i < cartItems.size() < i++){
    if(ItemToRemove == cartItems.at(i)){
      cartItems[i].erase();
      found = true;
    }
  }
  if(found == false){
    cout << "Item not found in cart. Nothing removed." << endl;
  }
}

void ShoppingCart::ModifyItem(string ItemToPurchase){
  bool found = false;
  for(int i = 0; i < cartItems.size(); i++){
    if(ItemToPurchase == cartItems[i].GetName()){
      cartItems.at(i) = ItemToPurchase;
    }  
  }
  if(found == false){
    cout << "Item not found in cart. Nothing modified." << endl;
  }
}

int ShoppingCart::GetNumItemsInCart(){
  for(int count = 0; i < cartItems.size(); count++){
    return count;
  }
}

double ShoppingCart::GetCostOfCart(){
  int totalCost = 0;
  for(int i = 0; i < cartItems.size(); i++){
    totalCost += cartItems[i].GetPrice();
  }
  return totalCost;
}





