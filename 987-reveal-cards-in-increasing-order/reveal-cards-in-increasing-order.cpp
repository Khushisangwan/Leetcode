class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(),deck.end());
        queue<int>q;
        int n=deck.size();
        vector<int>result(n);
        for(int i=0;i<n;i++){
            q.push(i);
        }
        for(int e:deck){
            int i=q.front();
            q.pop();
            result[i]=e;
            if(!q.empty()){
                q.push(q.front());
                q.pop();
            }
        }
        return result;
    }
};