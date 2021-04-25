#include "stock.h"

int main(){
    Stock place_holder("NULL","NULL", 0, 0);
    Stock s0("TOM SAWYER", "APPL",20, 300);
    Stock s1("HUCKLEBERRY FINN","MSFT",22,180);
    Stock s2("COUNT DRACULA","GOOGL",5,1800);
    Stock s3("VICTOR FRANKENSTEIN","CSCO",2,38);
    Stock s4("ERNEST SHACKLETON","JPM",9,97);
    Stock s5("HARRY POTTER","BAC",12,24);
    Stock s6("STEPHEN KING","AAWW",3,63);
    Stock s7("PETER PARKER","FBP",1,90);
    Stock s8("BRUCE WAYNE","AAA",2,633);
    Stock s9("BABE RUTH","BBB",10,6);
    Stock s10("SAMUEL JACKSON","CCC",65,623);

    std::string name = "r ock y";
    // for (int i = 0; i < name.length(); i++){
    //     if(name[i] == ' ')
    //         continue;
    //     std::cout<<name[i];
    // }    
    for(int i = 'a'; i < 'z'; i++){
        std::cout<<(char)i<< " " << i<< std::endl;
    }

    
}
