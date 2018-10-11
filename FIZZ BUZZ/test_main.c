#include <string.h>

#include <stdarg.h>
#include <setjmp.h>
#include <cmocka.h>

#include "fizz_buzz.h"

static void input_fizz_buzz_test(
    int input_size,
    int test_input,
    char* expected_output)
{
    int input[input_size];
    char output[10];
    int i = 0;
    int index = 0;

    while(index<input_size){
        if(test_input == 3){
            if(3*i%5 != 0){
                input[index] = 3*i;
                ++index;
            }
        }
        else if(test_input == 5){
            if(5*i%3 != 0){
                input[index] = 5*i;
                ++index;
            }

        }
        else if(test_input == 35){
            if(5*i%3 != 0 && 3*i%5 != 0){
                input[index] = 5*3*i;
                ++index;
            }

        }
        else{
            if(i%3 != 0 && i%5 != 0){
                input[index] = i;
                ++index;
            }
        }
        ++i;
    }

    for(i=0; i<input_size; ++i){
        fizz_buzz_detector(output, input[i]);
        assert_string_equal(expected_output, output);
    }

}


static void test_given_3_20times_should_be_fizz(void **state){
    (void)state;
    input_fizz_buzz_test(30, 3, "Fizz"); 
}

static void test_given_5_20times_should_be_buzz(void **state){
    (void)state;
    input_fizz_buzz_test(30, 5, "Buzz"); 
}

static void test_given_3_5_20times_should_be_fizzbuzz(void **state){
    (void)state;
    input_fizz_buzz_test(30, 35, "FizzBuzz"); 
}

static void test_not_3_5_20times_should_be_empty(void **state){
    (void)state;
    input_fizz_buzz_test(30, 0, ""); 
}

int main(){
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_given_3_20times_should_be_fizz),
        cmocka_unit_test(test_given_5_20times_should_be_buzz),
        cmocka_unit_test(test_given_3_5_20times_should_be_fizzbuzz),
        cmocka_unit_test(test_not_3_5_20times_should_be_empty),
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
    return 0;
}

