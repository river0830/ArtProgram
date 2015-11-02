#include <iostream>
#include <assert.h>

using namespace std;

//�������Ԫ��,��2��Ԫ�س���������,����Ԫ�س���ż����
//������������
void find_2_appear_once_number(const int *data, unsigned int len)
{
    assert((data != NULL) && (len >= 2));  //if false assert

    cout << "find_2_appear_once number function is run!" << endl;

    int xor_all = 0;

    for(unsigned int i = 0; i < len; i++)
    {
        xor_all ^= data[i];
    }

    //Ѱ��xor_all�е�һ����Ϊ0��bit, ���Խ����黮��Ϊ2��
    //��Ȼa��b�ڲ�ͬ�Ŀ�
    const int xor_flag = xor_all & (~(unsigned int)xor_all + 1);

    int xor_a = 0;
    for(unsigned int i = 0; i < len; i++)
    {
        if(xor_flag & data[i])
            xor_a ^= data[i];
    }

    cout << "xor_a is " << xor_a << endl;

    int xor_b = xor_all ^ xor_a;

    cout << "xor_b is " << xor_b << endl;
}


void test_find_once_number(void)
{
    const int data[8] = {2, 3, 4, 2, 4, 5, 2, 3};

    cout << "**********************************" << endl;
    find_2_appear_once_number(data, 8);
    cout << "**********************************" << endl;
}

