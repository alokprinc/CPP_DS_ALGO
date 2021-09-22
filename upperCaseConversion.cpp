#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main(){

    // Conversion into Upper Case //
//     string str = "jhsdkschdskeugdcdfvnfdjkv";
// cout<< 'a' -'A'<<endl;

// for (int i = 0; i < str.size(); i++)
// {
//     if(str[i] >= 'a' && str[i] <= 'z'){
//         str[i] = str[i] -32;
//     } 
// }
// cout <<str<<" ";


//   // Conversion into Lower Case //
//     string str1 = "JHHTDRSYTFKUKYHLITYJSYTDFKU";


// for (int i = 0; i < str.size(); i++)
// {
//     if(str1[i] >= 'A' && str1[i] <= 'Z'){
//         str1[i] = str1[i] +32;
//     } 
// }
// cout <<str1<<" ";
// }

/// Function For Transforming To lower and Upper case  ///

// string str = "hkuhfweufheriufhreiufvhe";
// transform(str.begin(),str.end(),str.begin(),::toupper);
// cout<<str;

string a = "35465453513";

sort(a.begin(),a.end(), greater<int>());
cout<<a;
}