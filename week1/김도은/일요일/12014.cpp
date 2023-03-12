#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> cache;

int main() {
    
    
    int n, m, testcase = 1;
    
    cin >> m;

    while (cin >> n) {
        
        cache.clear();
        
        cin >> m;
        
        for (int i = 1; i <= n; i++) {
            
            int cost;
            
            cin >> cost;
            
            if (cache.empty() || cache.back() < cost){
                cache.push_back(cost);
            }
            else {
                int idx = lower_bound(cache.begin(), cache.end(), cost) - cache.begin();
                cache[idx] = cost;
            }
        }
        
        if(cache.size() >= m){
            cout << "Case #" << testcase << "\n"<< 1 << "\n";
        }
        else{
            cout << "Case #" << testcase << "\n"<< 0 << "\n";
        }
        
        testcase++;
    }
    
}
