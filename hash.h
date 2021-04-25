#ifndef HASH_H
#define HASH_H
#include <iostream>
#include "stock.h"

class Hash{
    private:
        Stock* list;
        int pos,size;
    public:
        Hash(Stock empty_stock);
        void copy_over(Stock empty_stock);
        void add(Stock stock);
        int hashify(Stock stock);
        void collision(Stock stock);
        void remove(Stock stock);
        friend std::ostream& operator << (std::ostream& output, Hash hash);
};
#endif