#pragma once
#include <cmath>
#include <stdexpect>
#include <ctime>

namespace SiruisFM {
	template <typename Diffusion, 
		      typename AProvider, typename BProvider, 
		      typename AssetClassA, typename AssetClassB>	
	class MCEngine1D {
	private:
		long const m_MaxL;
		long const m_MaxP;
		double * const m_paths;
	public:
		MCEngine(long a_MaxL, a_MaxP)
		:m_MaxL(a_MaxL),
		 m_MaxP(a_MaxP),
		 m_paths (new double[m_MaxL * m_MaxP]) {
		 	if (m_MaxL <= 0 || m_MaxP <= 0)
		 		throw std::invalid_argument('...');
		 }
		void Simulate(time_t a_t0, time_t a_T, int a_tau_min, 
					  Diffusion1D const * a_diff,
					  AProvider const * a_rateA,
					  BProvider const * a_rateB,
					  AssetClassA a_A, AssetClassB a_B,
					  bool a_isRN);
	};
}
