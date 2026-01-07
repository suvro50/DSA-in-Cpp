#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

struct job{
    int job_number;
    int profit;
    int deadline;

};

bool cmp(job& a , job& b){
    return a.profit > b.profit;
}

// Function to find the maximum profit and the number of jobs done

vector<int> jobsequence(vector<job>& jobs ,int n){

   

    sort(jobs.begin(),jobs.end(),cmp);


    int maxdeadline=INT_MIN;
    for(int i=0;i<n;i++){
       maxdeadline=max(maxdeadline, jobs[i].deadline);
    }


    // +1 for use 1 based indexing
    vector<int> slot(maxdeadline+1,-1);

    int maxprofit=0;
    int number_of_jobs_done=0;

    for(int i=0;i<n;i++){

        for(int k=jobs[i].deadline; k>0; k--){

            if(slot[k] == -1){
                slot[k]=i;
                 maxprofit +=jobs[i].profit;
                 number_of_jobs_done++;
                 break;
            }
        }
    }

    // vector<int> ans;
    // ans.push_back(number_of_jobs_done);
    // ans.push_back(maxprofit);

    return { number_of_jobs_done , maxprofit};
    

}

int main(){

    int n;
    cout<<"Enter number of jobs: ";
    cin>> n;
    vector<job> jb(n);

    cin.ignore();
    for(int i=0;i<n;i++){
        cout<<"Enter details for job no "<<i+1<<": "<<endl;

        cout<<"Enter job_number: ";
        cin>>jb[i].job_number;

        cout<<"\nEnter job_profit: ";
        cin>>jb[i].profit;

        cout<<"\nEnter job_deadline: ";
        cin>>jb[i].deadline;

        cin.ignore();

    }

    vector<int> ans=jobsequence(jb,n);

    // for(auto i:ans){
    //     cout<<i<<" ";
    // }

    cout << "\nNumber of jobs done: " << ans[0] << endl;
    cout << "Maximum profit: " << ans[1] << endl;




    return 0;
}