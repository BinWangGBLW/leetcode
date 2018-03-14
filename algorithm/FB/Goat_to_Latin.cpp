#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <sstream>
#include <unordered_set>

/*
Goat to Latin  is a made-up language based off of English, sort of like Pig Latin.
(normal code)
The rules of Goat Latin are as follows:
1. If a word begins with a consonant (i.e. not a vowel), remove the first
    letter and append it to the end, then add 'ma'.
    For example, the word 'goat' becomes 'oatgma'.
2. If a word begins with a vowel (a, e, i, o, or u), append 'ma' to the end of the word.
    For example, the word 'I' becomes 'Ima'.
3. Add one letter "a" to the end of each word per its word index in the
    sentence, starting with 1. That is, the first word gets "a" added to the
    end, the second word gets "aa" added to the end, the third word in the
    sentence gets "aaa" added to the end, and so on.

Write a function that, given a string of words making up one sentence, returns
that sentence in Goat Latin. For example:

  string_to_goat_latin('I speak Goat Latin')

would return: 'Imaa peaksmaaa oatGmaaaa atinLmaaaaa'
*/

using namespace std;
class Solution {
public:
        vector <string> str_to_vec(string &s) {
                vector <string> res;
                istringstream in(s);
                string word;
                while (in >> word) {
                        res.push_back(word);
                }
                return res;
        }
        string string_to_goat_latin(string s) {
                vector <string> res = str_to_vec(s);
                for (int i = 0; i < (int) res.size(); ++i) {
                        if(ref.count(res[i][0])) res[i] += "ma";
                        else res[i] = res[i].substr(1) + res[i].substr(0, 1) + "ma";
                        string b;
                        for (int j = 0; j <= i; ++j) {
                                b += 'a';
                        }
                        res[i] += b;
                }
                string ans;
                for (int i = 0; i < (int)res.size(); ++i) {
                        ans += res[i] + ' ';
                }
                ans.pop_back();
                return ans;
        }
private:
        const unordered_set <char> ref = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
};

int main() {
        string s = "I speak Goat Latin";
        Solution m;
        cout << "The coverted Latin is:" << endl;
        cout << m.string_to_goat_latin(s) << endl;
        return 0;
}
