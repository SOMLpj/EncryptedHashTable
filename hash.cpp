#include "hash.h"
#include "sha256.h"
#include "cmath"
#include "string"
#include "vector"


Stock empty_stock("NULL","NULL", 0, 0, "NULL"); //empty stock 
std::vector <int> v;

Hash::Hash(){
    size = 30, pos = 0;
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
    int e = encrypt(stock);
    
    while(true){ //while position is not free
        pos++;
        if(pos == size)
            copy_over();
        if(list[pos] == empty_stock) 
            break;
    }
    list[pos] = stock;
    std::string encrypted_name = std::to_string(e);
    std::cout<<"Adding "<< stock.get_buyer_name()<<std::endl;
    std::cout<<"Encrypting..."<<std::endl;
    stock.set_buyer_name(encrypted_name);
    std::cout<<"ADDED " << stock.get_buyer_name()<< " at index " << pos<< std::endl;

    
}

void Hash::add(Stock s){
    pos = hashify(s);
    if(list[pos].get_buyer_name() == "NULL"){ // if not occupied
        std::string encrypted_name = std::to_string(encrypt(s));
        std::cout<<"Adding "<< s.get_buyer_name()<<std::endl;
        std::cout<<"Encrypting..."<<std::endl;
        s.set_buyer_name(encrypted_name);
        list[pos] = s;
        std::cout<<"ADDED " << s.get_buyer_name()<< " at index " << pos<< std::endl;
    }
    else{
        std::cout<<"Collision detected."<<std::endl;
        std::cout<<"Handling..."<<std::endl;
        collision(s);
    } 
    std::cout<<"\n\n";
}

int Hash::hashify(Stock stock){ 
    std::string input = stock.get_password();//"df;oaiwjef";
    std::string output1 = sha256(input);
    int index = 0, temp;
    char c;
    for(int i = 0; i  < 5; i++){ 
       if(isdigit(output1[i])){
           index+= (output1[i] - '0');
           continue;
       }
       c = toupper(output1[i]);
       temp = letter_to_num(c);
       index+=temp;
    }
    return index;
}

long long Hash::letter_to_num(char c){
    switch(toupper(c)){
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

int Hash::encrypt(Stock s){
    std::string name = s.get_buyer_name();
    int name_val = 0;
    int private_key = s.get_password().length();
    v.push_back(private_key);
    for(int i = 0; i < name.length(); i++){
        int temp = letter_to_num(name[i]) + private_key;
        v.push_back(temp);
        if(temp / 10 == 0)
            name_val*=10;
        else    
            name_val*=100;
        name_val += temp;
    }
    return std::abs(name_val);
    
}

std::string Hash::decrypt(int val){
    Stock s;
    int private_key = v[0];
    std::string num = std::to_string(val);
    std::string result;
    for(int i = 0; i < v.size(); i++){
        char c = num_to_letter(v[i] - private_key) ;
        result += c;
    }
    std::cout<<val<< " --> " << result<<"\n\n";
    return result;
}

std::ostream& operator << (std::ostream& output, Hash hash){
    for(int i = 0; i < hash.size; i++)
        output<<"i: " <<i<< " "<< hash.list[i].get_buyer_name()<< " " << hash.list[i].get_symbol()<< " " << hash.list[i].get_shares()<< " " << hash.list[i].get_cost()<<std::endl;
    output<<std::endl;
    return output;
}
