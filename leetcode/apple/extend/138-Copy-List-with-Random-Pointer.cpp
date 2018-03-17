/*
A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.
*/

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
#include <iostream>
#include <string>
#include <map>
#include <vector>
 
using namespace std;

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};
 
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        std::map <RandomListNode*, int> listmap;
        std::vector <RandomListNode *> listvector;
        RandomListNode *ptr = head;
        int i = 0;
        while(ptr) {
            listvector.push_back(new RandomListNode(ptr->label));
            listmap[ptr] = i;
            ptr = ptr->next;
            i++;
        }
        listvector.push_back(0);
        i = 0;
        ptr = head;
        while(ptr) {
            listvector[i]->next = listvector[i + 1];
            if(ptr->random) {
                int id = listmap[ptr->random];
                listvector[i]->random = listvector[id];
            }
            ptr = ptr->next;
            i++;
        }
        return listvector[0];
    }
    void print_list(RandomListNode *head) {
    	RandomListNode *ptr = head;
    	while (ptr) {
    		cout << ptr->label << "->next->";
    		ptr = ptr->next;
		}
		cout << "null" << endl;
		ptr = head;
		while (ptr) {
    		cout << ptr->label << "->random->";
    		ptr = ptr->random;
		}
		cout << "null" << endl;
	}
};

int main () {
	Solution ss;
	RandomListNode a(1);
	RandomListNode b(2);
	RandomListNode c(3);
	RandomListNode d(4);
	RandomListNode e(5);
	RandomListNode f(6);
	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = &e;
	e.next = &f;
	a.random = &e;
	e.random = &d;
	d.random = &c;
	c.random = &b;
	cout << "the native randomlist is : " << endl;
	ss.print_list(&a);
	RandomListNode *copy = ss.copyRandomList(&a);
	cout << "the deep copy randomlist is :" << endl;
	ss.print_list(copy);
	return 0;
}
