#include <bits/stdc++.h>
using namespace std;

class StockSpanner {
private:
    stack<pair<int, int>> st; 

public:
    StockSpanner() {}

    int next(int price) {
        int span = 1; 
        while (!st.empty() && st.top().first <= price) {
            span += st.top().second;
            st.pop();
        }
        st.push({price, span});
        return span;
    }
};

int main() {
    StockSpanner* obj = new StockSpanner();

    vector<int> prices = {100, 80, 60, 70, 60, 75, 85};
    cout << "Stock span results:" << endl;
    for (int p : prices) {
        cout << "Price: " << p << " -> Span: " << obj->next(p) << endl;
    }

    delete obj;
    return 0;
}