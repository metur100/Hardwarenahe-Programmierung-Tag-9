#include "dyn_array.h"

// checkmk dyn_array_tests.ts > dyn_array_tests.c
// gcc dyn_array.c dyn_array_tests.c -o tests -Wall -lsubunit -lm -lpthread -lrt -lcheck -std=c99 -g -fprofile-arcs -ftest-coverage


#test check_create
    dyn_array *testarray = create();
    ck_assert_int_eq(testarray->fill_level, 0);
    ck_assert_int_eq(testarray->length, 1);


#test add_first_element
    dyn_array *testarray = create();
    add_last(testarray, "Erstes");
    ck_assert_int_eq(testarray->fill_level, 1);
    ck_assert_int_eq(testarray->length, 1);
    ck_assert_str_eq(testarray->strings[0], "Erstes");


#test double_size
    dyn_array *testarray = create();
    double_array(testarray);
    ck_assert_int_eq(testarray->fill_level, 0);
    ck_assert_int_eq(testarray->length, 2);
    double_array(testarray);
    ck_assert_int_eq(testarray->fill_level, 0);
    ck_assert_int_eq(testarray->length, 4);


#test add_more_elements
    dyn_array *testarray = create();
    add_last(testarray, "Erstes");
    add_last(testarray, "Zweites");
    ck_assert_int_eq(testarray->fill_level, 2);
    ck_assert_int_eq(testarray->length, 2);
    add_last(testarray, "Drittes");
    ck_assert_int_eq(testarray->fill_level, 3);
    ck_assert_int_eq(testarray->length, 4);
    add_last(testarray, "Viertes");
    ck_assert_int_eq(testarray->fill_level, 4);
    ck_assert_int_eq(testarray->length, 4);
    add_last(testarray, "Fünftes");
    ck_assert_int_eq(testarray->fill_level, 5);
    ck_assert_int_eq(testarray->length, 8);
    ck_assert_str_eq(testarray->strings[0], "Erstes");
    ck_assert_str_eq(testarray->strings[1], "Zweites");
    ck_assert_str_eq(testarray->strings[2], "Drittes");
    ck_assert_str_eq(testarray->strings[3], "Viertes");
    ck_assert_str_eq(testarray->strings[4], "Fünftes");
    
#test halve_size_empty_enough
    dyn_array *testarray = create();
    testarray->length = 16;
    halve_array(testarray);
    ck_assert_int_eq(testarray->fill_level, 0);
    ck_assert_int_eq(testarray->length, 8);
    halve_array(testarray);
    ck_assert_int_eq(testarray->fill_level, 0);
    ck_assert_int_eq(testarray->length, 4);
    testarray->fill_level = 2;
    halve_array(testarray);
    ck_assert_int_eq(testarray->fill_level, 2);
    ck_assert_int_eq(testarray->length, 2);


#test halve_size_not_empty_enough
    dyn_array *testarray = create();
    testarray->length = 16;
    testarray->fill_level = 9;
    halve_array(testarray);
    ck_assert_int_eq(testarray->fill_level, 9);
    ck_assert_int_eq(testarray->length, 16);

#test remove_last_element_no_size_changing
    dyn_array *testarray = create();
    add_last(testarray, "Erstes");
    add_last(testarray, "Zweites");
    add_last(testarray, "Drittes");
    add_last(testarray, "Viertes");
    remove_string(testarray, "Viertes");
    ck_assert_int_eq(testarray->fill_level, 3);
    ck_assert_int_eq(testarray->length, 4);
    ck_assert_str_eq(testarray->strings[0], "Erstes");
    ck_assert_str_eq(testarray->strings[1], "Zweites");
    ck_assert_str_eq(testarray->strings[2], "Drittes");


#test remove_last_element_with_size_changing
    dyn_array *testarray = create();
    add_last(testarray, "Erstes");
    add_last(testarray, "Zweites");
    add_last(testarray, "Drittes");
    add_last(testarray, "Viertes");
    add_last(testarray, "Fünftes");
    remove_string(testarray, "Fünftes");
    ck_assert_int_eq(testarray->fill_level, 4);
    ck_assert_int_eq(testarray->length, 4);
    ck_assert_str_eq(testarray->strings[0], "Erstes");
    ck_assert_str_eq(testarray->strings[1], "Zweites");
    ck_assert_str_eq(testarray->strings[2], "Drittes");
    ck_assert_str_eq(testarray->strings[3], "Viertes");


#test remove_only_element
    dyn_array *testarray = create();
    add_last(testarray, "Erstes");
    remove_string(testarray, "Erstes");
    ck_assert_int_eq(testarray->fill_level, 0);
    ck_assert_int_eq(testarray->length, 1);


#test remove_middle_element
    dyn_array *testarray = create();
    add_last(testarray, "Erstes");
    add_last(testarray, "Zweites");
    add_last(testarray, "Drittes");
    add_last(testarray, "Viertes");
    add_last(testarray, "Fünftes");
    remove_string(testarray, "Drittes");
    ck_assert_int_eq(testarray->fill_level, 4);
    ck_assert_int_eq(testarray->length, 4);
    ck_assert_str_eq(testarray->strings[0], "Erstes");
    ck_assert_str_eq(testarray->strings[1], "Zweites");
    ck_assert_str_eq(testarray->strings[2], "Viertes");
    ck_assert_str_eq(testarray->strings[3], "Fünftes");






    
