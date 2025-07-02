#include <iostream>
#include <queue>

class RecentCounter {
private:
    std::queue<int> q;

public:
    RecentCounter() {
        // Constructor — no setup needed
    }
    
    int ping(int t) {
        // Add the new ping time to the queue
        q.push(t);
        
        // Remove all pings that are older than t - 3000
        while (!q.empty() && q.front() < t - 3000) {
            q.pop();
        }
        
        // The size of the queue is the number of pings in the range [t-3000, t]
        return q.size();
    }
};

int main() {
    RecentCounter* obj = new RecentCounter();
    
    // Example test pings
    std::cout << obj->ping(1) << std::endl;     // Output: 1
    std::cout << obj->ping(100) << std::endl;   // Output: 2
    std::cout << obj->ping(3001) << std::endl;  // Output: 3
    std::cout << obj->ping(3002) << std::endl;  // Output: 3
    
    // Clean up
    delete obj;
    return 0;
}