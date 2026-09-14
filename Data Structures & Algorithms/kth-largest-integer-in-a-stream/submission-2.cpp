class KthLargest {
private: 
    int k;
    vector<int> nums;
    priority_queue<int> pq;
public:
    KthLargest(int k, vector<int>& nums) {
        this->k=k;
        this->nums=nums;
        for (int n : nums) {
            pq.push(n);
        }
    }
    
    int add(int val) {
        printf("%d\n",val);
        pq.push(val);
        if(pq.size()<k){
            priority_queue<int> x=pq;
            while(x.size()>1){
                x.pop();
            }
            return x.top();
        }
        priority_queue<int> x=pq;
        int c=0;
        while(!x.empty() && c!=this->k-1){
            x.pop();
            c++;
        }
        printf("%d\n",x.top());
        return x.top();
    }
};
