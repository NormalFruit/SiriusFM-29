#pragma once
#include <IRProvider.h>

namespace SiriusFM {
	template<>
	class IRProvider<IRModeE::Const> {
		private:
			double m_IRs[int(CcyE::N)];
		public:
			IRProvider(char const * a_file);
			
			double r(CcyE a_Ccy, double a_) const {
				return m_IRs[int(a_Ccy)];	
			}
	}
}

