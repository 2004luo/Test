/* 
1.Ŀ�ģ�ʹ����С���˷������ݵ�����������
2.���ߣ����׷�
  ���ڣ�2023��3��8��
  ѧ�ţ�202004060808
3.���룺���������
  �������Ϻ������ʽ
        ���������
*/ 



#include <stdio.h>
#include "time.h"
#include <stdlib.h>
#include <math.h>

int main() //ʵ�ʺ���Ϊ y = x + 1,ͨ����ʵ�ʵ������ʩ�����õ�����������ݵ㣬�����Щ����һ��������� 
{
	int size = 100, size_test = 1000;//���������������Ϊ100�����麯��������������������Ϊ1000 
    float x[size], y[size];//��һ������洢0-100֮�����������ڶ�������洢��һ������ÿ������ĳ�����κ�����ʵ�ʺ���ֵ 
	float x_test[size_test], y_test[size_test]; //��һ������洢0-100֮�����������ڶ�������洢��һ������ÿ������ĳ�����κ�����ʵ�ʺ���ֵ 
    float a, b;//aΪ��Ϻ����Ľؾ࣬bΪ��Ϻ�����б�ʣ� 
	float average_x, average_y, sum_x = 0, sum_y = 0, sum_xy = 0, sum_x2 = 0;
	float error, error_test, error_test_sum = 0.0;
    int i, j;

    srand(time(0));
    for(i=0; i<size; i++) {        
	    x[i] = 0+1.0*(rand()%RAND_MAX)/RAND_MAX *(100-0);//�����[0,100]����һ��xֵ 
	    error = (2.0 * rand() / RAND_MAX - 1.0) * 0.1;//�������10%����� 
	    sum_x = sum_x + x[i];//��x�ĺ� 
	    y[i] = (x[i] + 1) * (1.0 + error);//����ʵ����ֵ������10%��������������һ��С����� 
		sum_y = sum_y + y[i];//��y�ĺ� 
		sum_xy = sum_xy + x[i] * y[i];//��x*y�ĺ� 
		sum_x2 = sum_x2 + x[i] * x[i];//��x^2�ĺ� 
	}
    average_x = sum_x / size;//��x�ľ�ֵ 
    average_y = sum_y / size; //��y�ľ�ֵ 
    b = (sum_xy - size * average_x * average_y) / (sum_x2 - size * average_x * average_x);//��С���˷�����Ϻ���б�� 
    a = average_y - b * average_x;//����Ϊ��Ϻ����ؾ� 
    if(b >= 0) printf("��Ϻ���Ϊ��%fx+%f\n", b, a);
    if(b < 0) printf("��Ϻ���Ϊ��%fx%f", b, a);//�����Ϻ������ʽ 
    //printf("�������xֵ ��Ӧ�������ֵ    ���\n");
    for(i=0; i<size_test; i++) {
        x_test[i] = 0+1.0*(rand()%RAND_MAX)/RAND_MAX *(100-0);
        for(j = 0; j < size; j++) {
        	if(x_test[i] == x[j]) {
        		i--;
        		break;
			    }
            }//��ڶ�����ȡxֵ���һ�β�ͬ 
		y_test[i] = b * x_test[i] + a;
		error_test = fabs(y_test[i] - (x_test[i] + 1));//�����Ϻ�����ʵ�ʺ�������ֵ������ƽ���� 
		error_test_sum = error_test_sum + error_test * error_test;
		//printf(" %f   %f   %f\n" ,x_test[i], y_test[i], error_test);
	    }
	printf("���������Ϊ��%f", sqrt(error_test_sum / size_test));//���������������� 
    return 0;
}

