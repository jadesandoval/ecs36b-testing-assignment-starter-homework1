#include <cstdlib>
#include <vector>
#include <algorithm>
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "sorting.h"
#include "test_helpers.h"
#include "rapidcheck/gtest.h"

TEST(CopyArrayTests, SimpleValuesAreSame) {
    /*
     * Check that the values in the copy are the same as the values in the original array.
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */

    int arraytest[] = {5, 10, 15, 20, 25};
    int *newarray = copy_array(arraytest, 5);

    for (int i = 0; i < 5; i++) {
        EXPECT_EQ(arraytest[i], newarray[i]) << "Values in copy should be same as orginal.";
    }
    free(newarray);
}

TEST(CopyArrayTests, SimpleOriginalDoesNotChange) {
    /*
     * Check that the  values in the original array did not change.
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */
    int arraytests[] = {1, 2, 3, 4};
    int *newarray = copy_array(arraytests, 4);

    for (int i = 0; i < 4; i++) {
      EXPECT_EQ(arraytests[i], i + 1) << "Values in the orginal array should not change.";
    }
    free(newarray);
}


TEST(CopyArrayTests, SimpleCopyWasMade) {
    /*
     * Check that a copy was actually made
     * (ar and copy point to different locations in memory and no parts of the two arrays overlap)
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */
    int arraytest[] = {1, 2, 3, 4};
    int *newarray = copy_array(arraytest, 4);

    EXPECT_NE(&arraytest[0], &newarray[0]) << "ar and copy should be in two different places in memory" ;
    free(newarray);

}


RC_GTEST_PROP(CopyArrayTests,
              PropertyValuesAreSame,
              (const std::vector<int>& values)
) {
    /*
     * Check that the values in the copy are the same as the values in the original array.
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */

    std::vector<int> my_array = values;
    int* newarray = copy_array(my_array.data(), my_array.size());

    for (size_t i = 0; i < values.size(); i++) {
        RC_ASSERT(newarray[i] == my_array[i]);
    }
    free(newarray);

}

RC_GTEST_PROP(CopyArrayTests,
              PropertyOriginalDoesNotChange,
              (const std::vector<int>&values)
) {
    /*
     * Check that the  values in the original array did not change.
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */
    std::vector<int> my_array = values;

    int* copy = copy_array(my_array.data(), my_array.size());

    for (size_t i = 0; i < values.size(); i++) {
        RC_ASSERT(my_array[i] == values.at(i));
    }
    free(copy);
}

RC_GTEST_PROP(CopyArrayTests,
              PropertyCopyWasMade,
              (const std::vector<int>&values)
) {
    /*
  * Check that a copy was actually made
  * (ar and copy point to different locations in memory and no parts of the two arrays overlap)
  * Don't forget to free any memory that was dynamically allocated as part of your test.
  */
    std::vector<int> my_array = values;

    int* mycopy = copy_array(my_array.data(), my_array.size());
    RC_ASSERT_FALSE(my_array.data() == mycopy);

    free(mycopy);
}



