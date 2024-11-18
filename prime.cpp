#include <iostream>
using namespace std;

// int main() {
//     int n;
//     cin>>n;

//     bool isPrime = 1;

//     for(int i = 2; i<=n; i++) {
//         if(n%i==0){
            
//             isPrime = 0;
//             break;
            
//         }
        
//     }
//     if(isPrime == 0){
        
//         cout<<"Not a prime number"<<endl;
        
//     }
//     else{

//         cout<<"prime number"<<endl;
//     }
//     return 0;
// }


bool isPrime(int n){
    
    for(int i = 2; i<n; i++) {
        if(n % i == 0 ||  n % 5 == 0) {
            return 0;
        }
       
    }  
    return 1;  
}
int main() {

    int num;
    cin >> num;
    
    if(isPrime(num)) {
        cout <<"is a prime number";
    }
    else
    {
        cout<<"not a prime number";
    }

    
}