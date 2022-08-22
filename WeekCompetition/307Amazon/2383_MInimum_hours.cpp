// Minimum Hours of Training to Win a Competition
/*
    You are entering a competition, and are given two positive integers initialEnergy and initialExperience denoting
    your initial energy and initial experience respectively.
    You are also given two 0-indexed integer arrays energy and experience, both of length n.
    You will face n opponents in order. The energy and experience of the ith opponent is denoted by energy[i] 
    and experience[i], respectively. When you face an opponent, you need to have both strictly greater experience and 
    energy to defeat them and move to the next opponent if available. 
    Before starting the competition, you can train for some number of hours. After each hour of training, you can 
    either choose to increase your initial experience by one, or increase your initial energy by one. 
    Return the minimum number of training hours required to defeat all n opponents.
*/
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
        int res; // minimum number of training hours
        int res_energy, res_experience = 0;
        int consumeEnergy = 0;
        for (auto e : energy) consumeEnergy += e;
        res_energy = initialEnergy > consumeEnergy ? 0 : consumeEnergy - initialEnergy + 1;
        int curExperience = initialExperience, diffExperience = 0;
        for (auto e : experience) {
            diffExperience = curExperience > e ? 0 : e - curExperience + 1;
            res_experience += diffExperience;
            curExperience += e + diffExperience;
        }
        res = res_energy + res_experience;
        return res;
    }
};
int main()
{
    Solution s;
    int initialEnergy = 5, initialExperience = 3;
    vector<int> energy  = {1, 4, 3, 2};
    vector<int> experience = {2, 6, 3, 1};
    cout << s.minNumberOfHours(initialEnergy, initialExperience, energy, experience) << endl;
    return 0;
}