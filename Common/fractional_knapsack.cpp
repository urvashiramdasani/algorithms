// This program fails on one of the hidden test cases of Coursera. I dont know what is the problem with the code!

#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

double get_optimal_value(long int capacity, vector<long int> weights, vector<long int> values, int n) {
  double value = 0.0;

  // write your code here
  double vbyw[n];
  for(int i = 0; i < n; i++) vbyw[i] = ((double) values[i]) / weights[i];
  int size = n;
  for(int i = 0; i < n; i++) {
    int max = 0;
    for(int i = 0; i < size; i++) {
      if(vbyw[max] < vbyw[i]) max = i;
    }
    // std::cout<<weights[max]<<" "<<values[max]<<std::endl;
    size--;
    if(weights[max] < capacity) {
      capacity -= weights[max];
      value += (double) values[max];
    } else {
        value += (((double) values[max]) * capacity) / weights[max];
        capacity = 0;
    }
    if(capacity <= 0) break;
  }
  return value;
}

int main() {
  int n;
  long int capacity;
  std::cin >> n >> capacity;
  vector<long int> values(n);
  vector<long int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values, n);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
