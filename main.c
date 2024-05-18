#include "libs/strings/string/string_.h"
#include <malloc.h>
#include "libs/data_structures/vector/vectorVoid.h"
#include <assert.h>

#define ASSERT_STRING(expected, got) assertString(expected, got, \
__FILE__, __FUNCTION__, __LINE__)
typedef struct TreeItem {
    int level;
    int value;
    int type;
    int idx;
} TreeItem;

void maxThreeImpl(int *nums, int level, int start, int end, int type, int *idx, vectorVoid *res) {
    (*idx)++;
    if (end < start) {
        TreeItem t = {level, -1, type, *idx};
        pushBackV(res, &t);
        return;
    }
    if (end == start) {
        TreeItem t = {level, nums[end], type, *idx};
        pushBackV(res, &t);
        return;
    }
    int max = INT_MIN;
    int maxIdx;
    for (int i = start; i <= end; i++) {
        if (max < nums[i]) {
            max = nums[i];
            maxIdx = i;
        }
    }
    TreeItem t = {level, max, type, *idx};
    pushBackV(res, &t);
    maxThreeImpl(nums, level + 1, start, maxIdx - 1, 1, idx, res);
    maxThreeImpl(nums, level + 1, maxIdx + 1, end, 2, idx, res);
}

int compareTreeItemByLevel(const void *treeItemPtr1, const void *treeItemPtr2) {
    TreeItem *treeItem1 = (TreeItem *) treeItemPtr1;
    TreeItem *treeItem2 = (TreeItem *) treeItemPtr2;
    int diffLevel = treeItem1->level - treeItem2->level;
    if (diffLevel == 0) {
        return treeItem1->idx - treeItem2->idx;
    }
    return diffLevel;
}

vectorVoid maxThree(int *nums, int len) {
    vectorVoid res = createVectorV(5, sizeof(TreeItem));
    int idx = 0;
    maxThreeImpl(nums, 0, 0, len - 1, 0, &idx, &res);
    qsort(res.data, res.size, sizeof(TreeItem), compareTreeItemByLevel);
    return res;
}

void test() {
    int nums[6] = {3, 2, 1, 6, 0, 5};
    vectorVoid res = maxThree(nums, sizeof(nums) / sizeof(int));
    for (int i = 0; i < res.size; i++) {
        TreeItem t;
        getVectorValueV(&res, i, &t);
        printf("%d:%d:%d\n", t.level, t.value, t.idx);
    }
    int test[9] = {6, 3, 5, -1, 2, 0, -1, -1, 1};
    assert(sizeof(test) / sizeof(int) == res.size);
    for (int i = 0; i < res.size; i++) {
        TreeItem treeItem;
        getVectorValueV(&res, i, &treeItem);
        assert(test[i] == treeItem.value);
    }
}


int main() {
    test();
}