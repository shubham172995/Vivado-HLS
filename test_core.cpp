#include <iostream>
#include <string>
#include "ap_int.h"

using namespace std;

int PutValue(long long* addr, long long data);

int main(){
	long long* s[75];
	s[0]=reinterpret_cast<long long*>(0x00000);	s[1]=reinterpret_cast<long long*>(0x00004);
	s[2]=reinterpret_cast<long long*>(0x00010);	s[3]=reinterpret_cast<long long*>(0x0000C);
	s[4]=reinterpret_cast<long long*>(0x00020);	s[5]=reinterpret_cast<long long*>(0x02048);
	s[6]=reinterpret_cast<long long*>(0x0204C);	s[7]=reinterpret_cast<long long*>(0x02040);
	s[8]=reinterpret_cast<long long*>(0x100E0);	s[9]=reinterpret_cast<long long*>(0x100E4);
	s[10]=reinterpret_cast<long long*>(0x100E8);	s[11]=reinterpret_cast<long long*>(0x100EC);
	s[12]=reinterpret_cast<long long*>(0x100F0);	s[13]=reinterpret_cast<long long*>(0x100F4);
	s[14]=reinterpret_cast<long long*>(0x100F8);	s[15]=reinterpret_cast<long long*>(0x100FC);
	s[16]=reinterpret_cast<long long*>(0x10100);	s[17]=reinterpret_cast<long long*>(0x10104);
	s[18]=reinterpret_cast<long long*>(0x10108);	s[19]=reinterpret_cast<long long*>(0x1010C);
	s[20]=reinterpret_cast<long long*>(0x10110);	s[21]=reinterpret_cast<long long*>(0x10114);
	s[22]=reinterpret_cast<long long*>(0x10118);	s[23]=reinterpret_cast<long long*>(0x1011C);
	s[24]=reinterpret_cast<long long*>(0x10120);	s[25]=reinterpret_cast<long long*>(0x10124);
	s[26]=reinterpret_cast<long long*>(0x10128);	s[27]=reinterpret_cast<long long*>(0x1012C);
	s[28]=reinterpret_cast<long long*>(0x10130);	s[29]=reinterpret_cast<long long*>(0x10134);
	s[30]=reinterpret_cast<long long*>(0x10138);	s[31]=reinterpret_cast<long long*>(0x1013C);
	s[32]=reinterpret_cast<long long*>(0x10140);	s[33]=reinterpret_cast<long long*>(0x10144);
	s[34]=reinterpret_cast<long long*>(0x10148);	s[35]=reinterpret_cast<long long*>(0x1014C);
	s[36]=reinterpret_cast<long long*>(0x10150);	s[37]=reinterpret_cast<long long*>(0x10154);
	s[38]=reinterpret_cast<long long*>(0x10158);	s[39]=reinterpret_cast<long long*>(0x1015C);
	s[40]=reinterpret_cast<long long*>(0x10160);	s[41]=reinterpret_cast<long long*>(0x10164);
	s[42]=reinterpret_cast<long long*>(0x10168);	s[43]=reinterpret_cast<long long*>(0x1016C);
	s[44]=reinterpret_cast<long long*>(0x10170);	s[45]=reinterpret_cast<long long*>(0x10174);
	s[46]=reinterpret_cast<long long*>(0x10178);	s[47]=reinterpret_cast<long long*>(0x1017C);
	s[48]=reinterpret_cast<long long*>(0x10180);	s[49]=reinterpret_cast<long long*>(0x10184);
	s[50]=reinterpret_cast<long long*>(0x10188);	s[51]=reinterpret_cast<long long*>(0x1018C);
	s[52]=reinterpret_cast<long long*>(0x10190);	s[53]=reinterpret_cast<long long*>(0x10194);
	s[54]=reinterpret_cast<long long*>(0x10198);	s[55]=reinterpret_cast<long long*>(0x1019C);
	s[56]=reinterpret_cast<long long*>(0x101A0);	s[57]=reinterpret_cast<long long*>(0x101A4);
	s[58]=reinterpret_cast<long long*>(0x101A8);	s[59]=reinterpret_cast<long long*>(0x101AC);
	s[60]=reinterpret_cast<long long*>(0x101B0);	s[61]=reinterpret_cast<long long*>(0x101B4);
	s[62]=reinterpret_cast<long long*>(0x101B8);	s[63]=reinterpret_cast<long long*>(0x101BC);
	s[64]=reinterpret_cast<long long*>(0x101C0);	s[65]=reinterpret_cast<long long*>(0x101C4);
	s[66]=reinterpret_cast<long long*>(0x101C8);	s[67]=reinterpret_cast<long long*>(0x101CC);
	s[68]=reinterpret_cast<long long*>(0x101D0);	s[69]=reinterpret_cast<long long*>(0x101D4);
	s[70]=reinterpret_cast<long long*>(0x101D8);	s[71]=reinterpret_cast<long long*>(0x00010);
	s[72]=reinterpret_cast<long long*>(0x00004);	s[73]=reinterpret_cast<long long*>(0x101D4);
	s[74]=reinterpret_cast<long long*>(0x00000);
	long long d[75];
	d[0]=0x00000000;	d[1]=0x00000000;
	d[2]=0x00000000;	d[3]=0x00000000;
	d[4]=0x0000007F;	d[5]=0x00000002;
	d[6]=0x00000007;	d[7]=0x00C80400;
	d[8]=0x00000000;	d[9]=0x00000000;
	d[10]=0x00000000;	d[11]=0x00000000;
	d[12]=0x00000000;	d[13]=0x00000000;
	d[14]=0x00000000;	d[15]=0x00000000;
	d[16]=0x00000000;	d[17]=0x00000000;
	d[18]=0x00000000;	d[19]=0x00000000;
	d[20]=0x00000000;	d[21]=0x00000000;
	d[22]=0x00000000;	d[23]=0x00000000;
	d[24]=0x00000000;	d[25]=0x00000000;
	d[26]=0x00000000;	d[27]=0x00000000;
	d[28]=0x00000000;	d[29]=0x00000000;
	d[30]=0x00020000;	d[31]=0x00002002;
	d[32]=0x00000000;	d[33]=0x00000000;
	d[34]=0x00000000;	d[35]=0x00000000;
	d[36]=0x00000000;	d[37]=0x00000000;
	d[38]=0x00002000;	d[39]=0x00002000;
	d[40]=0x00000000;	d[41]=0x22280000;
	d[42]=0x20008A00;	d[43]=0x00000800;
	d[44]=0x00000000;	d[45]=0x00200000;
	d[46]=0xA0000000;	d[47]=0x88020000;
	d[48]=0xA2080200;	d[49]=0x02082008;
	d[50]=0x02002000;	d[51]=0xA0880000;
	d[52]=0x0A008208;	d[53]=0x2A008002;
	d[54]=0x02200088;	d[55]=0x88288820;
	d[56]=0x2822008A;	d[57]=0x828A000A;
	d[58]=0xA088A200;	d[59]=0x80A20228;
	d[60]=0x8880A082;	d[61]=0xA82220AA;
	d[62]=0x82A20822;	d[63]=0x82A8A0AA;
	d[64]=0x22222AA2;	d[65]=0xA0A2A8AA;
	d[66]=0xA8AAA282;	d[67]=0xAA8AA28A;
	d[68]=0x8AAA8A22;	d[69]=0xAAA82AAA;
	d[70]=0x55156AAA;	d[71]=0x55555555;
	d[72]=0x00000001;	d[73]=0x0000003F;
	d[74]=0x00000001;
	for(int i=46;i<75;i++){
		int ans=PutValue(s[i], d[i]);
		cout<<"Hey, "<<ans<<endl;
	}
	return 0;
}

