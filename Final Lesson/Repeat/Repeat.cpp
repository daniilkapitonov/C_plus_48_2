

#include <iostream>
#include <forward_list>

using namespace std;

int main()
{
    forward_list<int> num{ 1,2,3,4 };
    cout << num.front() << endl;
    for (int n : num) {
        cout << n << endl;
    }
    auto it = num.begin();
    it++;
    num.insert_after(it, 23);
    for (int n : num) {
        cout << n << endl;
    }
}

