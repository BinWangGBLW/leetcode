#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

/* implement a file replace */
class Solution{
public:
        string replace_str(string &s, string &nat, string &rep) {
                while (true) {
                        int pos = s.find(nat);
                        if (pos == (int) string::npos) break;
                        s.replace(pos, (int) nat.size(), rep);
                }
                return s;
        }
};

int main (int argc, char ** argv) {
        if (argc != 4) {
                cout <<"Invalid!" << endl;
                exit(0);
        }
       ifstream s(argv[1]);
        if (!s) {
                cout << "Does not exit" << endl;
                exit(1);
        }
        string nat = argv[2];
        string rep = argv[3];
        Solution b;
        vector <string> in;
        string out;
        while (getline(s, out)) {
                out = b.replace_str(out, nat, rep);
                in.push_back(out);
        }
        ofstream r(argv[1]);
        for (int i = 0 ; i < (int)in.size(); ++i) {
                r <<  in[i] + '\n';
        }
        return 0;
}
