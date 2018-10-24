#include <string.h>

#include "binary_search.h"

int binary_search(int sorted_array[], int first, int last, int key) {
   // function:
   //   Searches sorted_array[first]..sorted_array[last] for key.  
   // returns: index of the matching element if it finds key, 
   //         otherwise  -(index where it could be inserted)-1.
   // parameters:
   //   sorted_array in  array of sorted (ascending) values.
   //   first, last in  lower and upper subscript bounds
   //   key         in  value to search for.
   // returns:
   //   index of key, or -insertion_position -1 if key is not 
   //                 in the array. This value can easily be
   //                 transformed into the position to insert it.
   
   while (first <= last) {
       int mid = (first + last) / 2;  // compute mid point.
       if (key > sorted_array[mid]) 
           first = mid + 1;  // repeat search in top half.
       else if (key < sorted_array[mid]) 
           last = mid - 1; // repeat search in bottom half.
       else
           return mid;     // found it. return position /////
   }
   return -(first + 1);    // failed to find key
}
