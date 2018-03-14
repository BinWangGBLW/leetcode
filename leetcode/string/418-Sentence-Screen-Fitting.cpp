#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        string s;
        for (const auto &word : sentence) {
            s += word;
            s += " ";
        }
        int count = 0, n = s.size();
        for (int i = 0; i < rows; ++i) {
            count += cols;
            if (s[count % n] == ' ') count++;
            else {
                while (s[(count - 1) % n] != ' ' && count > 0)
                    --count;
            }
        }
        return count / n;
    }
};

int main() {
    int rows = 4, cols = 5;
    vector <string> sentence = {"I", "had", "apple", "pie"};
    Solution s;
    cout << "The times of sentence is " <<s.wordsTyping(sentence, rows, cols) << endl;
    return 0;
}
