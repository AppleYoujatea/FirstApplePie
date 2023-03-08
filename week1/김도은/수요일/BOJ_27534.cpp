#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(){
    int test_case;
    cin >> test_case;
    for(int t = 0; t < test_case; t++){
        int n;
        cin >> n;
        string str;
        cin >> str;
        int price = 0;
        
        if(n == 1 || n == 3){
            price = -1;
            cout << price << "\n";
            continue;
        }
        
        int start_zero = -1;
        int start_one = -1;
        int end_zero = -1;
        int end_one = -1;
        
        for(int i = 0; i < n; i++){
            if(str[i] == '0'){if(start_zero == -1){
                    start_zero = i;
                }else{
                    end_zero = i;
                }
            }
            else{if(start_one == -1){start_one = i;}
                else{end_one = i;}
            }
        }
        if((end_zero == -1 && start_zero == -1) || (end_one == -1 && start_one == -1)){
            if(n== 2){
                cout << 1 << "\n";
            }else{
                cout << 2 << "\n";
            }continue;
        }
        
        if(end_zero == -1){
            end_zero = start_zero;
        }
        
        if(end_one == -1){
            end_one = start_one;
        }
        
        int zero_dis = end_zero - start_zero;
        int one_dis = end_one - start_one;
        
        if(zero_dis == one_dis){
            cout << price << "\n";
            continue;
        }
        
        //2인 경우
        if(zero_dis < one_dis){
            if(start_zero + one_dis-1 == end_one && end_zero - one_dis+1 == start_one){
                cout << 2 << "\n";
                continue;
            }
            
            if(end_zero < start_one){
                if(start_zero + one_dis == start_one){
                    cout << 2 << "\n";
                    continue;
                }
            }
            else{
                if(end_zero - one_dis == end_one){
                    cout << 2 << "\n";
                    continue;
                }
            }
            
            if(start_zero + one_dis-1 >= n && end_zero - one_dis+1 < 0){
                cout << 2 << "\n";
                continue;
            }
            
        }
        else{
            if(start_one + zero_dis-1 == end_zero && end_one - zero_dis+1 == start_zero){
                cout << 2 << "\n";
                continue;
            }
            
            if(end_one < start_zero){
                if(start_one + zero_dis == start_zero){
                    cout << 2 << "\n";
                    continue;
                }
            }
            else{
                if(end_one - zero_dis == end_zero){
                    cout << 2 << "\n";
                    continue;
                }
            }
            
            if(start_one + zero_dis-1 >= n && end_one - zero_dis+1 < 0){
                cout << 2 << "\n";
                continue;
            }
        }
        
      
        price = 1;
        cout << price<<"\n";
    }
}
