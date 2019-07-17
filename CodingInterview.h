//
// Created by xh on 2019/7/16.
//
#include <unordered_map>

#ifndef ALGORITHM_CODINGINTERVIEW_H
#define ALGORITHM_CODINGINTERVIEW_H

int getCount(const vector<int> &arr, int middle, int start) {
  int c = 0;
  for(auto item: arr) {
    if(item <= middle && item >= start)
      c++;
  }
  return c;
};
class CodingInterview {
public:
  // 不存在则返回-1  hashtable
  static int getDuplicateNumberInArray(vector<int> arr) {
    std::unordered_map<int, int> m;
    for (auto i = arr.begin(); i != arr.end(); i++) {
      if (!m.insert(std::make_pair(*i, 1)).second) {
        return *i;
      }
    }
    return -1;
  }

  static int getDuplicateNumberInArrayNoEdit(const vector<int>& arr) {
    if(arr.empty()) return -1;
    int start = 1;
    int end = arr.size();

    while (start <= end) {
      int middle = start+ (end-start)/2 ;
      // 判断某数字范围的所有数字在原数组的出现次数
      int count = getCount(arr, middle, start);
      if(start == end) {
        if(count>1) return start;
        else return -1;
      }
      if(count > (middle - start + 1)) {
        // 不能减一，因为middle处的值还会被用到，
        // 比如1,2,3,4,5,中间值是3，我要重复值是3，则需要更新end，如果end=mid-1，那么3不就丢失了
        // start需要=mid+1，第一是因为end和start必须要有一个是mid-/+1才行，否则会死循环，第二是因为start确实需要加1，不然用不到的元素就会被包含进来
        end = middle;
      } else {
        start = middle + 1 ; // 要加一
      }
    }
    return -1;
  }
};

#endif //ALGORITHM_CODINGINTERVIEW_H