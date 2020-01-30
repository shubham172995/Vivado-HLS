#ifndef CALCULATE_H
#define CALCULATE_H

#include "systemc.h"
#include "hls_math.h"
#include "stdlib.h"
#include <string>
//#include <sstream>


SC_MODULE (calculation){
	sc_in_clk clock;
	sc_out<bool>  din_tlast;
	sc_out<bool>  din_tvalid;
	sc_out<sc_uint<128> >  din;
	sc_out<sc_uint<4> > din_words;
	sc_out<sc_uint<4> > dout_words;
	sc_out<sc_uint<32> > ctrl;

	std::string data;
	sc_uint<128> dat;
	sc_uint<4> width;

	void datagen(){
		//while(1){
			//wait();
			//din_words=11;
			//din=0;
			width=10;
			std::string t;
			dat=0x0;
			int l=data.length();
			/*if(data.length()==0)
				break;*/
			/*for(int i=0;i<128;i++)
				din[i]=0;*/

			if(l>=20){
				t=data.substr(l-20, 20);
				data=data.substr(0, l-20);
			}
			else{
				t=data.substr(0, l);
				data="";
			}
			/*for(int i=t.length();i>=0;i--){
				int temp=t[i]-'0';
				dat=(dat+(temp*pow(2, i)));
			}*/
			//std::stringstream str;
			//str<<t;
			//str>>std::hex>>dat;
			dat=strtol (t.c_str(),NULL,16);
			din.write(dat);
		//}
	}

	SC_CTOR(calculation)
	:din("din"),
	 ctrl("ctrl"),
	 din_words("din_words"),
	 dout_words("dout_words"),
	 clock("clock"),
	 din_tlast("din_tlast"),
	 din_tvalid("din_tvalid")
	{
		din_words.write(11);
		dout_words.write(11);
		ctrl.write(0x048F55FC);
		din.write(0);
		din_tvalid.write(1);
		din_tlast.write(0);
		data="56FCEA2B05F4059A53A4C646F952BB13ADD832CA95EE819A76";
		for(int i=0;i<3;i++){
			if(i==2)
				din_tlast.write(1);
			SC_METHOD(datagen);
			//sensitive<<clock.pos();
		}
			//SC_CTHREAD(datagen, clock.pos());
	}
};

#endif
