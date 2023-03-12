#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    
    cin >> str;
    
    int cnt = 0;
    
    for(int i =0 ; i < str.length(); i++){
        if(str[i] == '('){
            cnt++;
        }
        else if(str[i] == ')'){
            cnt--;
        }
        else {
            cout << cnt;
            return 0;
        }
    }
    
    return 0;
}
