#include <iostream>
using namespace std;
void pattern(int n , int i){
    if (n==0)
    return;
    pattern(n/2 , i);

    for(int k =0 ; k<i ; k++)
    cout<<" ";
    for(int k =0 ; k<n ; k++)
    cout<<"* ";
    cout<<endl;

    pattern(n/2, n+i+1/2 );



}
int main(){
    int n , i;
    cout<<"enter the the pattern n and i "<<endl;
    cin>>n>>i;
    pattern(n ,i);

}