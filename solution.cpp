#include "solution.h"
#include "util.h"
#include <unordered_set>
#include <numeric>
#include <iterator>
#include <unordered_map>
#include <queue>
#include <string>
#include <sstream>
#include <algorithm>
#include <bitset>
using namespace sol940;
using namespace std;

/*takeaways
  - build the root than the left than the right recurrsively
*/

Node *Solution::_recover(string &S, int &pos, int level)
{

  int cnt = 0, n = S.size();
  /* we should have "level" number of dash
     precedes the node value in the S
     - don't change pos yet as we are just
       testing to see if there is still
       node at this level for this route
 */
  while (pos + cnt < n && S[pos + cnt] == '-')
    cnt++;
  /*
    - 1-2--3--4-5--6--7
    - when you reach 4 you are at level 2
      but following it we just have one dash
      - that means we have reached the bottom
        at this route and no more node needs
        to be recovered
  */
  if (cnt != level)
    return nullptr;
  /* retrieve the node */
  pos = pos + cnt;
  auto val = 0;
  for (; pos < n && isdigit(S[pos]); pos++)
    val = val * 10 + (S[pos] - '0');
  /* pos should be pointing at a '-' if
     we have not reached the end of S
  */

  auto node = new Node(val);
  node->left = _recover(S, pos, level + 1);
  node->right = _recover(S, pos, level + 1);

  return node;
}

Node *Solution::recover(string S)
{
  /* where you are pointing at in S */
  int pos = 0;
  return _recover(S, pos, 0);
}