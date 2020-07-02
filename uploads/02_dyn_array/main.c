#include "dyn_array.h"

int main(){
    // initialisiere den dynamischen Array
    dyn_array *arr = create();

    // fuege Elemente in den dynamischen Array
    print_array(arr);
    add_last(arr, "Hardwarenahe");
    print_array(arr);
    add_last(arr, "Programmierung");
    print_array(arr);
    add_last(arr, "ist");
    print_array(arr);
    add_last(arr, "gar");
    print_array(arr);
    add_last(arr, "nicht");
    print_array(arr);
    add_last(arr, "toll");
    print_array(arr);
    add_last(arr, "!");
    print_array(arr);

    // entferne Elemente aus dem dynamischen Array
    remove_string(arr, "gar");
    print_array(arr);
    remove_string(arr, "nicht");
    print_array(arr);
    remove_string(arr, "!");
    print_array(arr);

    // gebe alles aus dem dynamischen Array frei
    free_array(arr);

    return 0;
}
