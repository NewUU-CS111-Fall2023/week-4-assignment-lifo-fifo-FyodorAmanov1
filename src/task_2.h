#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

int main() {

    int N;
    cin >> N;
    deque<int> train_order;
    for(int i=0;i<N;i++) {
        int m;
        cin>>m;
        train_order.push_front(m);
    }

    deque<int> dead_end_queue;
    deque<int> track_2;

    int k=1;
    int l=1;
    bool flag= true;
    int count_in=0;
    int count_out=0;
    while(flag){
             if(k==train_order.front()){
                 count_in++;
                 k++;
             }

             dead_end_queue.push_front(train_order.front());
             train_order.pop_front();
             if(train_order.empty()){
                 flag= false;
             }
        if(dead_end_queue.back()==l){
                    track_2.push_back(dead_end_queue.back());
                   dead_end_queue.pop_back();
                   count_out++;
                   l++;
        }

      }
if(dead_end_queue.empty()){
    cout<<"possible";
} else{
    cout<<"not possible";
}

    }