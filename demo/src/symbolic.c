#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <klee/klee.h>

/**
  * read_buffer is to read element in buffer
  */
int read_buffer(int *output, int arr[], int index, int max_len) {
  if (index < max_len) {
    *output = arr[index];
    return 0;
  }
  return -1;
}

/**
  * results[i] = arr[i] % mod
  */
int mod(int results[], int arr[], int start_index, int end_index, int mod) {
  for (int i = start_index; i < end_index; i++) {
    results[i] = arr[i] % mod;
  }
  return 0;
}

/**
  * results[i] = arr[i] / div
  */
int divide(int results[], int arr[], int start_index, int end_index, int div) {
  for (int i = start_index; i < end_index; i++) {
    results[i] = arr[i] / div;
  }
  return 0;
}

void free_then_set_null(int *p) {
  assert(p != NULL);
  free(p);
  p = NULL;
}

/**
  * [p] = [p] + arr[i]
  */
int padd(int *p, int arr[], int i) {
  if (arr == NULL) {
    return -1;
  }
  *p = *p + arr[i];
  return 0;
}

/**
  * set all elements as 0
  */
void memset_zero(int arr[], int n) {
  memset(arr, 0, n);
}

int main(){
  int n;
  int choice;
  int arr[10];
  int arr_len;

  klee_make_symbolic(&n, sizeof(n), "n");
  klee_make_symbolic(&choice, sizeof(choice), "choice");
  klee_make_symbolic(&arr_len, sizeof(arr_len), "arr_len");

  for (int i = 0; i < 10; i++) {
    arr[i] = i;
  }

  switch (choice) {
  case 1: {
    int *p = malloc(sizeof(int));
    read_buffer(p, arr, n, arr_len);
    break;
  }
  case 2: {
    int results[10] = { 0 };
    mod(results, arr, 1, 5, arr_len);
    break;
  }
  case 3: {
    int results[10] = { 0 };
    divide(results, arr, 1, 5, 2);
    free(results);
  }
  case 4: {
    int *p;
    klee_make_symbolic(&p, sizeof(p), "p");
    free_then_set_null(p);
  }
  case 5: {
    int *p = malloc(sizeof(int));
    *p = 12;
    free_then_set_null(p);
    padd(p, arr, 5);
    break;
  }
  case 6: {
    int arr[10];
    memset_zero(arr, arr_len);
    memcpy(arr, arr, 5);
    break;
  }
  default:
    return 0;
  }
}
