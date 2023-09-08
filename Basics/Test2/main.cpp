#include <bits/stdc++.h>

using namespace std;

int main()
{
    int test;
    cin >> test;
    for(int t = 0; t < test; ++t){
        int n;
        cin >> n;
        string c;
        cin >> c;
        vector<int> w;
        w.push_back(-1);
        for(int i = 0; i < n; ++i){
            if(c[i] == 'W'){
                w.push_back(i);
            }
        }
        w.push_back(n);
        int p0;
        p0 = w.size();
        bool ans = true;
        for(int i = 0; i < p0 - 1; ++i){
                int r = 0, b = 0;
            if(w[i+1] - w[i] == 1){
                continue;
            }
            for(int y = w[i] + 1; y < w[i + 1]; ++y){
                if(c[y] == 'R'){
                    ++r;
                }
                if(c[y] == 'B'){
                    ++b;
                }
            }
            if(r == 0 || b == 0){ans = false;}
        }
        if(ans == true){cout << "YES";}else{cout << "NO";}
        cout << endl;
    }
}