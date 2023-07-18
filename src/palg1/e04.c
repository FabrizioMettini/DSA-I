#include <assert.h>
#include <string.h>

// O(n)
// It can't be optimized
int findX(char *s) {
  for (int i = 0; i < strlen(s); i++) {
    if (s[i] == 'X') {
      return i;
    }
  }
  return -1;
}

int main() {
  char s1[] = "I am going to the XGAMES next week.";
  char s2[] = "Joke, I wish.";
  assert(findX(s1) == 18);
  assert(findX(s2) == -1);
  return 0;
}