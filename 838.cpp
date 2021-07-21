const int maxn = 1e5 + 5;
class Solution
{
    int f[maxn];

public:
    string pushDominoes(string dominoes)
    {
        int n = dominoes.size();
        int force = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            if (dominoes[i] == 'L') force = n;
            else if (dominoes[i] == 'R') force = 0;
            else force = max(0, force - 1);
            f[i] += force;
        }
        for (int i = 0; i < n; i++)
        {
            if (dominoes[i] == 'R') force = n;
            else if (dominoes[i] == 'L') force = 0;
            else force = max(0, force - 1);
            f[i] -= force;
        }
        for (int i = 0; i < n; i++)
        {
            if (f[i] > 0) dominoes[i] = 'L';
            else if (f[i] < 0) dominoes[i] = 'R';
        }
        return dominoes;
    }
};