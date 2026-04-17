#include "../src/sorting.h"
#include "rapidcheck/gtest.h"
#include "sorting.h"
#include "test_helpers.h"
#include "gtest/gtest.h"
#include <cstdlib>

//int* get_sorted(int* ar, int len) {
    /**
   * Return a COPY of ar in sorted order.
   * @param ar: The array to make a sorted copy of.
   * @param len: The length of ar
   * @return: A sorted copy of
   */

//    int* sorted_ar = copy_array(ar, len);
//    make_sorted(ar, len);
//    return sorted_ar;
//}



TEST(GetSortedTests, SimpleSortSortedArray) {
    /*
     * Check that we can sort an array that is already sorted.
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */
    int newarray[] = {7, 9, 13, 16, 18};
    int *sorted_array = get_sorted(newarray, 5);
    for (int i = 0; i < 4; i++) {
        EXPECT_LT(sorted_array[i], sorted_array[i+1]); << "This array should be sorted already" <<
    }
    free(sorted_array);

}

TEST(GetSortedTests, SimpleSortReverseSortedArray) {
    /*
     * Check that we can sort an array that is reverse sorted order.
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */
    int newarray[] = {100, 90, 80, 70, 60};
    int *sorted_array = get_sorted(newarray, 5);
    for (int i = 0; i < 4; i++) {
        EXPECT_LT(sorted_array[i], sorted_array[i+1]); << "This array did not sort correctly." <<
    }
    free(sorted_array);

}

TEST(GetSortedTests, SimpleSortAverageArray) {
    /*
     * Check that we can sort an array where the elements in it are in random order.
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */
    int newarray[] = {6, 9, 4, 12, 11};
    int *sorted_array = get_sorted(newarray, 5);
    for (int i = 0; i < 4; i++) {
        EXPECT_LT(sorted_array[i], sorted_array[i+1]); << "This array did not sort correctly." <<
    }
    free(sorted_array);

}

TEST(GetSortedTests, SimpleSortArrayWithDuplicates) {
    /*
     * Check that we can sort an array where there are duplicate elements in it.
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */
    int newarray[] = {11, 94, 73, 94, 94};
    int *sorted_array = get_sorted(newarray, 5);
    for (int i = 0; i < 4; i++) {
        EXPECT_LT(sorted_array[i], sorted_array[i+1]); << "This array did not sort correctly." <<
    }
    free(sorted_array);

}

TEST(GetSortedTests, SimpleOriginalDoesNotChange) {
    /*
     * Check that the original array was not modified.
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */
    int newarray[] = {1, 9, 5, 2, 3};
    int copyofnewarray[5];
    copy_vector_to_array(newarray, copyofnewarray);

    int *sorted_array = get_sorted(newarray, 5);

    for (int i = 0; i < 5){
        EXPECT_EQ(newarray[i], copyofnewarray[i]); << "The original aray should stay the same." >
    }
    free(sorted_array);
}

TEST(GetSortedTests, SimpleCopyWasMade) {
    /*
     * Check that the sorted array is copy of the original array in sorted order.
     * (ar and copy point to different locations in memory and no parts of the two arrays overlap)
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */
    int newarray[] = {30, 20, 50, 10, 40};
    int newarray_sorted[] = {10, 20, 30, 40, 50};
    int* copy_array = get_sorted(newarray, 5);


    for (int i = 0; i<5; i++) {
        EXPECT_EQ(copy_array[i], newarray_sorted[i]);
        EXPECT_NE(&newarray[i], &copy_array[i]);
    }

    free(copy_array);


}


RC_GTEST_PROP(GetSortedTests,
              PropertyAfterSortingValuesAreInAscendingOrder,
              ( std::vector<int> values) //<-- this will give you a randomized vector of ints named values
) {
    /* Check that after sorting an array, the values are in ascending order
     * Don't forget to free any memory that was dynamically allocated as part of this test
     */

    std::vector<int>my_array;
    my_array.push_back(values);

    int *my_new_array[] = get_sorted(my_array, my_array.size());

    for (int i = 0; i < my_array.size() - 1; i++) {
        EXPECT_LT(my_new_array[i], my_new_array[i + 1]);
    }

    free(my_new_array);
}

RC_GTEST_PROP(GetSortedTests,
              PropertyOriginalDoesNotChange,
              (const std::vector<int>&values)
) {
    /*
     * Check that the original array was not modified.
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */
    ;
}

RC_GTEST_PROP(GetSortedTests,
              PropertyCopyWasMade,
              (const std::vector<int>&values)
) {
    /*
     * Check that the sorted array is copy of the original array in sorted order.
     * (ar and copy point to different locations in memory and no parts of the two arrays overlap)
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */

}











