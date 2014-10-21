/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  20/10/14 15:15:35
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "quickSort.h"
#include "mergeSort.h"

//void main() 
//{
//	int a[] = { 7, 12, 1, -2, 0, 15, 4, 11, 9};
//
//	int i;
//	printf("\n\nUnsorted array is:  ");
//	for(i = 0; i < 9; ++i)
//		printf(" %d ", a[i]);
//
//	mergeSort( a);
//
//	printf("\n\nSorted array is:  ");
//	for(i = 0; i < 9; ++i)
//		printf(" %d ", a[i]);
//
//}

//int main() {
//  int a[100], b[100], m, n, c, sorted[200];
// 
//  printf("Input number of elements in first array\n");
//  scanf("%d", &m);
// 
//  printf("Input %d integers\n", m);
//  for (c = 0; c < m; c++) {
//    scanf("%d", &a[c]);
//  }
// 
//  printf("Input number of elements in second array\n");
//  scanf("%d", &n);
// 
//  printf("Input %d integers\n", n);
//  for (c = 0; c < n; c++) {
//    scanf("%d", &b[c]);
//  }
//
//	int aa[] = { 7, 12, 1, 2, 0, 15, 4, 11, 9};
//
//  int ln=sizeof(aa)/sizeof(int);
//
//  printf("%d\n", arrayLength(*aa));
// 
//  merge(a, m, b, n, sorted);
// 
//  printf("Sorted array:\n");
// 
//  for (c = 0; c < m + n; c++) {
//    printf("%d\n", sorted[c]);
//  }
// 
//  return 0;
//}

int main(int argc, char* argv[]) {
    int fd;
    unsigned char c;

    /* needs error checking */
    fd = open(argv[1], O_RDONLY);
    read(fd, &c, sizeof(c));
    printf("<0x%x>\n", c);
    return 0;
}
