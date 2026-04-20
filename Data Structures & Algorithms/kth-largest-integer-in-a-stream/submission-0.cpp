class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> pq;
    int k;
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (int num : nums) {
            this->pq.push(num);
            if (this->pq.size() > this->k) {
                this->pq.pop();
            }
        }
    }
    
    int add(int val) {
        this->pq.push(val);
        if (this->pq.size() > this->k) {
            this->pq.pop();
        }
        return this->pq.top();
    }
};
