
#include <iostream>
#include <string.h>
#include <sstream>
#include <vector>
#include <set>
#include <math.h>
#include <map>
#include <tuple>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

enum TYPE
{
    Absent,
    Late,
    Leaveearly,
    Present
};

TYPE GetType(string &str)
{
    TYPE result = Absent;
    if (str.compare("absent") == 0)
        result = Absent;
    else if (str.compare("late") == 0)
        result = Late;
    else if (str.compare("leaveearly") == 0)
        result = Leaveearly;
    else if (str.compare("present") == 0)
        result = Present;

    return result;
}

bool IsAbsentOK(vector<TYPE> &work)
{
    int count = 0;
    for (auto iter = work.begin(); iter != work.end(); ++iter)
    {
        if ((*iter) == Absent) ++count;
    }
    return count <= 1;
}

bool IsLateEarlyOK(vector<TYPE> &work)
{
    bool isLate = false;
    bool result = true;
    for (auto iter = work.begin(); iter != work.end(); ++iter)
    {
        if ((*iter) == Late || (*iter) == Leaveearly)
        {
            if (isLate)
            {
                result = false;
                break;
            }
            isLate = true;
        }
        else
        {
            isLate = false;
        }
    }
    return result;
}
bool Is7DayOK(vector<TYPE> &work)
{
    bool result = true;
    map<int, int> indexCount;
    int count = 0;
    for (int i = 0; i < work.size(); ++i)
    {
        if (work[i] == Late || work[i] == Leaveearly || work[i] == Absent)
        {
            ++count;
            indexCount[count] = i;
        }
    }

    for (int i = 1; i < count - 2; ++i)
    {
        if (indexCount.find(i + 2) != indexCount.end() && indexCount[i + 2] - indexCount[i] < 7)
        {
            result = false;
            break;
        }
    }
    return result;
}

int main()
{
    int n = 0;
    cin >> n ;
    vector<vector<TYPE>> works;
    works.resize(n);

    string buf, tmp;
    int i = 0;
    while(getline(cin, buf) && i < n)
    {
        if (!buf.empty())
        {
            stringstream s(buf);
            while (getline(s, tmp, ' '))
            {
                if (!tmp.empty())
                {
                    works[i].push_back(GetType(tmp));
                }
            }
            ++i;
        }
        
    }

    for (auto iter = works.begin(); iter != works.end(); ++iter)
    {
        bool isGood = IsAbsentOK(*iter) && IsLateEarlyOK(*iter) && Is7DayOK(*iter);

        if (isGood)
            cout << "true" << " ";
        else
            cout << "false" << " ";

    }
    cout << endl;

    system("pause");
}