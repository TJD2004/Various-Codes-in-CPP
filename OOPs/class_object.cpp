#include<iostream>
using namespace std;

class Heroes {

   private: // Access only inside the class
   char DC_heores;


   //properties
   public:  // Access inside as well as outside of class 
   char Marvel_heores;

   Heroes() {
      cout << "DEfault Constructor called" << endl;
   }

   Heroes(char DC_heroes) { // this stores current address
      this -> DC_heores = DC_heores;
   }

   // Copy Constructor
   Heroes(Heroes &temp) {
      this -> DC_heores = temp.DC_heores;
   }

   char get_DC_heroes() { // Getter -> (Indirectly access the private class)
      return DC_heores;
   }

   void set_DC_heroes(char ch) { // Setter -> (Indirectly set the value of private class)
      DC_heores = ch;
   }

   // Destructor 
   ~Heroes() {
      cout << "Destructor Called" << endl;
   }

};

int main() {

   //creation of object
   // statically
   Heroes h1;

   //dinamically
   Heroes *h2 = new Heroes; 

   cout << "size : " << sizeof(h1) << endl;
   cout << "Marvel heroes : " << h1.Marvel_heores << endl;
   // cout << "DC Heroes : " << h1.DC_heores << endl; // error

   cout << "size : " << sizeof(*h2) << endl;
   cout << "Marvel heroes : " << (*h2).Marvel_heores << endl; // Pointer Function

   cout << "Marvel heroes : " << h2->Marvel_heores << endl; // Arrow Function

   // Use of Setter
   h1.set_DC_heroes('*');
   h2->set_DC_heroes('&');  // Arrow Function
   (*h2).set_DC_heroes('$'); // Pointer Function

   // Use of Getter
   cout << "DC Heroes : " << h1.get_DC_heroes() << endl;
   cout << "DC Heroes : " << h2->get_DC_heroes() << endl; // Arrow Function
   cout << "DC Heroes : " << (*h2).get_DC_heroes() << endl;  // Pointer Function

   return 0;
}