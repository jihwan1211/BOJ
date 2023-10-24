#include <bits/stdc++.h>
using namespace std;

string t, str;
bool flag = true;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> str;
    for (int i = 0; i < str.size(); i++)
    {
        if (!t.size())
        {
            if (str[i] != 'p' && str[i] != 'k' && str[i] != 'c')
            {
                flag = false;
                break;
            }
            t.push_back(str[i]);
            continue;
        }
        else
        {
            if (t.size() == 1)
            {
                if ((t[0] == 'p' && str[i] == 'i') || (t[0] == 'k' && str[i] == 'a'))
                {
                    t = "";
                    continue;
                }
                else if (t[0] == 'c' && str[i] == 'h')
                {
                    t.push_back(str[i]);
                    continue;
                }
                else
                {
                    flag = false;
                    t = "";
                    break;
                }
            }
            else if (t.size() == 2)
            {
                if (str[i] == 'u')
                {
                    t = "";
                }
                else
                {
                    flag = false;
                    break;
                }
            }
        }
    }
    if (t.size())
    {
        flag = false;
    }

    if (flag)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}
