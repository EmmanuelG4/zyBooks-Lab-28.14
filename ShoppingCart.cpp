#include <iostream>
#include "ShoppingCart.h"
#include <vector>

using namespace std;

//default constructor
ShoppingCart::ShoppingCart(){
  customerName = "none";
  currentDate = "January 1, 2016";
}

//constructor with parameters 
ShoppingCart::ShoppingCart(string name, string date){
  name = customerName;
  date = currentDate; 
}

string ShoppingCart::GetCustomerName() const{ return customerName; }

string ShoppingCart::GetDate() const{ return currentDate; }

void ShoppingCart::AddItem(ItemToPurchase ItemToAdd){
  cartItems.push_back(ItemToAdd);
}

void ShoppingCart::RemoveItem(string ItemToRemove){
  bool found = false;
  for(int i = 0; i < cartItems.size(); i++){
    if(ItemToRemove == cartItems.at(i).GetName()){
      cartItems.erase(cartItems.begin() + (i-1));
      found = true;
    }
  }
  if(found == false){
    cout << "Item not found in cart. Nothing removed." << endl;
  }
}

void ShoppingCart::ModifyItem(ItemToPurchase ItemToMod){
  bool found = false;
  for(int i = 0; i < cartItems.size(); i++){
    if(ItemToMod.GetName() == cartItems[i].GetName()){
      cartItems.at(i) = ItemToMod;
    }  
  }
  if(found == false){
    cout << "Item not found in cart. Nothing modified." << endl;
  }
}

int ShoppingCart::GetNumItemsInCart(){
  for(int count = 0; count < cartItems.size(); count++){
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
