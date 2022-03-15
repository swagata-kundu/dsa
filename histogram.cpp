#include<stack>
#include <bits/stdc++.h>


class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s1,s2;
        vector<int> left;
        vector<int> right;
        
        int length=heights.size();
        
        for(int i=0;i<length;i++){
            
            while(!s1.empty()){

                if(heights[s1.top()]<heights[i]){
                    break;
                }
                s1.pop();
            }
                
            if(s1.empty()){
                left.push_back(-1);
            }else{
                left.push_back(s1.top());
            }
            s1.push(i);
        }
        
        for(int i=length-1;i>=0;i--){
            
            while(!s2.empty()){

                if(heights[s2.top()]<heights[i]){
                    break;
                }
                s2.pop();
            }
                
            if(s2.empty()){
                right.push_back(length);
            }else{
                right.push_back(s2.top());
            }
            s2.push(i);
        }
    
    reverse(right.begin(), right.end());
    int maxarea=0;
    for(int i=0;i<length;i++){
        int area=(right[i]-left[i]-1)*heights[i];
        if(area>maxarea){
            maxarea=area;
        }
    }
    return maxarea;
        
    }
};