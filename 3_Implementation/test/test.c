#include "unity.h"
#include "remword.h"
/* Required by the unity test framework */
void setUp(){}
/* Required by the unity test framework */
void tearDown(){}

void test_enterchoice(void)
{
  TEST_ASSERT_EQUAL(2,enterchoice(2));
}

int test_main(void)
{
/* Initiate the Unity Test Framework */
  UNITY_BEGIN();

/* Run Test functions */
  RUN_TEST(test_enterchoice);
 return UNITY_END();
}
