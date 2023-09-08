#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int words;
    cin >> words;
    map<string, int> words_cnt;
    for (int word = 0; word < words; ++word)
    {
        string w;
        cin >> w;
        map<string, int>::iterator it;
        it = words_cnt.find(w);
        if (it == words_cnt.end())
        {
            words_cnt[w] = 0;
        }
        else
        {
            ++words_cnt[w];
        }
    }

    vector<pair<string, int>> vec(words_cnt.begin(), words_cnt.end());
    sort(vec.begin(), vec.end(), [](const pair<string, int> &l, const pair<string, int> &r)
            {
                if (l.second != r.second) {
                    return l.second < r.second;
                }

                return l.first < r.first;
            });
    reverse(vec.begin(), vec.end());
    for (auto const &pair : vec)
     {
        std::cout << pair.first << std::endl;
    }
}
