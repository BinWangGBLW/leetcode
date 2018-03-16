#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

/*
Given two sentences words1, words2 (each represented as an array of strings), and a list of similar word pairs pairs, determine if two sentences are similar.

For example, words1 = ["great", "acting", "skills"] and words2 = ["fine", "drama", "talent"] are similar, if the similar word pairs are pairs = [["great", "good"], ["fine", "good"], ["acting","drama"], ["skills","talent"]].

Note that the similarity relation is transitive. For example, if "great" and "good" are similar, and "fine" and "good" are similar, then "great" and "fine" are similar.

Similarity is also symmetric. For example, "great" and "fine" being similar is the same as "fine" and "great" being similar.

Also, a word is always similar with itself. For example, the sentences words1 = ["great"], words2 = ["great"], pairs = [] are similar, even though there are no specified similar word pairs.

Finally, sentences can only be similar if they have the same number of words. So a sentence like words1 = ["great"] can never be similar to words2 = ["doubleplus","good"]. 
*/

using namespace std;

class Solution {
public:
    bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2, vector<pair<string, string>> pairs) {
        if (words1.size() != words2.size()) return false;
        g_.clear();
        for (const auto & p : pairs) {
            g_[p.first].insert(p.second);
            g_[p.second].insert(p.first);
        }
        unordered_set <string> visited;
        for (int i = 0; i < (int)words1.size(); ++i) {
            visited.clear();
            if (!dfs(words1[i], words2[i], visited)) return false;
        }
        return true;
    }
private:
    unordered_map <string, unordered_set <string>> g_;
    bool dfs(const string & src, const string & dst, unordered_set <string> & visited) {
        if (src == dst) return true;
        visited.insert(src);
        for (const auto next : g_[src]) {
            if (visited.count(next)) continue;
            if (dfs(next, dst, visited)) return true;
        }
        return false;
    }
};

int main () {  
  Solution s;
  vector <string> words1 = {"great", "acting", "skills"};
  vector <string> words2 = {"fine","drama","talent"};
  vector <pair <string, string>> pairs = {{"great", "good"}, {"fine", "good"}, {"acting","drama"}, {"skills","talent"}}; 
  if (s.areSentencesSimilarTwo(words1, words2, pairs)) cout << "true";
  else cout << "false";
  cout << endl;
}



