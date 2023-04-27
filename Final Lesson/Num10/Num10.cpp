

#include <iostream>
#include <deque>
using namespace std;

int main()
{
	deque<int> dq;
	double avg = 0.0;
	for (int i = 0; i < 10; i++) {
		dq.push_back(rand() % 101);
		avg += dq[i];
	}
	avg /= dq.size();
	cout << avg << endl;
 
}

