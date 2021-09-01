#include"vector"
#include"algorithm"
#include"iostream"
#include"queue"
using namespace std;

class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int,vector<int>,greater<int>> minHeap;
    priority_queue<int,vector<int>,less<int>> maxHeap;

    MedianFinder() {}

    void addNum(int num) {
        if(minHeap.empty() || num > minHeap.top()){
            minHeap.push(num);
            if(minHeap.size()-maxHeap.size()>1){
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }
        }
        else{
            maxHeap.push(num);
            if(maxHeap.size()-minHeap.size()>0){
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            }
        }
        //cout<<"Add: "<<num<<' '<<minHeap.size()<<' '<<maxHeap.size()<<endl;
    }

    double findMedian() {
        if(minHeap.size()!=maxHeap.size()){
            //cout<<"Find: "<<minHeap.size()<<' '<<maxHeap.size();
            return minHeap.top();
        }
        else{
            return (maxHeap.top()+minHeap.top())/2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */


int main(){
    priority_queue<int,vector<int>,greater<int>> minHeap;
    minHeap.push(1);
    minHeap.push(2);
    minHeap.push(3);
    cout<<minHeap.top();
    return 0;
}
