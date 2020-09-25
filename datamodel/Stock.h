#include<iostream>
#include<vector>
#include"Item.h"
#include"../headers/parser.hpp"
//Mini-Project/datamodel/Stock.cpp
using namespace std;

class Stock {
private:
    ifstream fin;
    ofstream fout;
    vector<Item> stockList;
    static Stock* instance;

    Stock() {
        fin.open("stock.csv");
    }

public:

    static Stock* getInstance() {
        if(!instance)
            instance = new Stock();
        return instance;
    }

    void readStock() {
        string line;
        if(fin.is_open()) {
            cout << "File is Open.\n";
            aria::csv::CsvParser parser(fin);
            for (auto& row : parser) {
                string stock[3];
                int i = 0;
                for (auto& field : row) {
                    stock[i++] = field;
                }
                Item item(stock[0], stoi(stock[1]), stoi(stock[2]));
                stockList.push_back(item);
            }
        } else {
            cout<<"Unable to open file!\n";
            exit(0);
        }
        cout<<"Stock: "<<endl;
        for(auto& itr : stockList) {
            cout<<"\t"<<itr.toString()<<endl;
        }
        fin.close();
    }

    vector<Item>* getStocks() {
        return &stockList;
    }

    void writeStock() {
        fout.open("../stock.csv");
        for(auto& itr : stockList) {
            fout<<itr.getName()<<","<<itr.getPrice()<<","<<itr.getQuantity()<<endl;
        }
        fout.close();
    }
};

Stock *Stock::instance = nullptr;

