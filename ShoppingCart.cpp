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
  customerName = name;
  currentDate = date; 
  vector<ItemToPurchase> cartItems;
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
  return cartItems.size();
}

double ShoppingCart::GetCostOfCart(){
  int totalCost = 0;
  for(int i = 0; i < cartItems.size(); i++){
    totalCost += (cartItems[i].GetPrice()*cartItems[i].GetQuantity());
  }
  return totalCost;
}

void ShoppingCart::PrintTotal(){
  cout << customerName << "'s Shopping Cart - " << currentDate << endl;
  cout << "Number of Items: " << cartItems.size() << endl;
  cout << endl;
  if(GetNumItemsInCart() > 0){  
    for(int i = 0; i < cartItems.size(); i++){
      cout << cartItems[i].GetName() << " " << cartItems[i].GetQuantity() << " @ $" << cartItems[i].GetPrice() << " = $" << (cartItems[i].GetQuantity() * cartItems[i].GetPrice()) << endl; 
    }
    cout << endl;
  }
  else{
    cout << "SHOPPING CART IS EMPTY" << endl;
  }
  cout << endl;
  cout << "Total: $" << GetCostOfCart();
}

void ShoppingCart::PrintDescriptions(){
  if(GetNumItemsInCart() > 0){
    cout << customerName << "'s Shopping Cart - " << currentDate << endl;
    cout << endl;
    cout << "Item Descriptions" << endl;
    
    for(int i = 0; i < cartItems.size(); i++){
      cout << cartItems[i].GetName() << ": " << cartItems[i].GetDescription() << endl;
    }
  }
  else{
    cout << "SHOPPING CART IS EMPTY" << endl;
  }
}
