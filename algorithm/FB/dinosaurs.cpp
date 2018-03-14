#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <unordered_map>
#include <queue>
#include <cmath>
using namespace std;

/*
dinosaurs question

You will be supplied with two data files in CSV format. The first file contains
statistics about various dinosaurs. The second file contains additional data.

Given the following formula,

speed = ((STRIDE_LENGTH / LEG_LENGTH) - 1) * SQRT(LEG_LENGTH * g)
Where g = 9.8 m/s^2 (gravitational constant)
(normal code)
Write a program to read in the data files from disk, it must then print the names
of only the bipedal dinosaurs from fastest to slowest. Do not print any other information.

$ cat dataset1.csv
NAME,LEG_LENGTH,DIET
Hadrosaurus,1.2,herbivore
Struthiomimus,0.92,omnivore
Velociraptor,1.0,carnivore
Triceratops,0.87,herbivore
Euoplocephalus,1.6,herbivore
Stegosaurus,1.40,herbivore
Tyrannosaurus Rex,2.5,carnivore

$ cat dataset2.csv
NAME,STRIDE_LENGTH,STANCE
Euoplocephalus,1.87,quadrupedal
Stegosaurus,1.90,quadrupedal
Tyrannosaurus Rex,5.76,bipedal
Hadrosaurus,1.4,bipedal
Deinonychus,1.21,bipedal
Struthiomimus,1.34,bipedal
Velociraptor,2.72,bipedal 
*/
class dinosaurs {
public:
  
/*** calculate speed  
speed = ((STRIDE_LENGTH / LEG_LENGTH) - 1) * SQRT(LEG_LENGTH * g)***/
  
  float speed(float leg_length, float stride_length) {
    return (stride_length / leg_length - 1) * sqrt(leg_length * 9.8);
  }
  
  vector <string> read_line(string s) {
    vector <string> m;
    s.push_back(',');
    string t;
    for(int i = 0; i < (int)s.size(); ++i) {
      if (s[i] == ',') {
        m.push_back(t);
        t.clear();
      }
      else t += s[i];
    }
    return m;
  }
  vector <string> calculate(vector <string> file1, vector <string> file2) {
    map <string, float> m2;
    for (int i = 0; i < (int)file2.size(); ++i) {
      vector <string> tmp = read_line(file2[i]);
      if (tmp[2] == "bipedal") m2[tmp[0]] = stof(tmp[1]);
    }
    map <string, float> m;
    for (int i = 0; i < (int)file1.size(); ++i) {
      vector <string> tmp = read_line(file1[i]);
      if (m2.count(tmp[0])) m[tmp[0]] = speed(m2[tmp[0]], stof(tmp[1]));
    }
    priority_queue <pair <float, string>> q;
    for (auto it : m) {
      q.push({it.second, it.first});
    }
    vector <string> res;
    while (!q.empty()) {
      auto t = q.top(); q.pop();
      res.push_back(t.second);
    }
    return res;
  }
};
int main () {
  vector <string> file1 = { "NAME,LEG_LENGTH,DIET",
                  "Hadrosaurus,1.2,herbivore",
                  "Struthiomimus,0.92,omnivore",
                  "Velociraptor,1.0,carnivore",
                  "Triceratops,0.87,herbivore",
                  "Euoplocephalus,1.6,herbivore",
                  "Stegosaurus,1.40,herbivore",
                  "Tyrannosaurus Rex,2.5,carnivore"};
  vector <string> file2 = {"NAME,STRIDE_LENGTH,STANCE",
                  "Euoplocephalus,1.87,quadrupedal",
                  "Stegosaurus,1.90,quadrupedal",
                  "Tyrannosaurus Rex,5.76,bipedal",
                  "Hadrosaurus,1.4,bipedal",
                  "Deinonychus,1.21,bipedal",
                  "Struthiomimus,1.34,bipedal",
                  "Velociraptor,2.72,bipedal"  
                 };
  dinosaurs d;
  vector <string> res = d.calculate(file1, file2);
  cout <<"The names of only the bipedal dinosaurs from fastest to slowest is:" <<endl;
  for (auto it : res)
    cout << it << endl;
  return 0;
}
