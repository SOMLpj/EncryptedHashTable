#include "stock.h"

Stock::Stock(){

}

Stock::Stock(std::string buyer_name, std::string symbol, int shares, int cost){
    this -> buyer_name = buyer_name; 
    this -> symbol = symbol; 
    this -> cost = cost;
    this -> shares = shares; 
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

std::ostream& operator << (std::ostream& output, Stock stock){
    output<<stock.symbol<< " "<<stock.shares<<" $"<<stock.cost<<std::endl;
    return output;
}

bool operator == (Stock s1, Stock s2){
    if(s1.buyer_name == s2.buyer_name && s1.symbol == s2.symbol && s1.cost == s2.cost && s1.shares == s2.shares)
        return true;
    return false;
}

