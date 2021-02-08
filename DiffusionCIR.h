#pragma once
#include <stdexcept>

namespace SiriusFM {
	class DiffusionCIR {
	private:
    		double const m_cappa;
    		double const m_sigma;
    		double const m_theta;
    	public:
        	double mu(double a_s, double a_t) {
        		return m_cappa * (m_theta - a_s);
        	}
        	double sigma(double a_s, double a_t) {
            		if (a_s < 0) return 0.0;
            		return m_sigma * std::sqrt(a_s);
        	}
    		DiffusionCIR(double a_cappa, double a_sigma, double a_theta)
		:m_cappa(a_cappa)
		 m_sigma(a_sigma)
		 m_theta(a_theta) {
			if(m_sigma <= 0) throw std::invalid_arguement('...');
			if(m_cappa < 0)  throw std::invalid_arguement('...');
			if(m_theta <= 0) throw std::invalid_arguement('...');
		}
     
    	};
}
