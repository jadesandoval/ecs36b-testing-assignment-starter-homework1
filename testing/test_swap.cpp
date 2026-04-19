#include <cstdlib>
#include <vector>
#include <algorithm>
#include "test_helpers.h"
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "sorting.h"
#include "rapidcheck/gtest.h"


TEST(SwapTests, SimpleSwapTwoValues) {
    /*
     * Swap two values and see if the swap was successful.
     */
    int a = 10;
    int b = 20;
    swap(&a, &b);

    ASSERT_EQ(a, 20);
    ASSERT_EQ(b, 10);
}

TEST(SwapTests, SimpleSwapValuesInArray) {
    /*
     * Swap a few values in an array.
     * Check that the ones that swapped did swap and the ones that didn't swap
     * are still at the same locations
     */
    int testvalues[] = {1, 2, 3, 4, 5};
    swap(&testvalues[0], &testvalues[1]);
    swap(&testvalues[3], &testvalues[4]);

    ASSERT_EQ(testvalues[0], 2);
    ASSERT_EQ(testvalues[1], 1);
    ASSERT_EQ(testvalues[2], 3);
    ASSERT_EQ(testvalues[3], 5);
    ASSERT_EQ(testvalues[4], 4);
}

RC_GTEST_PROP(SwapTests,
              PropertySwapTwoValues,
              (int a_start, int b_start)
) {
    /*
     * Swap two values and see if the swap was successful.
     */
  int a = a_start;
  int b = b_start;
  swap(&a_start, &b_start);

  ASSERT_EQ(a_start, b);
  ASSERT_EQ(b_start, a);
}


RC_GTEST_PROP(SwapTests,
              PropertySwapValuesInArray,
              (const std::vector<int>& values)
) {
    /*
     * Swap two values in an array. See that they swapped and the others did not
     */
    if (values.size() >= 2) {
        std::vector<int> my_array = values;
        std::vector<int> backup_array = values;

        int zeroindex = my_array[0];
        int oneindex = my_array[1];

        swap(&my_array[0], &my_array[1]);
        RC_ASSERT(my_array[0] == oneindex);
        RC_ASSERT(my_array[1] == zeroindex);

        for (size_t i = 2; i < values.size(); i++) {
            RC_ASSERT(my_array[i] == backup_array[i]);
        }
    }
}
