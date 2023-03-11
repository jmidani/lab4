//
//  main.cpp
//  Lab2
//
//  Created by Mohamed Basuony on 17/09/2022.
//

#include <iostream>
using namespace std;

class Box {
    
   private:
      double length;      // Length of a box
      double breadth;     // Breadth of a box
      double height;      // Height of a box
   public:
      double getVolume(void) {
         return length * breadth * height;
      }
      void setLength( double len ) {
         length = len;
      }
      void setBreadth( double bre ) {
         breadth = bre;
      }
      void setHeight( double hei ) {
         height = hei;
      }
      
      // Overload + operator to add two Box objects.
      Box operator+(const Box& b) {
         Box box;
         box.length = this->length + b.length;
         box.breadth = this->breadth + b.breadth;
         box.height = this->height + b.height;
         return box;
      }

      //Overloading * opperator to multiply heights
      double operator*(const Box& b){
        return height*b.height;
      }

      //Overloading == operator to compare all data members
      bool operator==(const Box& b){
        if(height==b.height&&breadth==b.breadth&&length==b.length){
            return true;
        }
        return false;
      }

      //Overloading <= operatore to compare lengths
      bool operator<=(const Box& b){
        if(length<=b.length){
            return true;
        }
        return false;
      }
};
// Main function for the program
int main() {
   Box Box1;                // Declare Box1 of type Box
   Box Box2;                // Declare Box2 of type Box
   Box Box3;                // Declare Box3 of type Box
   double volume = 0.0;     // Store the volume of a box here
   bool is_equal;
   bool length_lessOrEqual;
   double heights;

   // box 1 specification
   Box1.setLength(6.0);
   Box1.setBreadth(7.0);
   Box1.setHeight(5.0);
 
   // box 2 specification
   Box2.setLength(12.0);
   Box2.setBreadth(13.0);
   Box2.setHeight(10.0);
 
   // volume of box 1
   volume = Box1.getVolume();
   cout << "Volume of Box1 : " << volume <<endl;
 
   // volume of box 2
   volume = Box2.getVolume();
   cout << "Volume of Box2 : " << volume <<endl;

   // Add two object as follows:
   Box3 = Box1 + Box2;

   // volume of box 3
   volume = Box3.getVolume();
   cout << "Volume of Box3 : " << volume <<endl;

   // Height product
   heights=Box1*Box2;
   cout<<"Product of Box1 and Box2's heights : "<<heights<<endl;

    //Comparing all data members
    if(Box1==Box2){
        is_equal=true;
        cout<<"Boxes are equal.\n";
    }
    else{
        is_equal=false;
        cout<<"Boxes are not equal.\n";
    }

    //Comparing lengths
    if(Box1<=Box2){
        length_lessOrEqual=true;
        cout<<"Length of Box1 is smaller or equal to Box2.\n";
    }
    else{
        length_lessOrEqual=false;
        cout<<"Length of Box1 is bigger than Box2.\n";
    }
    

   return 0;
}