#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

/**
 * 快速排序的算法可以用三句话描述:
 * [Algo]
 * - 选择基准项(pivot element, 一般取第一个元素为pivot)
 * - 把数组里所有小于pivot的移动到pivot左边, 大于pivot的移动到右边 ⇒
 * - 此时pivot已经位于最终排序时的正确位置
 * - 对pivot左右两个数组分别递归进行快速排序
 *
 * 这里有几点要注意的:
 * - 让j先移动
 * - 最后pivot要和j交换而不是和i交换:
 *   因为最后放在最左边的应该是一个小于pivot的数嘛
 * - 移动的时候别忘了需要加数组下标的边界检查(i<=hi, j>=lo)
 * - partition()的复杂度是线性的O(n)
 */

// quick partition
void swap(int a[], int i, int j) {
  auto t = a[i];
  a[i] = a[j];
  a[j] = t;
}

int partition(int a[], int lo, int hi) {
  int pivot = a[lo], i = lo, j = hi;
  while (true) {
    for (; j >= lo && a[j] >= pivot; --j)
      ;  // move j to point where a[j] < pivot
    for (; i <= hi && a[i] <= pivot; ++i)
      ;                 // move i to a point where a[i] > pivot
    if (i >= j) break;  // break if i and j meets
    swap(a, i++, j--);
  }
  swap(a, lo, j);  // swap pivot with a[j]
  return j;
}

// knuth shuffle
/**
 * for(k=1 to n): 每次把第k个元素和前k个元素中的随机一个元素交换.
 */
void shuffle(vector<int> a) {
  for (size_t k = 0; k < a.size(); ++k) {
    swap(a[k], a[rand() % (k + 1)]);
  }
}

// qick sort

void qsort(int a[], int lo, int hi) {
  if (lo <= hi) return;

  auto p = partition(a, lo, hi);
  qsort(a, lo, p - 1);
  qsort(a, p + 1, hi);
}

void qsort(vector<int> a) {
  shuffle(a);
  int arr[100];
  copy(a.begin(), a.end(), arr);

  qsort(arr, 0, a.size() - 1);
}

// quick select

int findKth(int a[], int k) {
  int lo = 0, hi = 100;  // a.size();
  while (lo < hi) {
    auto p = partition(a, lo, hi);
    if (p == k)
      return a[k];
    else if (p < k)
      lo = p + 1;
    else
      hi = p - 1;
  }
  return a[k];
}

// 3-way qsort
/**
 * qsort之前有个bug: 在数组里很多重复元素的时候, 效率会下降为O(N2).
 * 原因是qsort没有好好处理重复元素的问题.
 *
 * 于是Dijkstra提出了一个3-way partition的算法: 把数组分为三部分:
 * 左边[lo, lt)严格小于pivot, 中间[lt, gt]等于pivot, 右边(gt, hi]严格大于pivot.
 *
 * 算法初始化lt=lo, gt=hi, i=lo, 用指针i向右扫描, [i,gt]为未处理到的部分.
 * 算法很subtle, invariant是这样的:
 * - a[lo,lt-1] < pivot
 * - a[lt, i-1] = pivot
 * - a[i,gt] = unseen
 * - a[gt+1, hi] > pivot
 */
void qsort3way(int a[], int lo, int hi) {
  if (hi <= lo) return;
  int lt = lo, i = lo, gt = hi, pivot = a[lo];
  while (i < gt) {      //[i, gt] is unseen elements
    if (a[i] == pivot)  // a[lt, i-1] are elements == pivot
      i++;
    else if (a[i] > pivot)  // a[gt+1, hi] are elements > pivot
      swap(a, gt--, i);
    else  // a[lo, lt-1] are elements < pivot
      swap(a, lt++, i++);
  }

  qsort3way(a, lo, lt - 1);
  qsort3way(a, gt + 1, hi);
}
