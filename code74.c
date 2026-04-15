#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    unordered_map<string, int> votes;
    
    string name;
    for(int i = 0; i < n; i++) {
        cin >> name;
        votes[name]++;
    }
    
    string winner = "";
    int maxVotes = 0;
    
    for(auto it : votes) {
        string candidate = it.first;
        int count = it.second;
        
        if(count > maxVotes) {
            maxVotes = count;
            winner = candidate;
        }
        else if(count == maxVotes) {
            if(candidate < winner) {
                winner = candidate;
            }
        }
    }
    
    cout << winner << " " << maxVotes << endl;
    
    return 0;
}