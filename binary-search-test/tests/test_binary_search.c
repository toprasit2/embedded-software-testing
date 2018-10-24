#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include "binary_search.h"

static void test_1to10_F1_L10_K5_should_5(void **state){
    int input[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int output = binary_search(input,0,9,5);
    assert_int_equal(4, output);
}

static void test_1to10_F1_L10_K12_should_n11(void **state){
    int input[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int output = binary_search(input,0,9,12);
    assert_int_equal(-11, output);
}

static void test_1to10_F3_L8_K9_should_8(void **state){
    int input[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int output = binary_search(input,3,8,9);
    assert_int_equal(8, output);
}

static void test_1to10_F5_L3_K9_should_n6(void **state){
    int input[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int output = binary_search(input,5,3,9);
    assert_int_equal(-6, output);
}

static void test_1to10_Fm1_Lm9_K9_should_0(void **state){
    int input[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int output = binary_search(input,-1,-9,9);
    assert_int_equal(0, output);
}

static void test_1to10_F1_L9_K3_should_n2(void **state){
    int input[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int output = binary_search(input,1,9,3);
    assert_int_equal(2, output);
}

int main(int argc, const char * argv[])
{
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_1to10_F1_L10_K5_should_5),
	cmocka_unit_test(test_1to10_F1_L10_K12_should_n11),
        cmocka_unit_test(test_1to10_F3_L8_K9_should_8),
	cmocka_unit_test(test_1to10_F5_L3_K9_should_n6),
        cmocka_unit_test(test_1to10_Fm1_Lm9_K9_should_0),
    cmocka_unit_test(test_1to10_F1_L9_K3_should_n2),
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
 


}
