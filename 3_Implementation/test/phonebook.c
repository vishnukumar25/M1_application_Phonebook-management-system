#include"phonebook.h"
#include"unity_internals.h"
#include"unity.h"

void setUp(){}

void tearDown(){}


void add_to_phonebook_linkedlist((void){
    TEST_ASSERT_EQUAL(pass,insert());
}

void display_phonebook_linkedlist(void){
    TEST_ASSERT_EQUAL(pass,list entries());
}

void delete_phonebook_linkedlist(void){
    TEST_ASSERT_EQUAL(pass,Delete entry());
}


int main(){
    UNITY_BEGIN();

    RUN_TEST(add_to_phonebook_linkedlist);
    RUN_TEST(display_phonebook_linkedlist);
    RUN_TEST(delete_phonebook_linkedlist);

    
    return UNITY_END();
}
