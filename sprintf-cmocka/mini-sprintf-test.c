#include <stdio.h>
#include <memory.h>
#include <setjmp.h>
#include <cmocka.h>

static void test_sprintf_with_no_format_operation(void **state)
{
    (void) state;
    char output[5] = "";
    
    assert_int_equal( 3, sprintf(output, "hey"));
    assert_string_equal("hey", output);
}

static void test_sprintf_with_format_number(void **state)
{
    (void) state;
    char output[5] = "";
    
    assert_int_equal( 6, sprintf(output, "hey %d",10));
    assert_string_equal("hey 10", output);
}

static void test_sprintf_with_wrong_input(void **state)
{
    (void) state;
    char output[5] = "";
    
    assert_int_equal( 6, sprintf(output, "hey %d",10));
    assert_string_not_equal("hey 20", output);
}

int main(int ac, char** av)
{
    char output[10];
   printf("%d", sprintf(output, "hey %d",10));
   const struct CMUnitTest tests[] = {
       cmocka_unit_test(test_sprintf_with_no_format_operation),
       cmocka_unit_test(test_sprintf_with_format_number),
       cmocka_unit_test(test_sprintf_with_wrong_input)
   };
   return cmocka_run_group_tests(tests, NULL, NULL);
}
