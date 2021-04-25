#include "hash.h"
#include "cmath"
Stock empty_stock("NULL","NULL", 0, 0); //empty stock 

Hash::Hash(){
    size = 10, pos = 0;
    list = new Stock[size];
    for(int i = 0; i < size; i++) //place holder value for table
        list[i] = empty_stock;
}

void Hash::copy_over(){
    int copy = size;
    size = pos + 10;
    for(int i = copy; i < size; i++)
        list[i] = empty_stock; //increased list size
}

//*** WORK IN PROGRESS ***
// int Hash::hashify(Stock stock){ 
//     std::string buyer_name = stock.get_buyer_name();
//     int last = '\0'; //empty last initial
//     int first = buyer_name[0]; //setting first initial
//     for(int i = 0; i < buyer_name.length(); i++){
//         if(buyer_name[i] == ' ') //if space
//             int last = buyer_name[i+1]; //setting last initial
//     }
//     if(last != '\0'){ //if last initial is set
//         int loc = std::abs(first-last);
//     }
//     int loc = 0;
//     return loc;
// }

void Hash::collision(Stock stock){
    
    while(true){ //while position is not free
        pos++;
        if(pos == size)
            copy_over();
        if(list[pos] == empty_stock) 
            break;
    }
    list[pos] = stock;
}

//*** WORK IN PROGRESS ***
// void Hash::add(int val){
//     pos = hashify(val);
//     if (pos > size)
//         copy_over();
//     if(list[pos] == 0 || list[pos] == -1) // if not occupied
//         list[pos] = val;
//     else //if occupied --> collision
//         collision(val);
// }

// void Hash::remove(int val){
//     pos = hashify(val);
//     if(list [pos] == val){
//         std::cout<<"Element removed: "<< val<<std::endl;
//         list[pos] = -1; //removed
//     }
//     else{
//         while(true){
//             pos++;
//             if(size < pos){
//                 std::cout<<"Could not find element: "<< val<< std::endl; 
//                 break;
//             }
//             if(list[pos] == val){
//                 std::cout<<"Element removed: "<< val<<std::endl;
//                 list[pos] = -1;
//                 break;
//             }
//         }
//     }
// }

std::ostream& operator << (std::ostream& output, Hash hash){
    for(int i = 0; i < hash.size; i++)
        output<<hash.list[i]<< " ";
    output<<std::endl;
    return output;
}
