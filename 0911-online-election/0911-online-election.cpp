
class TopVotedCandidate {
public:
    vector<int> times;
    vector<int> leaders;

    TopVotedCandidate(vector<int>& persons, vector<int>& t) {

        times = t;

        unordered_map<int, int> mp;

        int leader = -1;
        int maxi = 0;

        for (int i = 0; i < persons.size(); i++) {

            mp[persons[i]]++;

            if (mp[persons[i]] >= maxi) {
                maxi = mp[persons[i]];
                leader = persons[i];
            }

            leaders.push_back(leader);
        }
    }

    int q(int t) {

        int i = upper_bound(times.begin(), times.end(), t) - times.begin();

        return leaders[i - 1];
    }
};
