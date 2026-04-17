#include <cstdlib>
#include <string>
#include "gtest/gtest.h"
#include "formatting.h"
#include "test_helpers.h"
#include "rapidcheck/gtest.h"

auto word_generator() {
    /* Creates a generator for a string made up of
     * characters from [a - z]
     */
    auto lower_case_letter_generator = rc::gen::inRange<char>('a', 'z' + 1);
    return rc::gen::container<std::string>(lower_case_letter_generator);
}

auto vector_of_ints_to_vector_of_strings(const std::vector<int>& numbers) {
    /* Create a vector of strings from a vector of ints
     */
    std::vector<std::string>string_ofnumbers;

    for (int i = 0; i < numbers.size(); i++) {
        std::string addthis = std::to_string(numbers.at(i));
        string_ofnumbers.push_back(addthis);
    }
    return string_ofnumbers;

}

//void parse_args(int argc, char** argv, int* ar_out, int* len_out){
  /**
 * Transform the command line arguments from their string representations to their numeric values
 * @param argc: the number of the command line arguments
 * @param argv: the command line arguments
 * @param ar_out: An output parameter. The array to store the command line arguments into. It is assumed that
   * no space has been made for the values so this function will allocate the space for the values inside of ar_out.
   * If there are no command line arguments ar_out should be set to NULL.
 * @param len_out:  An output parameter. The number of elements placed into ar_out.
 */

//  *len_out = argc - 1;
//  ar_out = (int*)malloc(*len_out);
//  for(int i = 0; i < *len_out; ++i){
//    sscanf(argv[i], "%d", ar_out[i]);
//  }

//}
 

TEST(ParseArgsTests, SimpleCheckArgumentsParsedSuccessfully) {
    /*
     * Check that you parse the command line arguments correctly.
     * (ar_out and len_out are set to the right values).
     * Don't forget to free any memory that was dynamically allocated as part of your test.'
     */
    parse_args(5, "1, 2, 3, 4, 5");

}

TEST(ParseArgsTests, SimpleCheckParseNoArgs) {
    /*
     * Check that you parse you can successfully parse "no" command line arguments.
     */
}


RC_GTEST_PROP(ParseArgsTests,
              PropertyCheckArgumentsParsedSuccessfully,
              ()
) {
    /* Check that we can correctly parse the command line
     * arguments when we receive 1 or more arguments.
     * Don't forget to free any memory that was dynamically allocated as part of this test
     */
}

RC_GTEST_PROP(ParseArgsTests,
              PropertyCheckParseNoArgs,
              ()
) {
    /*
     * Check that you parse you can successfully parse "no" command line arguments.
     */
}
