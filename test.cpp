#include <algorithm>

class accounts {};

int main(void) {
  int amount[] = {42, 54, 957, 432, 1234, 0, 754, 16576};
  std::vector<int> accounts(amount, amount + 8);
}