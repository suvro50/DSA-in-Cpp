#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct Item{
    int weight;
    int value;
    
};

bool cmp(Item a, Item b){
    double r1=(double)a.value / (double)a.weight ;
    double r2=(double)b.value / (double)b.weight ;

    return r1 > r2;

}

void fractional_Knapsack(vector<Item>& v, int capacity){

    sort(v.begin(),v.end(),cmp);

    double totalValue = 0.0;
    int currentWeight = 0;

    for(int i=0;i<v.size();i++){

        if(currentWeight + v[i].weight <= capacity){

            currentWeight +=v[i].weight;
            totalValue+=v[i].value;

        }else{
            //  here currentWeight means how many weight full in bag
            int remain=capacity -currentWeight;

          
            double currect_per_kg_value= (double)v[i].value / (double)v[i].weight;

            double fraction =remain*currect_per_kg_value;
            totalValue+=fraction;
            break;

        }
    }

    cout<<"Maximum profit with "<<capacity<<" kg : "<<totalValue;

}
 

int main(){

    // { weight, value};
    vector<Item> v={ {10, 60}, {20, 100}, {30, 120} };

    int w=50;


    fractional_Knapsack(v,w);


    return 0;
}