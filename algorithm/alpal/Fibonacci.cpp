#include <stdio.h>
#include <iostream>

using namespace std;

class Solution{
public:
	int fibonacci(int i)  
	{  
    	if (i <= 2)  
        	return i == 0 ? 0 : 1;  
    	return fibonacci(i - 1) + fibonacci(i - 2);  
	} 
};
   
int main(void)  
{  
    int i;  
  	Solution s;
    for (i = 1; i <= 12; i++)  
        printf("经过%d次之后的数量：%d\n", i, s.fibonacci(i));   
    cout << endl;  
    return 0;  
} 

