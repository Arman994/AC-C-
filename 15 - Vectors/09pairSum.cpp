 #include <iostream>
 #include <vector>
 using namespace std;

vector<int> twoSum(vector<int>& numbers, int target) {
    int st=0, end=numbers.size() - 1;
    vector<int> ans;
    while(st<end) {
        int currSum = numbers[st] + numbers[end];
        if(currSum == target) {
            ans.push_back(st);
            ans.push_back(end);
            return ans;
        }else if(currSum > target) {
            end--;
        }else {
            st++;
        }
    }
    return ans;
}

int main() {
    vector<int> arr = {2, 7, 11, 15};
    int target = 9;
    vector<int> ans = twoSum(arr, target);
    cout << ans[0] << ", " << ans[1];
}