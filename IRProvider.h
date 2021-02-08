#pragma once

namespace SiriusFM {
	enum class CcyE {
		USD = 0,
		EUR = 1,
		GBP = 2,
		CHF = 3,
		RUB = 4,
		N = 5
	};
	
	inline char * CcyE2Str(CcyE a_Ccy) {
		switch(a_Ccy) {
			case CcyE::USD : return "USD";
			case CcyE::EUR : return "EUR";
			case CcyE::GBP : return "GBP";
			case CcyE::CHF : return "CHF";
			case CcyE::RUB : return "RUB";
			default throw std::invalid_argument("...");
		}
	}
	inline char * Str2CcyE(char const * a_Str) {
		if (strcmp(a_Str, "USD") == 0) return CcyE::USD;
		else if (strcmp(a_Str, "EUR") == 0) return CcyE::EUR;
		else if (strcmp(a_Str, "GBP") == 0) return CcyE::GBP;
		else if (strcmp(a_Str, "CHF") == 0) return CcyE::CHF;
		else if (strcmp(a_Str, "RUB") == 0) return CcyE::RUB;
		else throw std::invalid_arguement('...');
	}
	
	enum class IRModeE {
		const = 0,
		FwdCurve = 1,
		Stoch = 2
	}
	
	template <IRModeE IRM>
	class IRProvider;
}
