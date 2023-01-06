//Perfect Reactangle
class Solution {
 public:
  bool isRectangleCover(vector<vector<int>>& rectangles) {
    int n = rectangles.size();

    if (n == 1) return true;

    map<pair<int, int>, int> m;

    for (auto& rect : rectangles) {
      m[{rect[0], rect[1]}]++;
      m[{rect[2], rect[3]}]++;
      m[{rect[0], rect[3]}]--;
      m[{rect[2], rect[1]}]--;
    }

    int Corner = 0;

    for (auto ite = m.begin(); ite != m.end(); ite++) {
      if (ite->second != 0) {
        if (abs(ite->second) != 1) return false;

        Corner++;
      }
    }

    return Corner == 4;
  }
};