#include <iostream>
#include <queue>
#include <unordered_set>

using namespace std;

class SmallestInfiniteSet {
private:
    int next_smallest;
    priority_queue<int, vector<int>, greater<int>> min_heap;
    unordered_set<int> heap_elements;

public:
    SmallestInfiniteSet() {
        next_smallest = 1;
    }
    
    int popSmallest() {
        if (!min_heap.empty()) {
            int smallest = min_heap.top();
            min_heap.pop();
            heap_elements.erase(smallest);
            return smallest;
        } else {
            return next_smallest++;
        }
    }
    
    void addBack(int num) {
        if (num < next_smallest && heap_elements.find(num) == heap_elements.end()) {
            min_heap.push(num);
            heap_elements.insert(num);
        }
    }
};

int main() {
    SmallestInfiniteSet* obj = new SmallestInfiniteSet();

    cout << obj->popSmallest() << endl; // 1
    cout << obj->popSmallest() << endl; // 2
    obj->addBack(1);
    cout << obj->popSmallest() << endl; // 1
    cout << obj->popSmallest() << endl; // 3
    cout << obj->popSmallest() << endl; // 4
    obj->addBack(2);
    cout << obj->popSmallest() << endl; // 2

    delete obj;
    return 0;
}