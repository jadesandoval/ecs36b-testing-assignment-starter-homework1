#include "../src/sorting.h"
#include "sorting.h"
#include "test_helpers.h"

#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "rapidcheck/gtest.h"
#include <algorithm>
#include <vector>

TEST(MinIndexOfArrayTests, SimpleMinIndexAtFrontOfArray) {
    /*
     * See if we can find the index of the minimum value when it is at the front of the array
     */
    int newarray[]= {1, 2, 3, 4, 5};
    ASSERT_EQ(min_index_of_array(newarray, 5), 0);
}

//int min_index_of_array(int* ar, int len) {
  /**
 * Find the INDEX of the minimum value in ar. If there are multiple values that are
 * the minimum, return the index of the first minimum.
 * @param ar: The array to search through
 * @param len: the number of elements in ar
 * @return: The INDEX of the minimum value in ar
 */


TEST(MinIndexOfArrayTests, SimpleMinIndexAtEndOfArray) {
    /*
     * See if we can find the index of the minimum value when it is at the end of the array
     */
    int newarray[]= {5, 4, 3, 2, 1};
    ASSERT_EQ(min_index_of_array(newarray, 5), 4);
}

TEST(MinIndexOfArrayTests, SimpleMinIndexAtMiddleOfArray) {
    /*
     * See if we can find the index of the minimum value when it is somewhere
     * in the "middle" of the array.
     */
    int newarray[]= {5, 4, 1, 2, 3};
    ASSERT_EQ(min_index_of_array(newarray, 5), 2);
}

TEST(MinIndexOfArrayTests, SimpleDuplicateMinimums) {
    /*
     * See if we return the index of the first minimum in the array
     * When there are multiple values that are the minimum.
     */
    int newarray[]= {8, 2, 7, 9, 2, 5};
    ASSERT_EQ(min_index_of_array(newarray, 6), 1);
}

TEST(MinIndexOfArrayTests, SimpleArrayDoesNotChange) {
    /*
     * Check that finding the minimum of the array did not change the contents of the array.
     */
    int newarray[]= {1, 2, 3, 4, 5};
    min_index_of_array(newarray, 5);

    for (int i = 0; i < 5; i++) {
        ASSERT_LE(newarray[i], newarray[i + 1]);
    }
}


RC_GTEST_PROP(MinIndexOfArrayTests,
              PropertyFindMinIndex,
              (const std::vector<int>& values)) {
    /* Check that the value at the location of the minimum index
     * is not larger than any of the other values in the array
     */

    if (values.empty()) return;

    std::vector<int> my_array = values;
    int min_index = min_index_of_array(my_array.data(), values.size());

    for (size_t i = 0; i < values.size(); i++) {
        RC_ASSERT(my_array[i] >= my_array[min_index]);
    }
}

RC_GTEST_PROP(MinIndexOfArrayTests,
              PropertyArrayDoesNotChange,
              (const std::vector<int>& values)) {
    /*
     * Check that finding the minimum of the array did not change the contents of the array.
     */
    RC_PRE(!values.empty());

    std::vector<int> my_array = values;
    min_index_of_array(my_array.data(), my_array.size());

    for (size_t i = 0; i < values.size(); i++) {
        RC_ASSERT(my_array[i] == values.at(i));
    }
}
