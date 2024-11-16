#include <climits>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// Structure to represent a point (position, cost per unit length)
struct Point {
  int x, cost;
  Point(int x = 0, int cost = 0) : x(x), cost(cost) {}
};

// Compare function for the priority queue (min-heap)
struct compare {
  bool operator()(const Point &p1, const Point &p2) {
    return p1.cost > p2.cost;
  }
};

long long minCostConnectPoints(int n, vector<int> &positions,
                               vector<int> &costs) {
  // Priority queue to store the points by their minimum cost to connect
  priority_queue<Point, vector<Point>, compare> pq;

  // Initialize all points with their cost to connect as infinity
  vector<long long> minCost(n, LLONG_MAX);
  minCost[0] = 0; // Start from the first point

  // Push the first point into the priority queue
  pq.push(Point(0, 0));

  long long totalCost = 0;

  // Prim's algorithm to connect all points
  while (!pq.empty()) {
    int current = pq.top().x;
    long long currentCost = pq.top().cost;
    pq.pop();

    // Add the cost to the total cost
    totalCost += currentCost;

    // Iterate over all the remaining points
    for (int i = 0; i < n; ++i) {
      if (i != current) {
        long long cost = min(costs[i], costs[current]) *
                         abs(positions[i] - positions[current]);
        if (cost < minCost[i]) {
          minCost[i] = cost;
          pq.push(Point(i, cost));
        }
      }
    }
  }

  return totalCost;
}

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vector<int> positions(n), costs(n);

    for (int i = 0; i < n; ++i) {
      cin >> positions[i];
    }

    for (int i = 0; i < n; ++i) {
      cin >> costs[i];
    }

    cout << minCostConnectPoints(n, positions, costs) << endl;
  }

  return 0;
}
