class Solution {
public:
    int gap[3], id[3]={0, 1, 2};
    int jump_or_shift(int i, vector<int>& startTime, vector<int>& endTime) {
        int busy=endTime[i]-startTime[i];
        bool pass=0;
        [[unroll]]
        for (int k=0; k<3; k++) {
            if (gap[k]>= busy && (id[k]!= i && id[k]!= i+1)) {
                pass=1;
                break;
            }
        }
        const int end=(i==0)?0:endTime[i-1];
        const int jump=startTime[i+1]-end;
    //    cout<<"pass="<<pass<<" busy="<<busy<<" jump="<<jump<<" shift="<<jump-busy<<endl;
        if (pass) return jump;
        return jump-busy; // shift 
    }

    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) 
    {
        const int n = startTime.size();
        startTime.push_back(eventTime); // add dummy end
        gap[0]=startTime[0], gap[1]=startTime[1]-endTime[0], gap[2]=startTime[2]-endTime[1];
        // bubble sort for 3 
        if (gap[0]<gap[1]) swap(gap[0], gap[1]), swap(id[0], id[1]);
        if (gap[1]<gap[2]) swap(gap[1], gap[2]), swap(id[1], id[2]);
        if (gap[0]<gap[1]) swap(gap[0], gap[1]), swap(id[0], id[1]);

        for (int i=3; i<=n; i++) {
            int curr_gap = startTime[i]-endTime[i - 1];
            if (curr_gap >= gap[0]) {
                gap[2]=exchange(gap[1], gap[0]);
                gap[0]=curr_gap;
                id[2]=exchange(id[1], id[0]);
                id[0]=i;
            } 
            else if (curr_gap >= gap[1]) {
                gap[2]=exchange(gap[1], curr_gap);
                id[2]=exchange(id[1], i);
            } 
            else if (curr_gap > gap[2]) {
                gap[2]=curr_gap; id[2]=i;
            }
        }
    //    for (int i=0; i<3; i++)
    //        cout<<id[i]<<"-> gap="<<gap[i]<<endl;

        int ans=0;
        for (int i=0; i<n; i++) {
            ans = max(ans, jump_or_shift(i, startTime, endTime));
        }
        return ans;
    }
};