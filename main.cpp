#include "stock.h"
#include "hash.h"

int main(){
    Stock place_holder("NULL","NULL", 0, 0, "NULL");
    Stock s0("HUCKLEBERRY", "APPL",20, 300, "apple");
    Stock s1("FINN","MSFT",22,180,"orange");
    Stock s2("Huck","GOOGL",5,1800,"peanut");
    Stock s3("FRANKENSTEIN","CSCO",2,38,"cheese");
    Stock s4("SHACKLETON","JPM",9,97,"onions");
    Stock s5("POTTER","BAC",12,24,"syrup");
    Stock s6("KING","AAWW",3,63, "avocado");
    Stock s7("PARKER","FBP",1,90, "security");
    Stock s8("WAYNE","AAA",2,633, "helloworld");
    Stock s9("RUTH","BBB",10,6, "potatoes");
    Stock s10("JACKSON","CCC",65,623,"timex");

    Hash h;
    // TEST DECRYPTION HERE
    int e = h.encrypt(s8);
    h.decrypt(e);
    
    //ADD STOCK OBJECTS HERE
    h.add(s2);
    h.add(s1);
    h.add(s3);
    h.add(s3);
    h.add(s4);
    h.add(s5);
    h.add(s6);
    h.add(s7);
    h.add(s8);
    h.add(s9);
    h.add(s10);

    //PRINT
    std::cout<<h<<std::endl;

}
