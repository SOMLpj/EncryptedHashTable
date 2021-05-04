#ifndef HASH_H
#define HASH_H
#include <iostream>
#include "stock.h"

class Hash{
    private:
        
    public:
        Stock* list;
        int pos,size;
        Hash();
        void copy_over();
        void add(Stock);
        int hashify(Stock);
        void collision(Stock);
        void remove(Stock);
        long long letter_to_num(char);
        char num_to_letter(int);
        int encrypt(Stock);
        std::string decrypt(int);
        friend std::ostream& operator << (std::ostream& output, Hash hash);

};
#endif