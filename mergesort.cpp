#include "mergesort.h"

/**
 * Helper function to merge sort
 * Returns true or false if conditional is met
 * Replaces "if (a[i1] < a[i2])" 
 * Necessary if you want to compare criterias
 * @param arr Country array
 * @param i1 Next element to consider in the first half
 * @param i2 Next element to consider in the second half 
 * @param choice Numerical value which determines the criteria to be sorted by
**/
bool merge_comparison(Country* arr, int i1, int i2, int choice) {
	switch (choice) {
        case 1: 
            return arr[i1].get_name() < arr[i2].get_name();
        case 2:
            return arr[i1].get_code() < arr[i2].get_code();
        case 3:
            return arr[i1].get_calling() < arr[i2].get_calling();
        case 4:
            return arr[i1].get_year() < arr[i2].get_year();
        case 5:
            return arr[i1].get_emissions() < arr[i2].get_emissions();
        case 6:
            return arr[i1].get_population() < arr[i2].get_population();
        case 7:
            return arr[i1].get_area() < arr[i2].get_area();
        case 8:
            return arr[i1].get_percent() < arr[i2].get_percent();
        case 9:
            return arr[i1].get_density() < arr[i2].get_density();
        default:
            return false;
    }
}

/** 
   Merges two adjacent ranges in an array.
   @param arr the Country array with the elements to merge
   @param from the start of the first range
   @param mid the end of the first range
   @param to the end of the second 
   @https://learn.zybooks.com/zybook/OHLONECS124ChenhansaFall2023/chapter/14/section/7
**/
void merge(Country* arr, int from, int mid, int to,int choice) {
	int n = to - from + 1; // Size of the range to be merged 
   // Merge both halves into a temporary array b 
   // We allocate the array dynamically since its size is only
   // known at run time--see Section 7.4
   Country* b = new Country[n];

   int i1 = from;
      // Next element to consider in the first half 
   int i2 = mid + 1;
      // Next element to consider in the second half 
   int j = 0; // Next open position in b 

   // As long as neither i1 nor i2 is past the end, move the smaller
   // element into b
  
   while (i1 <= mid && i2 <= to)
   {  
      if (merge_comparison(arr,i1,i2,choice))
      {  
         b[j] = arr[i1];
         i1++;
      }
      else
      {  
         b[j] = arr[i2];
         i2++;
      }
      j++;
   }

   // Note that only one of the two while loops below is executed

   // Copy any remaining entries of the first half
   while (i1 <= mid)
   {  
      b[j] = arr[i1];
      i1++;
      j++;
   }
   // Copy any remaining entries of the second half
   while (i2 <= to)
   {  
      b[j] = arr[i2];
      i2++;
      j++;
   }

   // Copy back from the temporary array
   for (j = 0; j < n; j++)
   {
      arr[from + j] = b[j];
   }

   // The temporary array is no longer needed.
   delete[] b;
}

/**  
   Sorts the elements in a range of an array.
   @param a the Country array with the elements to sort
   @param from start of the range to sort
   @param to end of the range to sort
*/
void merge_sort(Country *arr, int from, int to,int choice) {
   if (from == to) { return; }
   int mid = (from + to) / 2;
   // Sort the first and the second half
   merge_sort(arr, from, mid,choice);
   merge_sort(arr, mid + 1, to,choice);
   merge(arr, from, mid, to,choice);
}