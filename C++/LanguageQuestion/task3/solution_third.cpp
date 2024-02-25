#include <iostream>
#include <vector>
using namespace std;

class LongestIncreasingSubsequence {
public:
    static pair<int, vector<int>> findLongestIncreasingSubsequence(const vector<int>& nums) {
        int maxLength = 0;
        vector<int> longestSubsequence;
        int n = nums.size();
        vector<int> barrel;
        for(int i = 0;i < n;i++){
            barrel.push_back(dg(i,nums));
        }
        int temp = 0;
        for(int i = 0;i < n;i++){
            if(temp < barrel[i]){
                temp = i;
                maxLength = barrel[i];
            }
        }
        vector<int> Subsequence;
        for(int i = 0;i < temp;i++){
            Subsequence.clear();
            int fronter = nums[i];
            Subsequence.push_back(fronter);
            for(int j = i + 1;j < temp;j++){
                int latter = nums[j];
                if(fronter < latter){
                    fronter = latter;
                    Subsequence.push_back(fronter);
                }
            }
            if(Subsequence.size() == barrel[temp]-1){
                longestSubsequence = Subsequence;
            }
        }
        return { maxLength, longestSubsequence };
    }
    static int dg(int i,const vector<int>& nums){
        int cnt = 0;
        for(int j = 0 ;j < i;j++){
            if(nums[j] < nums[i]){
                cnt = max(cnt,dg(j,nums));
            }
        }
        return cnt + 1;
    }
};

int main() {
    vector<int> input = {10, 22, 9, 33, 21, 50, 41, 60, 80};

    auto result = LongestIncreasingSubsequence::findLongestIncreasingSubsequence(input);

    cout << "Longest Increasing Subsequence: ";
    for (int num : result.second) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Length of Longest Increasing Subsequence: " << result.first << endl;

    return 0;
}
