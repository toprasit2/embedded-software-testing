#include <string.h>

#include <stdarg.h>
#include <setjmp.h>
#include <cmocka.h>

#include "funny_string.h"


static void test_given_equal_different_should_be_funny(void **state){
    (void)state;
    char output[10];
    int i = 0;
    char input[][100] = {
        "ab", "cd",
        "AB", "CD",
        "0110",
        "*//*",
        "acxz", "bdxz", "cbhi", "jkmn", "ehux", "ggbb", "abba", "abcd",
        "ABCD", "BDXZ", "CBHI", "JKMN", "EHUX", "GGBB", "ABBA", "ABCD",
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    };

    for(i=0; i<12; ++i){
        distance = funny_string(input[i], output);
        assert_string_equal("funny", output);
        assert_string_not_equal("not funny", output);
    }
}

static void test_given_not_equal_different_should_be_funny(void **state){
    (void)state;
    char output[10];
    int i = 0;
    char input[][5] = { "bcxz", "adxz", "azax", "azbx", "mnos", "ggez", "AZEW", "LPWQ"};

    // strcpy(input[0],"bcxz");
    // strcpy(input[1],"adxz");

    for(i=0; i<8; ++i){
        funny_string(input[i], output);
        assert_string_equal("not funny", output);
        assert_string_not_equal("funny", output);
    }
}

int main(){
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_given_equal_different_should_be_funny),
        cmocka_unit_test(test_given_not_equal_different_should_be_funny),
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
    return 0;
}

