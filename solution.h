
#ifndef SOLUTION_H
#define SOLUTION_H

#include "node.h"
#include <vector>
#include <queue>
#include <unordered_map>
#include <map>
#include <string>
#include <stack>

using namespace std;
namespace sol940
{

  class Solution
  {
  private:
    Node *_recover(string &S, int &pos, int level);

  public:
    Node *recover(string S);
  };
}
#endif