#include <stdio.h>

// O(2^n)
int fib_R(int n){
  if (n == 0)
    return 0;

  if(n == 1)
    return 1;

  return fib_R(n - 1) + fib_R(n - 2);
}

// O(n)
int fib_iter(int n){
  int memo[1000];
  memo[0] = 0;
  memo[1] = 1;

  for(int i = 2; i <= n; i++) {
    memo[i] = memo[i - 1] + memo[i - 2];
  }

  return memo[n];
}

// O(n)
int fib(int n, int memo[], int calc[]){
  if(calc[n])
    return memo[n];

  if (n == 0)
    return 0;

  if(n == 1)
    return 1;

  int res = fib(n - 1, memo, calc) + fib(n - 2, memo, calc);
  calc[n] = 1;
  memo[n] = res;
  return res;
}

int fib_dp(int n){
  int memo[1000], calc[1000] = {0};
  return fib(n, memo, calc);
}

int main(){
  printf("%d\n", fib_R(6));
  printf("%d\n", fib_iter(6));
  printf("%d\n", fib_dp(6));
  return 0;
}
