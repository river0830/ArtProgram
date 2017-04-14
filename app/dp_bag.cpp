#include <iostream>
#include <string.h>
#include "assert.h"

using namespace std;

void dp_bag(int n, int v, int *ww, int *vv)
{
    int **value = NULL;

    cout << "****************test dp_bag s******************" << endl;

    printf("the weight array is:");
    for(int i = 0; i < n; i++)
        printf("%d ", ww[i]);

    printf("\r\n");
    printf("the value array is:");
    for(int i = 0; i < n; i++)
        printf("%d ", vv[i]);
    printf("\r\n");

    value = new int*[n];             //n numbers int* pointer
    value[0] = new int[n * (v+1)];
    assert(NULL != value);
    assert(NULL != value[0]);

    memset(value[0], 0, sizeof(4) * (v+1));
    for(int i = 1; i < n; i++) {
        value[i] = value[i-1] + v + 1;
        memset(value[i], 0, sizeof(4) * (v+1));
    }

    //i为价值数组索引
    for(int i = 0; i < n; i++) {
        //j为重量
        for(int j = 0; j <= v; j++) {
            if(i > 0) {
                value [i][j] = value[i-1][j];
                if(j >= ww[i]) {
                    int tmp = value[i-1][j - ww[i]] + vv[i];
                    if(value[i][j] < tmp) value[i][j] = tmp;
                }
            }
            else {
                //数组第一行根据重量条件赋值价值
                if(j >= ww[i]) value[i][j] = vv[i];
            }
        }
    }

    printf("maxvalue is %d, the maxvalue array is:\r\n", value[n-1][v]);
    for(int i = 0; i < n; i++) {
        printf("\r\n");
        for(int j = 0; j < v + 1; j++)
            printf("%2d ", value[i][j]);
    }

    delete [] value[0];
    delete [] value;

    printf("\r\n");
    cout << "****************test dp_bag e******************" << endl;
}


void dp_bag_test()
{
    static int w[4] = {5, 4, 6, 3};
    static int v[4] = {10, 40, 30, 50};

    dp_bag(4, 10, w, v);
}
