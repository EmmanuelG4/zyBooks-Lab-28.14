#include <iostream>
using namespace std;

#include "ItemToPurchase.h"

//constructor
ItemToPurchase::ItemToPurchase(){
  itemName = "none";
  itemPrice = 0;
  itemQuantity = 0;
}

ItemToPurchase::ItemToPurchase(string name, string description, int price, int quantity = 0){
  itemName = name;
  itemDescription = description;
  itemPrice = price;
  itemQuantity = quantity;
}

// getters
string ItemToPurchase::GetName() const{
  return itemName;
}
string ItemToPurchase::GetDescription() const{
  return itemDescription;
}
int ItemToPurchase::GetPrice() const{
  return itemPrice;
}
int ItemToPurchase::GetQuantity() const{
  return itemQuantity;
}

// setters
void ItemToPurchase::SetName(string name){
  itemName = name;
}
void ItemToPurchase::SetDescription(string description){
  itemDescription = description;
}
void ItemToPurchase::SetPrice(int newPrice){
  itemPrice = newPrice;
}
void ItemToPurchase::SetQuantity(int newQuantity){
  itemQuantity = newQuantity;
}

// extra
void ItemToPurchase::PrintItemCost(){
  cout << itemName << " " << itemQuantity << " @ $" << itemPrice << " = $" << (itemQuantity * itemPrice) << endl;
}
void ItemToPurchase::PrintItemDescription(){
  cout << itemName << ": " << itemDescription << endl;
}
