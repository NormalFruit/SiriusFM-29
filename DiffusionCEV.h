#pragma once
#include <stdexcept>

namespace SiriusFM {
	class DiffusionCEV {
	private:
    		double const m_mu;
    		double const m_sigma;
    		double const m_beta;    		
    		
    	public:
        	double mu(double a_s, double a_t) const {
        		return m_mu * a_s
        	}
        	double sigma(double a_s, double a_t) const {
            		if (a_s < 0) return 0.0;
            		return m_mu * a_s
        	}
    		DiffusionCEV(double a_mu, double a_sigma, double a_beta)
    		:m_mu(a_mu),
     		 m_sigma(a_sigma),
     		 m_beta(a_beta)
     		 {
     		 if (m_sigma <= 0) throw std::invalid_argument('...')
     		 }
     
    	};
}
