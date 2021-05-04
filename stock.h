#ifndef STOCK_H
#define STOCK_H
#include <iostream>

class Stock{
    private:
        std::string buyer_name, symbol, password;   
        int shares, cost;
    public:
        
        Stock();
        Stock(std::string buyer_name, std::string symbol, int shares, int cost, std::string password);

        std::string get_buyer_name();
        std::string get_symbol();
        int get_shares();
        int get_cost(); 
        std::string get_password();

        void set_buyer_name(std::string);
        
        friend std::ostream& operator << (std::ostream& output, Stock stock);
        friend bool operator == (Stock s1, Stock s2);
};

#endif