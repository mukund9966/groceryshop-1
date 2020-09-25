#include<iostream>
#include"datamodel/Stock.h"
using namespace std;

void opening() {
    cout<<"************Welcome to the Budget Food - The Grocery Store************\n";
    cout<<"Developed By - Saransh Kumar, Shivang Dubey, Mukund Khandelwal\n";
}

int main() {
    opening();
    Stock::getInstance()->readStock();
    return 0;
}
