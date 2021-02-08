#pragma once
#include "MCEnging1D.h"
#include <cassert>
#include <random>
#include <cmath>

namespace SiruisFM {
	<typename Diffusion, 
	 typename AProvider, 
	 typename BProvider, 
	 typename AssetClassA, 
	 typename AssetClassB>
	 
	inline void MCEngine1D <Diffusion, 
		  		 Provider, BProvider, 
		   		 AssetClassA, AssetClassB>
	::Simulate(time_t a_t0, time_t a_T, int a_tau_min, long a_P, double a_s0, 
					  Diffusion1D const * a_diff,
					  AProvider const * a_rateA,
					  BProvider const * a_rateB,
					  AssetClassA a_A, AssetClassB a_B,
					  bool a_isRN)
					  
		for (long p = 0; p < a_P; ++p) {
			double * path0 = m_paths + 2 * p * L;
			double * path1 = path0 + L;
			path0[0] = a_s0;
			path1[0] = a_s0;
			double y = y0;
			double sp0 = a_s0;
			double sp1 = a_s0;
			for (long l = 1; l < L; ++l) {
				double mu0 = 0.0;
				double mu1 = 0.0;
				if (a_isRN) {
					double delta_r = a_rateB->r(a_B, y)...
					
					mu0 = delta_r * sp0;
					mu1 = delta_r * sp1;
				} else {
					mu0 = a_diff->mu(sp0, y);
					mu1 = a_diff->mu(sp1, y);
				}
				double sigma0 = a_diff->sigma(sp0, y);
				double sigma1 = a_diff->sigma(sp0, y);
				double Z = N01(U);
				double sn0, sn1;
				if (l = L - 1) {
					double sn0 = sp0 + mu0 * tlast + sigma0 * Z * slast;
					double sn1 = sp1 + mu1 * tlast - sigma1 * Z * slast;
					y += tlast;
				} else {
					sn0 = sp0 + mu0 * tau + sigma0 * Z * stau;
					sn1 = sp1 + mu1 * tau - sigma1 * Z * stau;
					y += tau;
				}
				path0[l] = sn0;
				path1[l] = sn1;
				sp0 = sn0;
				sp1 = sn1;
			}
		}
	
	assert(a_diff != nullptr && a_rateA != nullptr && a_rateB != nullptr && 
		   a_A != AssetClass::UNDEFINED && a_t0 <= a_T && a_P > 0 && 
		   a_tau_min > 0);
		   
	double y0 = YearFrac(a_t0);
	double yT = YearFrac(a_T);
	double tau = double(a_tau_min)/(365.25 * 1440.0);
	long L = long ceil((yT - y0)/tau) + 1;
	assert(L >= 2);
	long P = 2 * a_P;
	if ((L * P) > m_MaxL * m_MaxP)
		throw std::invalid_argument('...');
	std::normal_distribution<> N01(0.0, 1.0);
	std::mt19937_64 U;
	double stau = sqrt(tau);
	double tlast = yT - t0 - double (L - 2) * tau;
	double slast = sqrt(tlast);
	assert(slast <= stau && 0 < slast);




}
