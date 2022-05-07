#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <unordered_map>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol940;

/*
Input: "1-2--3--4-5--6--7"
Output: [1,2,5,3,4,6,7]
*/

tuple<string> testFixture1()
{
  return make_tuple("1-2--3--4-5--6--7");
}

/*
Input: "1-2--3---4-5--6---7"
Output: [1,2,5,3,null,6,null,4,null,7]
*/
tuple<string> testFixture2()
{
  return make_tuple("1-2--3---4-5--6---7");
}

void test1()
{
  auto f = testFixture1();
  Solution sol;
  auto tree = sol.recover(get<0>(f));

  cout << "Expect to see 3:" << tree->left->left->val << endl;
  cout << "Expect to see 7:" << tree->right->right->val << endl;
}

void test2()
{
  auto f = testFixture2();
  Solution sol;
  auto tree = sol.recover(get<0>(f));

  cout << "Expect to see 3:" << tree->left->left->val << endl;
  cout << "Expect to see 6:" << tree->right->left->val << endl;
}

main()
{
  test1();
  test2();
  return 0;
}