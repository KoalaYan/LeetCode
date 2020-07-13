#include"vector"
#include"algorithm"
#include"iostream"
using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        //sol-1
        /*
        vector<int>::iterator it1 = nums1.begin();
        vector<int>::iterator it2 = nums2.begin();
        while(it1 != nums1.end() && it2 != nums2.end()){
            if(*it1 == *it2){
                res.push_back(*it1);
                it1++;
                it2++;
            }
            else if(*it1 < *it2){
                it1++;
            }
            else{
                it2++;
            }
        }
        */
        int i = 0;
        int j = 0;
        int e1 = nums1.size();
        int e2 = nums2.size();
        while(i!=e1&&j!=e2){
            if(nums1[i]==nums2[j]){
                res.push_back(nums1[i]);
                i++;
                j++;
            }
            else if(nums1[i]<nums2[j]){
                i++;
            }
            else{
                j++;
            }
        }
        return res;
    }
};

int main(){
    vector<int> nums1 = {1,2,2,1};
    vector<int> nums2 = {2,2};
    Solution sol;
    //cout<<sol.intersect(nums1, nums2);
    return 0;
}
