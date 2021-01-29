#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int KillTheMonster(int hp, int k, vector<int>& dmg)
{
    priority_queue<int, vector<int>> kills;
    for (int i=0; i<dmg.size(); i++)
    {
        if (dmg[i] <= 0)
        {
            hp -= dmg[i];
            continue;
        }

        hp -= dmg[i];
        kills.push(dmg[i]);

        while (hp <= 0 && k > 0 && !kills.empty())
        {
            hp += kills.top();
            kills.pop();
            k--;
        }
        if (hp < 0)
            return i;
        if (hp == 0)
            return i+1; 
    }
    return dmg.size();
}

int main()
{
    vector<int> damage = {-3, 2, 3, -2, 8, 8, 6, 4, 3, 3};
    int X = 10;
    int K = 2;
    cout << KillTheMonster(X, K, damage) << "\n";
    return 0;
}