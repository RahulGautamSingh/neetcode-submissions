class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        // create a vector of pair <position, speed>
        // sort in ascending order based on position
        // init stack <int>
        // create new vector
        // store time taken = target - position / speed in it
        // int fleet = 0;
        // iterate -- computed time vector 
        // stack.push() for index len-1
        // for index >=0
        // if timetaken is less than stack top do nothing
        // if timetaken is greaterthanequalsto stack top fleet++ push that time to stack
     int n = position.size();
    vector<pair<int,int>> cars(n);
    for (int i = 0; i < n; i++) cars[i] = {position[i], speed[i]};
    sort(cars.begin(), cars.end());              // ascending by position

    stack<double> st;
    for (int i = n - 1; i >= 0; i--) {           // closest to target first
        double t = (double)(target - cars[i].first) / cars[i].second;
        if (st.empty() || t > st.top()) st.push(t);
    }
    return st.size();
    }
};
