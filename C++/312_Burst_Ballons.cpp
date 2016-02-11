class Solution {
public:
    int maxCoins(vector<int>& nums) {
        vector<int> newVec(nums);
        newVec.insert(newVec.begin(),1);
        newVec.push_back(1);
        int **T = (int**)malloc(sizeof(int*) * newVec.size());
        for (int i = 0; i < newVec.size();i++)
            T[i] = (int*)malloc(sizeof(int) * newVec.size());
        for (int i = 0; i < newVec.size(); i++) 
            for (int j = 0; j < newVec.size(); j++)
                T[i][j] = 0;
                
        for (int length = 2; length < newVec.size();length++) {
            for (int i = 0; i < newVec.size()-length;i++) {
                for (int k = i + 1; k < i+length;k++) {
                    int sum = T[i][k] + newVec[i]*newVec[k]*newVec[i+length] + T[k][i+length];
                    if (sum > T[i][i+length])
                        T[i][i+length] = sum;
                }
            }
        }
        return T[0][newVec.size() - 1];
    }
};