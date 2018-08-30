/*
 * The solution is based on the following observation:
 * - The 'event' when a booking starts and ends can be marked.
 * - And to be able to count the overlapping of bookings, one
 *   can mark a start of an event with +1, and the end with -1.
 * - If we add the values up to a time t, it will give as the number
 *   of booking interactions until that time t.
 *
 *   Complexity:
 *   - O(N) for each book() call, where N = total number of events.
 */
class MyCalendarThree {
public:
    map<int,int> d;
    MyCalendarThree() {
        d.clear();
    }

    int book(int start, int end) {
        d[start]++;
        d[end]--;

        int c=0;
        int ans = -1;
        for(auto& it : d) {
            c += it.second;
            ans = max(ans,c);
        }
        return ans;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree obj = new MyCalendarThree();
 * int param_1 = obj.book(start,end);
 */
