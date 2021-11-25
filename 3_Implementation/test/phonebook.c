#include"phonebook.h"
#include"unity_internals.h"
#include"unity.h"

void setUp(){}

void tearDown(){}


void insert_to_phonebook_linkedlist((void){
    TEST_ASSERT_EQUAL(pass,insert());
}

void list_phonebook_linkedlist(void){
    TEST_ASSERT_EQUAL(pass,list entries());
}

void delete_phonebook_linkedlist(void){
    TEST_ASSERT_EQUAL(pass,Delete entry());
}


int main(){
    UNITY_BEGIN();

    RUN_TEST(insert_to_phonebook_linkedlist);
    RUN_TEST(list_phonebook_linkedlist);
    RUN_TEST(delete_phonebook_linkedlist);

    
    return UNITY_END();
}
