class FreqStack {
public:
    int max_freq = 0;
    map<int,int> freq;
    map<int,stack<int>> freq2elem;
    
    FreqStack() {
    }
    
    void push(int x) {
        freq[x]++;
        max_freq = max(max_freq, freq[x]);
        freq2elem[freq[x]].push(x);
    }
    
    int pop() {
        int e = freq2elem[max_freq].top();
        freq2elem[max_freq].pop();
        freq[e]--;
        if (freq2elem[max_freq].empty())
            max_freq--;
        return e;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack obj = new FreqStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 */
