#include "hash.h"
#include "sha256.h"
#include "cmath"
#include "string"
#include "vector"


Stock empty_stock("NULL","NULL", 0, 0, "NULL"); //empty stock 
std::vector <int> v;

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


void Hash::collision(Stock stock){ //WILL PROBABLY USE CHAINING (LINKED LISTS) TO HANLDE COLLISIONS
    
    while(true){ //while position is not free
        pos++;
        if(pos == size)
            copy_over();
        if(list[pos] == empty_stock) 
            break;
    }
    list[pos] = stock;
}

void Hash::add(Stock& s){
    pos = hashify(s);
    if (pos > size)
        copy_over();
    if(list[pos].get_buyer_name() == "NULL"){ // if not occupied
        std::string encrypted_name = std::to_string(encrypt(s));
        s.set_buyer_name(encrypted_name);
        list[pos] = s;
    }
    else //if occupied --> collision
        collision(s);
}

int Hash::hashify(Stock stock){ 
    std::string input = stock.get_password();//"df;oaiwjef";
    std::string output1 = sha256(input);
    std::cout<<output1<<std::endl;
    char*str;
    int num = 0;
    int length = output1.length();
    int j;

    for (int i = 0; i < 3; i++ ){
        j = get_rand(length);
        std::cout << "INDEX " << j << " VALUE ";
        str[i] = output1[j];
        std::cout << str[i] << std::endl;
        num += str[i];
    }
    return num;
}

int Hash::get_rand(int x){
    int temp = x;
    while(temp--){
        x = rand() % x + 0;
    }
    return x;
}

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

long long Hash::letter_to_num(char c){
    switch(c){
        case 'A':
        return 1;
        case 'B':
        return 2;
        case 'C':
        return 3;
        case 'D':
        return 4;
        case 'E':
        return 5;
        case 'F':
        return 6;
        case 'G':
        return 7;
        case 'H':
        return 8;
        case 'I':
        return 9;
        case 'J':
        return 10;
        case 'K':
        return 11;
        case 'L':
        return 12;
        case 'M':
        return 13;
        case 'N':
        return 14;
        case 'O':
        return 15;
        case 'P':
        return 16;
        case 'Q':
        return 17;
        case 'R':
        return 18;
        case 'S':
        return 19;
        case 'T':
        return 20;
        case 'U':
        return 21;
        case 'V':
        return 22;
        case 'W':
        return 23;
        case 'X':
        return 24;
        case 'Y':
        return 25;
        case 'Z':
        return 26;
    }
    return 0;
}

char Hash::num_to_letter(int val){
     switch(val){
        case 1:
        return 'A';
        case 2:
        return 'B';
        case 3:
        return 'C';
        case 4:
        return 'D';
        case 5:
        return'E';
        case 6:
        return 'F';
        case 7:
        return 'G';
        case 8:
        return 'H';
        case 9:
        return 'I';
        case 10:
        return 'J';
        case 11:
        return 'K';
        case 12:
        return 'L';
        case 13:
        return 'M';
        case 14:
        return 'N';
        case 15:
        return 'O';
        case 16:
        return 'P';
        case 17:
        return 'Q';
        case 18:
        return 'R';
        case 19:
        return 'S';
        case 20:
        return 'T';
        case 21:
        return 'U';
        case 22:
        return 'V';
        case 23:
        return 'W';
        case 24:
        return 'X';
        case 25:
        return 'Y';
        case 26:
        return 'Z';
    }
    return ' ';
}

int Hash::encrypt(Stock& s){
    std::string name = s.get_buyer_name();
    int name_val = 0;
    for(int i = 0; i < name.length(); i++){
        int temp = letter_to_num(name[i]);
        v.push_back(temp);
        if(temp / 10 == 0)
            name_val*=10;
        else    
            name_val*=100;
        name_val += letter_to_num(name[i]);
    }
    std::cout<<"Encrypted name: " <<name_val<<std::endl;
    return std::abs(name_val);
}

std::string Hash::decrypt(int val){
    Stock s;
    std::string num = std::to_string(val);
    std::string result;
    for(int i = 0; i < v.size(); i++){
        char c = num_to_letter(v[i]);
        result += c;
    }
    std::cout<<"Decrypted name: " << result<<std::endl;
    return result;
}

std::ostream& operator << (std::ostream& output, Hash hash){
    for(int i = 0; i < hash.size; i++)
        output<<hash.list[i].get_buyer_name()<< " " << hash.list[i].get_symbol()<< " " << hash.list[i].get_shares()<< " " << hash.list[i].get_cost()<<std::endl;
    output<<std::endl;
    return output;
}
