#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct Item{
    int index;
    string name;
    int weight;
    double value;  

    void print(){
        cout<<"Index: "<<index<<"| Name: "<<name<<" | weight:"<<weight<<" | value: "<<value<<endl;
    }
};

bool cmp(const Item& a, const Item& b){
    double r1=(double)a.value  / (double)a.weight ;
    double r2=(double)b.value / (double)b.weight ;

    if(r1==r2){
        return a.value > b.value;
    }
    if(a.value==b.value){
        return a.index > b.index;
    }

    return r1 > r2;

}

void fractional_Knapsack(vector<Item>& v, int capacity){

    sort(v.begin(),v.end(),cmp);

    double totalValue = 0.0;
    int currentWeight = 0;

    vector<Item> selected;

    for(int i=0;i<v.size();i++){

        if(currentWeight + v[i].weight <= capacity){

            selected.push_back(v[i]);
            currentWeight +=v[i].weight;
            totalValue+=v[i].value;

        }else{
            // here currentWeight means how many weight full in bag
            int remain=capacity - currentWeight;

          
            double per_kg_value= (double)v[i].value / (double)v[i].weight;

            double fraction =remain*per_kg_value;
            totalValue+=fraction;
            Item partialItem=v[i];

            partialItem.name=v[i].name+"(Partial)";

            partialItem.weight=remain;
            partialItem.value=fraction;
            
            selected.push_back(partialItem);
            break;

        }
    }

    cout<<"Maximum profit with "<<capacity<<" kg : "<<totalValue;

    cout<<"\nSelected Items: "<<endl;
    for(auto i:selected){
        i.print();
    }

}
 
int main(){ 

    int n;
    cout<<"Enter number of items: ";
    cin>>n;

    cin.ignore();
    vector<Item> v(n);

    for(int i=0;i<v.size();i++){
        v[i].index = i + 1;
        cout<<"Enter info for item no "<<i+1<<": "<<endl;


        cout<<"Enter name: ";
        getline(cin,v[i].name);

        cout<<"Enter weight: ";
        cin>>v[i].weight;

        cout<<"Enter value: ";
        cin>>v[i].value;

         cin.ignore();

    }

    int w;
    cout<<"Enter capacity in (kg): ";
    cin>>w;
    
    fractional_Knapsack(v,w);


    return 0;
}