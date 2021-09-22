#include<iostream>
using namespace std;


int getBit(int n, int pos){
  return  ((n & (1 << pos))!= 0 );
}


int setBit(int n,int pos){
    return (n | (1<<pos)) ;
}

int clearBit(int n,int pos){
  return (n &  (~(1 <<pos)));
}


int updateBit(int n,int pos,int value){
  //clearBit(n,pos);
    //setBit(n,pos);  // can be used directly//
  
  
   int mask =  (n &  (~(1 <<pos)));
   int mask2 = (n | (value << pos));
    
    return mask2;
}
int main(){
cout<< getBit(5,2)<<endl;

cout<< setBit(5,1)<<endl;

cout<<clearBit(5,2)<<endl;

cout<<updateBit(5,1,1)<<endl;
}