#include "stock.h"

Stock::Stock(){

}

Stock::Stock(std::string buyer_name, std::string symbol, int shares, int cost, std::string password){
    this -> buyer_name = buyer_name; 
    this -> symbol = symbol; 
    this -> cost = cost;
    this -> shares = shares; 
    this -> password = password; 

}

std::string Stock::get_buyer_name(){
    return this -> buyer_name;
}

std::string Stock::get_symbol(){
    return this -> symbol;
}

int Stock::get_cost(){
    return this-> cost;
}

int Stock::get_shares(){
    return this -> shares;
}

void Stock::set_buyer_name(std::string s){
    this -> buyer_name = s;
}

std::string Stock::get_password(){
    return this -> password;
}


std::ostream& operator << (std::ostream& output, Stock stock){
    output<<stock.symbol<< " "<<stock.shares<<" $"<<stock.cost<<std::endl;
    return output;
}

bool operator == (Stock s1, Stock s2){
    if(s1.get_buyer_name() == s2.get_buyer_name() && s1.get_symbol() == s2.get_symbol() && s1.get_cost() == s2.get_cost() && s1.get_shares() == s2.get_shares() && s1.get_password() == s2.get_password())
        return true;
    return false;
}

