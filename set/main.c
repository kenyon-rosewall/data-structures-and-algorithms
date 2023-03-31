#include <stdio.h>
#include "set.h"

i32 multiply_by_ten(i32 value)
{
  return 10 * value;
}

b32 is_in_range(i32 value)
{
  return (value > 20) && (value < 70);
}

i32 main(i32 argc, char **argv)
{
  set *s = set_create(10);

  printf("Set empty: ");
  set_empty(s) ? printf("YES\n") : printf("NO\n");

  set_remove(s, 50);

  set_add(s, 10);
  set_add(s, 20);
  set_add(s, 30);
  set_add(s, 40);
  set_add(s, 50);
  set_add(s, 30);
  set_add(s, 60);
  set_add(s, 70);
  set_add(s, 80);
  set_add(s, 90);
  set_add(s, 100);
  set_add(s, 110);

  printf("Set full: ");
  set_full(s) ? printf("YES\n") : printf("NO\n");

  printf("Set contains 40: ");
  set_contains(s, 40) ? printf("YES\n") : printf("NO\n");
  printf("Set contains 41: ");
  set_contains(s, 41) ? printf("YES\n") : printf("NO\n");

  set_remove(s, 100);

  set_print(s);

  set *s2 = set_map(s, multiply_by_ten);
  printf("Multiplied by 10\n");
  set_print(s2);

  set *s3 = set_filter(s, is_in_range);
  printf("Subset within range\n");
  set_print(s3);

  set_destroy(s);
}