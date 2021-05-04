// #include "cryptlib.h"
// #include "sha.h"
// #include <iostream>

// int main (int argc, char* argv[])
// {
//     using namespace CryptoPP;

//     SHA256 hash;	
//   

#include <iostream>
#include "sha256.h"
 
using namespace std;
int main(int argc, char *argv[])
{
    string input = "something";
    string output1 = sha256(input);
 
    cout << "({"<< input << "}):" << output1 << endl;
    return 0;
}