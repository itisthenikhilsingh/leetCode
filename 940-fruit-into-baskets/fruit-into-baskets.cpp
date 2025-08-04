class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> basket;
    int left = 0;
    int maxPicked = 0;

    for (int right = 0; right < fruits.size(); ++right) {
        basket[fruits[right]]++;

        while (basket.size() > 2) {
            int leftFruit = fruits[left];
            basket[leftFruit]--;
            if (basket[leftFruit] == 0) {
                basket.erase(leftFruit);
            }
            left++;
        }
        maxPicked = max(maxPicked, right - left + 1);
    }

    return maxPicked;
        
    }
};