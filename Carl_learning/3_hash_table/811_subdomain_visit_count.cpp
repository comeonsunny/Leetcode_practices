// 811. Subdomain Visit Count
/*
    A website domain like "discuss.leetcode.com" consists of various subdomains. At the top level, we have "com", at the next level, we have 
    "leetcode.com", and at the lowest level, "discuss.leetcode.com".
    When we visit a domain like "discuss.leetcode.com", we will also visit the parent domains "leetcode.com" and "com" implicitly.
    A count-paired domain is a domain that has one of the two formats "rep d1.d2.d3" or "rep d1.d2" where rep is the number of 
    visits to the domain and d1.d2.d3 is the domain itself.
    For example, "9001 discuss.leetcode.com" is a count-paired domain that indicates that discuss.leetcode.com was visited 9001 times.
    Given an array of count-paired domains cpdomains, return an array of the count-paired domains of each subdomain in the input.
    You may return the answer in any order. 
    Example 1:
    Input: cpdomains = ["9001 discuss.leetcode.com"]
    Output: ["9001 discuss.leetcode.com","9001 leetcode.com","9001 com"]
    Explanation: We only have one website domain: "discuss.leetcode.com". 
    As discussed above, the subdomain "leetcode.com" and "com" will also be visited. So they will all be visited 9001 times.
*/
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> m;
        for (auto& cpdomain : cpdomains) {
            int i_space = cpdomain.find(' ');
            int count = stoi(cpdomain.substr(0, i_space));
            string domain = cpdomain.substr(i_space + 1);
            for (int i = 0; i < domain.size(); ++i) {
                if (domain[i] == '.') {
                    m[domain.substr(i + 1)] += count;
                }
            }
            m[domain] += count;
        }
        vector<string> res;
        for (auto& [domain, count] : m) {  // c++ 17 feature
            res.push_back(to_string(count) + " " + domain);
        }
        return res;
    }
};
int main()
{
    Solution sol;
    vector<string> cpdomains = {"9001 discuss.leetcode.com"};
    vector<string> res = sol.subdomainVisits(cpdomains);
    for (auto& s : res) {
        cout << s << endl;
    }
    return 0;
}