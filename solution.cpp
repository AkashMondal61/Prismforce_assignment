#include <iostream>
#include <vector>
using namespace std;

class ChakravyuhaEscape
{
private:
    int initial_energy;
    int num_circles;
    int skips;
    int recharges;
    vector<int> enemies;
    // 5D DP vector to store results
    vector<vector<vector<vector<vector<int> > > > > dp;

    bool canEscape(int current_circle, int cur_energy, int skips_left, int recharges_left, bool prev_attacked)
    {
        // Base Case: If Abhimanyu has crossed all circles
        if (current_circle == num_circles)
        {
            return true;
        }
        // Check if already computed
        if (dp[current_circle][cur_energy][skips_left][recharges_left][prev_attacked ? 1 : 0] != -1)
        {
            return dp[current_circle][cur_energy][skips_left][recharges_left][prev_attacked ? 1 : 0];
        }
        // If energy is insufficient and no skips or recharges are available
        if (cur_energy < enemies[current_circle] && skips_left == 0 && recharges_left == 0)
        {
            return false;
        }

        bool result = false;
        int curPowerNeed = enemies[current_circle];
        // Special cases for enemies in 4th and 8th circles (index 3 and 7)
        if (current_circle == 3 || current_circle == 7)
        {
            if(prev_attacked)
            curPowerNeed+= enemies[current_circle-1]/2;
        }

        // Battle
        if ( cur_energy >=curPowerNeed)
        {
            result = canEscape(current_circle + 1, cur_energy - curPowerNeed, skips_left, recharges_left, true);
        }

        // Skip if you can
        if (skips_left > 0)
        {
            result = result || canEscape(current_circle + 1, cur_energy, skips_left - 1, recharges_left, false);
        }

        // Recharge
        if (recharges_left > 0)
        {
            result = result || canEscape(current_circle, initial_energy, skips_left, recharges_left - 1, prev_attacked);
        }

        return dp[current_circle][cur_energy][skips_left][recharges_left][prev_attacked ? 1 : 0] = result;
    }

public:
    ChakravyuhaEscape(int energy, int skips_count, int recharges_count, const vector<int>& enemies_list) {
        // Initialize the member variables with the values passed to the constructor
        initial_energy = energy;          // Set the initial energy
        enemies = enemies_list;           // Copy the list of enemy strengths into the enemies variable
        num_circles = enemies.size();     // Calculate and store the total number of circles (enemies)
        skips =min( skips_count,num_circles);              // Set the number of skips allowed
        recharges =min(num_circles, recharges_count);      // Set the number of recharges allowed
            dp = vector<vector<vector<vector<vector<int> > > > >(
            num_circles,
            vector<vector<vector<vector<int> > > >(
                initial_energy + 1,
                vector<vector<vector<int> > >(
                    skips + 1,
                    vector<vector<int> >(
                        recharges + 1,
                        vector<int>(2, -1)))));
    }


    bool canAbhimanyuEscape()
    {
        return canEscape(0, initial_energy, skips, recharges, false);
    }
};

int main()
{
    int p, a, b;
    int num_circles = 11; // Number of circles (always 11 in this problem)

    cin >> p;
    cin >> a;
    cin >> b;

    vector<int> k(num_circles);
    for (int i = 0; i < num_circles; i++)
    {
        cin >> k[i];
    }

    ChakravyuhaEscape chakravyuha(p, a, b, k);
    if (chakravyuha.canAbhimanyuEscape())
    {
        cout << "Abhimanyu can cross the Chakravyuha." << endl;
    }
    else
    {
        cout << "Abhimanyu cannot cross the Chakravyuha." << endl;
    }

    return 0;
}


