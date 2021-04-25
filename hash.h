#ifndef HASH_H
#define HASH_H
#include <iostream>
#include "stock.h"

class Hash{
    private:
        Stock* list;
        int pos,size;
    public:
        Hash();
        void copy_over();
        void add(Stock);
        int hashify(Stock);
        void collision(Stock);
        void remove(Stock);
        friend std::ostream& operator << (std::ostream& output, Hash hash);
        

};
#endif