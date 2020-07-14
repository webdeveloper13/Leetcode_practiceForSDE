class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(),coins.end());
        int size = coins.size();
        int *array = new int[amount+1];
        array[0]=0;
        int j;
        for(int i=1;i<=amount;++i){
            array[i]=amount+1;                                          //To initialize all values in array to amount+1
        }
        for(int i=1;i<=amount;++i){
            j = 0;
            while(j<size && coins[j]<=i){
                if(array[i]==1) break;
                array[i] = mini(1+array[i-coins[j]],array[i]);          //Calling out min function rather than std::min reduces execution time, do try it!
                ++j;
            }
        }
        return array[amount]<=amount?array[amount]:-1;
    }
private:
    int mini(int a, int b){
      return a<b?a:b;
    }
};