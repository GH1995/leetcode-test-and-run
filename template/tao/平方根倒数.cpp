#include <stdio.h>

float Q_rsqrt(float number) {
  const float threehalfs = 1.5F;
  float x2 = number * 0.5F;
  float y = number;
  long i = *(long*)&y;
  i = 0x5f3759df - (i >> 1);
  y = *(float*)&i;
  y = y * (threehalfs - (x2 * y * y));

  return y;
}

int main(void) {
  printf("%f\n", Q_rsqrt(100));
  return 0;
}
