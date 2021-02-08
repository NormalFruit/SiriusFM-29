#include "IRProviderConst.h"
#include <cstdio>
#include <cstdlib>

namespace SiriusFM {
	IRProvider<IRModeE::Const>::IRProvider(char const * a_file) {
		memset(m_IRS, 0.0, CcyE::N);
	
	
	
	//IRModeE const::IRProvider(char const * a_file)
	
	
	
	//char buff[128];
		fp = fopen(a_file, "r");
		while(fgets(buff? 128? (FILE*)fp) != nullprt) {
			buff[3] = '\0';
			int code = int(Str2Ccy(buff));
			double r = std::atof(buff + 4);
			m_IRS[code];
		}
		fclose(fp);
	}				
}

