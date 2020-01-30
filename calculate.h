#ifndef CALCULATE_H
#define CALCULATE_H

#include "systemc.h"
#include "hls_math.h"
#include "ap_int.h"

SC_MODULE (calculation){
	sc_in_clk clock;
	sc_out<bool>  din_tlast;
	sc_out<bool>  din_tvalid;
	sc_out<sc_uint<128> >  din;
	sc_out<sc_uint<4> > din_words;
	sc_out<sc_uint<4> > dout_words;
	sc_out<sc_uint<32> > ctrl;

	ap_uint<256> data;

	void datagen(){
		while(1){
			wait();
			din_words=11;
			din=0;
			if(data==0)
				break;
			/*for(int i=0;i<128;i++)
				din[i]=0;*/
			for(int i=0;i<(din_words*8);i++){
				int temp=data%2;
				data/=2;
				din=din+(temp*pow(2, i));
			}
		}
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
		din_words=11;
		dout_words=11;
		ctrl=4233465604;
		din=0;
		din_tvalid=1;
		din_tlast=0;
		data=0x56FCEA2B05F4059A53A4C646F952BB13ADD832CA95EE819A76;
		for(int i=0;i<3;i++){
			if(i==2)
				din_tlast=1;
			SC_METHOD(datagen);
			sensitive<<clock.pos();
		}
			//SC_CTHREAD(datagen, clock.pos());
	}
};

#endif
