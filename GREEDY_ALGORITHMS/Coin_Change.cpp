#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;



void minimum_coins_need(vector<int>& v,int ammount){

    int totalcoin=0;
    vector<int> usecoin;
    for(int i=0;i<v.size();i++){
        
        if(ammount >= v[i]){   // if the ammount is grater than i peak the coin
            int count= ammount / v[i];  // how many time i can get this coin suppose , ammount=43, v[i]=4 : 43/4=10 , so i peck this coin 10 time
            ammount -= count*v[i];  //(-) coin ammount 10*4 =40 , so 43-40=3
            
            totalcoin+=count;  // How much coin i take , add that
            usecoin.push_back(v[i]);  // add coin number in vector
        }  
    }
    cout<<"Minimum number of coin need: "<<totalcoin<<endl;

    cout<<"Coins numbers: ";
    for(auto i: usecoin){
        cout<<i<<" ";
    }
}

int main(){

    int n;
    cout<<"Enter number of coin: ";
    cin>>n;

    vector<int> v(n);
    cout<<"Enter coin Denominations: ";
    for(int i=0;i<v.size();i++){
        cin>>v[i];
    }

    sort(v.rbegin(),v.rend());  //decending order sort

    int ammount;
    cout<<"Enter ammount: ";
    cin>>ammount;

    minimum_coins_need(v,ammount);

    return 0;
}