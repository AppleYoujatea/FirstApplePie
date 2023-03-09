#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#include <string>

#define INF 1e9

using namespace std;

int score[9] = {10, 8, 6, 5, 4, 3, 2, 1, 0};

int main(){
    int r_score = 0;
    int b_score = 0;
    
    vector<pair<string, int>> record;
    
    for(int i = 0; i < 8; i++){
        
        string str;
        
        cin >> str;
        
        char team;
        
        cin >> team;
        
        //B가 1, R이 0
        record.push_back({str, team == 'B'? 1: 0});
        
    }
    
    sort(record.begin(), record.end());
    
    for(int i = 0; i <  8; i++){
        
        if(record[i].second == 1){
            b_score += score[i];
            
        }
        else{
            r_score += score[i];
        }
    }
    
    if( r_score > b_score){
        cout << "Red";
    }
    else{
        cout <<"Blue";
    }
    
}
