#include "stock.h"
#include "hash.h"

int main(){
    Stock place_holder("NULL","NULL", 0, 0);
    Stock s0("AAA", "BBB",20, 300);
    Stock s1("FINN","MSFT",22,180);
    Stock s2("DRACULA","GOOGL",5,1800);
    Stock s3("FRANKENSTEIN","CSCO",2,38);
    Stock s4("SHACKLETON","JPM",9,97);
    Stock s5("POTTER","BAC",12,24);
    Stock s6("KING","AAWW",3,63);
    Stock s7("PARKER","FBP",1,90);
    Stock s8("WAYNE","AAA",2,633);
    Stock s9("RUTH","BBB",10,6);
    Stock s10("JACKSON","CCC",65,623);

    Hash h;
    int encrypter = h.encrypt(s3);
    h.decrypt(encrypter);
}
