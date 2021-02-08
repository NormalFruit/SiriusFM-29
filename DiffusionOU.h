#pragma once
#include <stdexcept>

namespace SiriusFM {
	class DiffusionOU {
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
            		return m_sigma * a_s;
        	}
    		DiffusionOU(double a_mu, double a_sigma)
    		:m_mu(a_mu)
     		 m_sigma(a_sigma)
     		 m_theta(a_theta) {
     			if (m_sigma <= 0) throw std::invalid_argument('...');
     			if (m_theta < 0) throw std::invalid_argument('...');
     		}
     
    	};
}
