#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for (int a : asteroids) {
            bool destroyed = false;
            while (!st.empty() && a < 0 && st.top() > 0) {
                if (abs(a) > st.top()) {
                    st.pop();
                } else if (abs(a) == st.top()) {
                    st.pop();
                    destroyed = true;
                    break;
                } else {
                    destroyed = true;
                    break;
                }
            }
            if (!destroyed) {
                st.push(a);
            }
        }

        vector<int> result(st.size());
        for (int i = st.size() - 1; i >= 0; --i) {
            result[i] = st.top();
            st.pop();
        }
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> asteroids = {5, 10, -5};
    vector<int> result = sol.asteroidCollision(asteroids);

    cout << "Resulting asteroids after collisions: ";
    for (int a : result) {
        cout << a << " ";
    }
    cout << endl;

    vector<int> asteroids2 = {8, -8};
    result = sol.asteroidCollision(asteroids2);

    cout << "Resulting asteroids after collisions: ";
    for (int a : result) {
        cout << a << " ";
    }
    cout << endl;

    return 0;
}
