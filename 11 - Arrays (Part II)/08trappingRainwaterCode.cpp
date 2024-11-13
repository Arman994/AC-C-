class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int leftMax[20000], rightMax[20000]; 
        leftMax[0] = height[0];    //   Problem in subtraction with int min so
        rightMax[n-1] = height[n-1];             //   n-1

        for(int i =1; i<height.size(); i++) {
            leftMax[i] = max(height[i-1], leftMax[i-1]);    //   i-1
        }
        
        for(int i =n-2; i>=0; i--) {
            rightMax[i] = max(height[i+1], rightMax[i+1]);    //   i+1
        }
        
        int waterTrapped = 0;
        
        for(int i=0; i<height.size(); i++) {
            int currWater = min(leftMax[i], rightMax[i]) - height[i];
            if(currWater > 0) {
                waterTrapped += currWater;
            }
        }
        return waterTrapped;
    }
};