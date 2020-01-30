#ifndef CALCULATE_H
#define CALCULATE_H

#include "systemc.h"
#include "hls_math.h"
#include <string>


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
		while(1){
			wait();
			//din_words=11;
			//din=0;
			width=11;
			if(data.length()==0)
				break;
			/*for(int i=0;i<128;i++)
				din[i]=0;*/
			for(int i=0;i<width*8;i++){
				int l=data.length();
				int temp=data[l-1]-'0';
				data=data.substr(0, l-1);
				dat=(dat+(temp*pow(2, i)));
			}
			din.write(dat);
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
		din_words.write(11);
		dout_words.write(11);
		ctrl.write(0x048F55FC);
		din.write(0);
		din_tvalid.write(1);
		din_tlast.write(0);
		data="1010110111111001110101000101011000001011111010000000101100110100101001110100100110001100100011011111001010100101011101100010011101011011101100000110010110010101001010111101110100000011001101001110110";
		for(int i=0;i<3;i++){
			if(i==2)
				din_tlast.write(1);
			SC_CTHREAD(datagen, clock.pos());
			//sensitive<<clock.pos();
		}
			//SC_CTHREAD(datagen, clock.pos());
	}
};

#endif
