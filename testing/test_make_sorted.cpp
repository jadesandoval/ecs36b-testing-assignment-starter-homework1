#include "../src/sorting.h"
#include "sorting.h"
#include "test_helpers.h"
#include "gtest/gtest.h"
#include "rapidcheck/gtest.h"
#include <cstdlib>
#include <vector>

// void make_sorted(int* ar, int len) {
  /**
 * Sort the given array in place.
 * @param ar: The array to be sorted.
 * @param len: The length of the array to be sorted.
 */
//  for (int i = 0; i < len; ++i) {
//    int min_index = min_index_of_array(ar + i, len);
//    swap(ar + i, ar + min_index);
//  }
//}


TEST(MakeSortedTests, SimpleSortSortedArray) {
    /*
     * Check that we can sort an array that is already sorted.
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */
    int myarray[] = {10, 20, 30, 40, 50};
    make_sorted(myarray, 5);

    for (int i = 0; i < 4; i++) {
      ASSERT_LE(myarray[i], myarray[i+1]) << "Array should stay sorted.";
    }

}

TEST(MakeSortedTests, SimpleSortReverseSortedArray) {
    /*
     * Check that we can sort an array that is reverse sorted order.
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */
    int myarray[] = {5, 4, 3, 2, 1};
    make_sorted(myarray, 5);

    for (int i = 0; i < 4; i++) {
        ASSERT_LE(myarray[i], myarray[i+1]) << "Array should be sorted.";
    }
}


TEST(MakeSortedTests, SimpleSortAverageArray) {
    /*
     * Check that we can sort an array where the elements in it are in random order.
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */
    int myarray[] = {20, 61, 88, 27, 91};
    make_sorted(myarray, 5);

    for (int i = 0; i < 4; i++) {
        ASSERT_LE(myarray[i], myarray[i+1]) << "Array should be sorted." ;
    }
}

TEST(MakeSortedTests, SimpleSortArrayWithDuplicates) {
    /*
     * Check that we can sort an array where there are duplicate elements in it.
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */
    int myarray[] = {88, 61, 88, 27, 91};
    make_sorted(myarray, 5);

    for (int i = 0; i < 4; i++) {
        ASSERT_LE(myarray[i], myarray[i+1]) << "Array should be sorted." ;
    }
}

RC_GTEST_PROP(MakeSortedTests,
              PropertyAfterSortingValuesAreInAscendingOrder,
              ( std::vector<int> values)
) {
    /* Test that after sorting an array, the values are in ascending order
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */
    RC_PRE(!values.empty());
    std::vector<int> my_array = values;
    make_sorted(my_array.data(), my_array.size());

    for (size_t i = 0; i < values.size() - 1; i++) {
        RC_ASSERT(my_array[i] <= my_array[i+1]);
    }
}
