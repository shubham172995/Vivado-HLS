#include<iostream>

using namespace std;

int PutValue(long long* addr, long long data){
#pragma HLS INTERFACE s_axilite port=addr bundle=CTRLS
#pragma HLS INTERFACE s_axilite port=data bundle=CTRLS
#pragma HLS INTERFACE s_axilite port=return bundle=CTRLS
	//long long *temp=(long long*)(addr);
	*addr=data;
	return 1;
}
