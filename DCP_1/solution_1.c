#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
 * Given a list of numbers and a number k, 
 * return whether any two numbers from the list add up to k.
 * For example, given [10, 15, 3, 7] and k of 17, 
 * return true since 10 + 7 is 17.
 * Bonus: Can you do this in one pass?
 */

void swap(int *, int*);
void sort(int *, int);
bool adds_up(int *, int, int);

int main(int argc, char **argv)
{
    // Must provide atleast 2 arguments.
    if(argc < 3) {
        printf("Minimum usage: ./prog x k\n");
        printf("Usage: ./prog x1 x2 x3 ... xn k\n");
        return EXIT_FAILURE;
    }
    // Size of the buffer will be the number of arguments
    // minus the first and last argument (program and k, respectively).
    int n = argc - 2;
    int x[n];
    for(int i = 0; i < n; i++) {
        // Cast to int. Didn't bother with variable int sizes.
        x[i] = atoi(argv[i + 1]);
    }
    // Cast our k to int.
    int k = atoi(argv[n + 1]);
    // 1 == True, 0 == False
    printf("%d\n", adds_up(x, k, n));
    return EXIT_SUCCESS;
}

void swap(int *x, int *y)
{
    // Simple pointer swap
    int temp = *x;
    *x = *y;
    *y = temp;
}
 
void sort(int *unsorted_array, int n)
{
   // Bubble Sort, didn't bother with Quick Sort.
   // You have to break the array and blah blablah blablhaaha
   for (int i = 0; i < n - 1; i++) { 
       for (int j = 0; j < n - i - 1; j++) {
           if (unsorted_array[j] > unsorted_array[j + 1]) {
              swap(&unsorted_array[j], &unsorted_array[j + 1]);
           }
       }
   }
}

bool adds_up(int *numbers, int test_value, int size)
{
    // Define the minimum and maximum size of the buffer.
    int arr_min = 0;
    int arr_max = size - 1;
    int num;
    // The following will only work on sorted buffers.
    sort(numbers, size);
    // Min and Max will approach each other, but should never cross.
    while (arr_min < arr_max) {
        // Sum up the numbers at the min and max end.
        num = numbers[arr_min] + numbers[arr_max];
        if(num == test_value) {
            return true; // Yay the two add up!
        } else if(num < test_value) {
            arr_min++; // Too small.
        } else {
            arr_max--; // Too large.
        }
    }
    // Couldn't find any suitable pairs.
    return false;
}
