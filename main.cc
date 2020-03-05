/*
 * Empty C++ Application
 */

#include <iostream>
#include "xparameters.h"
#include "xpolar.h"

u32 USER_DEFINED_BA_TABLE[128] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
								  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2,
								  0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2, 0, 2, 2, 2,
								  0, 0, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
								  0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 2, 2, 2, 2, 2, 2,
								  0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
								  0, 2, 2, 2, 2, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1,
								  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1
};

int main()
{
	xpolar_polar_parameters polar_params;
	polar_params.N=128;
	polar_params.K=50;
	polar_params.AUGMENT = AUGMENT_CRC;
	polar_params.CRC_SEL = CRC_SEL_24c;
	u32 compressed_length = polar_params.N / 16;
	u32 compressed_BA_TABLE[compressed_length];
	xpolar_compress_bit_allocation_table(USER_DEFINED_BA_TABLE, compressed_BA_TABLE,
	compressed_length);
	for (int i = 0; i < compressed_length; i++) {
		polar_params.BA_TABLE[i] = compressed_BA_TABLE[i];
	}
	xpolar_Config* polar_cfg;
	xpolar polar;
	int	status;
	polar_cfg = xpolar_LookupConfig(XPAR_XPOLAR_0_DEVICE_ID);
	if (!polar_cfg) {
		std::cout << "ERROR: Could not lookup Polar" << std::endl;
		return 1;
	}
	else
		std::cout << "LOOKUP CONFIG DONE!!" << std::endl;
	status = xpolar_CfgInitialize(&polar, polar_cfg);
	if(status!=XST_SUCCESS){
		std::cout<<"ERROR: Could not initialize Polar"<<std::endl;
		return 1;
	}
	else
		std::cout << "INITIALIZED POLAR!!" << std::endl;
	xpolar_add_polar_params(&polar, &polar_params);


	xpolar_set_CORE_AXI_WR_PROTECT(&polar, 0);
	xpolar_set_CORE_CODE_WR_PROTECT(&polar, 0);
	xpolar_set_CORE_AXIS_WIDTH(&polar, 0);
	xpolar_set_CORE_AXIS_ENABLE(&polar, 63);
	if(xpolar_get_CORE_AXIS_ENABLE(&polar))
		std::cout<<"AXIS ENABLED\n";
	else if(!xpolar_get_CORE_AXIS_ENABLE(&polar))
		std::cout<<"AXIS NOT ENABLED\n";
	xpolar_set_CORE_ISR(&polar, 127);
	xpolar_set_CORE_IER(&polar, 0x7FF);
	xpolar_set_CORE_IDR(&polar, 0);
	xpolar_set_CORE_ECC_ISR(&polar, 4095);
	xpolar_set_CORE_ECC_IER(&polar, 4095);
	xpolar_set_CORE_ECC_IDR(&polar, 0);



	return 0;
}
