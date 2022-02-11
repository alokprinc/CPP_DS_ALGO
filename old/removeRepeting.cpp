#include <iostream>
using namespace std;

string removeR(string s){

if(s.length()==0){
    return "";
}

    char ch = s[0];
    string ans = removeR(s.substr(1));

    if(ch ==ans[0]){
        return ans;   
         }
             return (ch+ans);
}
int main (){
  
cout<<removeR("aaaaabbeeeejjjjddddddlllllsuuueedncnsakjbsakjjkfhkfgebhkjbjjjjffffjhgjyrhhhh");

}