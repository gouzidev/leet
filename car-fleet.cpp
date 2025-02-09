
#include "helper.cpp"

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed)
    {
        int n_fleets = position.size();
        float time_reach_target;
        float remind_dist;
        float fastest;
        set <pair <int, int>, greater<>> cars;

        for (int i = 0; i < position.size(); i++)
            cars.insert({position[i], speed[i]});
        set<pair <int, int>>::iterator it = cars.begin();
        remind_dist = target - it->first;
        fastest = remind_dist / it->second;; // 10 -> needs 1t
        it++;
        while (it != cars.end())
        {
            remind_dist = target - it->first;
            time_reach_target = remind_dist / it->second; // 8 -> 1t
            if (fastest >= time_reach_target)
                n_fleets--;
            else
                fastest = time_reach_target;
            it++;
        }
        return n_fleets;
    }
};

int main() {
    // Create test cases
    Solution solution;
    vector <int> positions = {1,4}; // {0, 3, 5, 8, 10}
    vector <int> speeds = {3,2}; //     {1, 3, 1, 4, 2 }
    int nfleets =  solution.carFleet(10, positions, speeds);
    cout << "nfleets -> " << nfleets << endl;
    return 0;
}
