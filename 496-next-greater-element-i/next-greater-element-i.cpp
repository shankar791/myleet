#include<stack>
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> temp(nums2.size(),-1),vt;
        //vector<int> vt;
        stack<int> st;
        temp[nums2.size()-1]= -1;
        for(int i=nums2.size()-1;i>=0;i--){
            while(!st.empty()&&nums2[i]>=st.top()){
                st.pop();
            }
            if(!st.empty()){
                temp[i]=st.top();           
            }
            st.push(nums2[i]);
        }
        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<nums2.size();j++){
                if(nums1[i]==nums2[j]){
                    vt.push_back(temp[j]);
                }
            }
        }
        return vt;
    }
};