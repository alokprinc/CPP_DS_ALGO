#include <iostream>
#include <climits>
using namespace std;

int main() {
int arr[6] ={  12 ,-32 ,40 , -5};
int maxNo =INT_MIN ,minNo =INT_MAX;

for (int i = 1; i <= 4; i++)
{
   maxNo = max(arr[i] , maxNo);
    minNo = min(arr[i], minNo);

}

cout<< maxNo <<" "<< minNo <<endl;
}
