#include <iostream>
#include <string.h>
#include <vector>

#include "assert.h"

using namespace std;

void dp_bag(int n, int v, int *ww, int *vv)
{
    int **value = NULL;
    int i, j;

    cout << "****************test dp_bag s******************" << endl;

    printf("the weight array is:");
    for(i = 0; i < n; i++)
        printf("%d ", ww[i]);

    printf("\r\n");
    printf("the value array is:");
    for(i = 0; i < n; i++)
        printf("%d ", vv[i]);
    printf("\r\n");

    value = new int*[n];             //n numbers int* pointer
    value[0] = new int[n * (v+1)];
    assert(NULL != value);
    assert(NULL != value[0]);

    memset(value[0], 0, sizeof(int) * (v+1));
    for(i = 1; i < n; i++) {
        value[i] = value[i-1] + v + 1;
        memset(value[i], 0, sizeof(int) * (v+1));
    }

    //i为价值数组索引
    for(i = 0; i < n; i++) {
        //j为重量
        for(j = 0; j <= v; j++) {
            if(i > 0) {
                value [i][j] = value[i-1][j];
                if(j >= ww[i]) {
                    int tmp = value[i-1][j - ww[i]] + vv[i];
                    if(value[i][j] < tmp) {
                        value[i][j] = tmp;
                    }
                }
            }
            else {
                //数组第一行根据重量条件赋值价值
                if(j >= ww[i]) value[i][j] = vv[i];
            }
        }
    }

    printf("maxvalue is %d, the maxvalue array is:\r\n", value[n-1][v]);
    for(i = 0; i < n; i++) {
        printf("\r\n");
        for(j = 0; j < v + 1; j++)
            printf("%2d ", value[i][j]);
    }

    printf("\r\n");

    i = n - 1; j = v;
    while(i > 0) {
        if(value[i-1][j - ww[i]] + vv[i] == value[i][j]) {
            printf("$$select No.%d value:%d | ", i, vv[i]);
            j -= ww[i];
        }
        i--;
    }
    printf("\r\n");

    delete [] value[0];
    delete [] value;

    printf("\r\n");
    cout << "****************test dp_bag e******************" << endl;
}

void dp_bag1(int n, int v, int *ww, int *vv)
{
    int *value = NULL;
    int **path = NULL;
    int i, j;

    cout << "****************test dp_bag1 s******************" << endl;

    printf("the weight array is:");
    for(i = 0; i < n; i++)
        printf("%d ", ww[i]);

    printf("\r\n");
    printf("the value array is:");
    for(i = 0; i < n; i++)
        printf("%d ", vv[i]);
    printf("\r\n");

    value = new int[n * (v+1)];
    assert(NULL != value);
    memset(value, 0, sizeof(int) * (v+1));

    path = new int*[n];             //n numbers int* pointer
    path[0] = new int[n * (v+1)];
    assert(NULL != path);
    assert(NULL != path[0]);

    memset(path[0], 0, sizeof(4) * (v+1));
    for(i = 1; i < n; i++) {
        path[i] = path[i-1] + v + 1;
        memset(path[i], 0, sizeof(4) * (v+1));
    }

    //i为价值数组索引
    for(i = 0; i < n; i++) {
        //j为重量
        for(j = v; j >= ww[i]; j--) {
            int tmp = value[j-ww[i]] + vv[i];

            if(value[j] < tmp) {
                value[j] = tmp;
                path[i][j] = 1;
            }
        }
    }

    printf("maxvalue is %d, the maxvalue array is:\r\n", value[v]);
    for(j = 0; j < v + 1; j++) {
        printf("%2d ", value[j]);
    }

    printf("\r\n");
    i = n - 1; j = v;
    while(i > 0 && j > 0) {
        if(path[i][j] == 1) {
            printf("$select No.%d value:%d | ", i, vv[i]);
            j -= ww[i];
        }
        i--;
    }

    printf("\r\n");
    delete [] value;
    delete [] path[0];
    delete [] path;

    printf("\r\n");
    cout << "****************test dp_bag e******************" << endl;
}

void dp_bag2(vector<int> &v)
{
    cout << "****************test dp_bag2 s******************" << endl;

    srand(100);

    int sum = 0, bsum, i, j;
    int len = v.size();

    if(len < 2) return;

    for(vector<int>::iterator iter = v.begin(); iter != v.end(); ++iter) {
        sum += *iter;
        cout << *iter << " ";
    }
    cout << endl;

    bsum = sum;
    sum = sum/2 + 1;

    vector<int> bag(sum + 1, 0);
    vector<vector<int> > path(len);
    for(i = 0; i < len; i++)
        path[i].resize(sum + 1, 0);

    for(i = 0; i < len; i++) {
        for(j = sum; j >= v[i]; j--) {
            if(bag[j] < bag[j - v[i]] + v[i]) {
                bag[j] = bag[j - v[i]] + v[i];
                path[i][j] = 1;
            }
        }
    }

    cout << "array sum is " << bsum << endl;
    cout << "array half sum is " << sum << endl;
    cout << "the first array sum is " << bag[sum] << endl;
    cout << "the second array sum is " << bsum - bag[sum] << endl;

    i = len - 1;
    j = sum;
    while(i > 0) {
        if(path[i][j] == 1) {
            cout << "select array item " << i << " " << v[i] << endl;
            j -= v[i];
        }
        i--;
    }

    cout << "****************test dp_bagw e******************" << endl;
}


void dp_bag_test()
{
    static int w[8] = {5, 4, 6, 3, 2, 2, 2, 2};
    static int v[8] = {10, 40, 30, 500, 60, 20, 70, 900};

    dp_bag(8, 10, w, v);
    dp_bag1(8, 10, w, v);

    vector<int> ar(v, v+8);
    dp_bag2(ar);
}
