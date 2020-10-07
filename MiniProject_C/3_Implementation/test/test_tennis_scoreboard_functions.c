#include <CUnit/Basic.h>
#include <CUnit/CUnit.h>

/* Modify these two lines according to the project */
#include <tennis_scoreboard_functions.h>
#define PROJECT_NAME    "TENNIS_SCOREBOARD_TRACKER"

/* Prototypes for all the test functions */
void test_print_points(void);
void test_current_game_score(void);
/*void test_multiply(void);
void test_divide(void);*/

/* Start of the application test */
int main() {
/* Note: Do not edit START*/
  /*Initialize and setup the Test Framework */
  if (CUE_SUCCESS != CU_initialize_registry())
    return CU_get_error();
  CU_pSuite suite = CU_add_suite(PROJECT_NAME, 0, 0);
/* Note: Do not edit END */


  /* Add your test functions in this format for testing*/
  CU_add_test(suite, "print_points", test_print_points);
  CU_add_test(suite, "current_game_score", test_current_game_score);
  /*CU_add_test(suite, "multiply", test_multiply);
  CU_add_test(suite, "divide", test_divide);*/


/* Note: Do not edit START*/
  /* Setup Test Framework to output the result to Screen */
  CU_basic_set_mode(CU_BRM_VERBOSE);

  /* run the unit test framework*/
  CU_basic_run_tests();

  /* Cleaning the Resources used by Unit test framework */
  CU_cleanup_registry();
/* Note: Do not edit END */
  return 0;
}

/* Write all the test functions */
void test_print_points(void)
{
    CU_ASSERT(15 == print_points(1));
    CU_ASSERT(30 == print_points(2));
    CU_ASSERT(40 == print_points(3));
}

void test_current_game_score(void)
{
    CU_ASSERT(1 == current_game_score(0,3));
    CU_ASSERT(1 == current_game_score(3,0));
    CU_ASSERT(1 == current_game_score(2,3));
    CU_ASSERT(1 == current_game_score(1,1));
    CU_ASSERT(1 == current_game_score(0,0));
    CU_ASSERT(2 == current_game_score(3,3));
    CU_ASSERT(2 == current_game_score(6,6));
    CU_ASSERT(2 == current_game_score(11,11));
    CU_ASSERT(3 == current_game_score(4,3));
    CU_ASSERT(3 == current_game_score(6,7));
    CU_ASSERT(3 == current_game_score(13,12));
}

