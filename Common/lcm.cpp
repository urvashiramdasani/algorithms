#include <iostream>
#include <algorithm>

long long gcd_fast(int a, int b) {
  if(b == 0) return a;
  return gcd_fast(b, a % b);
}

long long lcm_naive(int a, int b) {
	return (a/ gcd_fast(a, b) * b);
}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << lcm_naive(a, b) << std::endl;
  return 0;
}
