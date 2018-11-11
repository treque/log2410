///////////////////////////////////////////////////////////
//  Torus.cpp
//  Implementation of the Class Torus
//  Created on:      11-nov.-2018 00:12:09
//  Original author: Huyen Trang Dinh
///////////////////////////////////////////////////////////

#include "Torus.h"


Torus::Torus(const Point3D& pt, float rTotal, float rInt)
	: PrimitiveAbs(pt)
{
	if (rTotal < 0.0 || rInt < 0.0)
		throw std::range_error("Invalid dimension value for torus. Must be larger than 0");

	m_dimensions[0] = rTotal;
	m_dimensions[1] = rInt;
}

Torus::~Torus() {
}

Torus * Torus::clone() const{
	return new Torus(m_center, m_dimensions[0], m_dimensions[1]);
}

size_t Torus::getNbParameters() const {
	size_t nbParam = sizeof(m_dimensions) / sizeof(float);
	return nbParam;
}

PrimitiveParams Torus::getParameters() const {
	PrimitiveParams parameters;
	for (int i = 0; i < getNbParameters(); i++) {
		parameters.push_back(m_dimensions[i]);
	}
	return parameters;
}

void Torus::setParameter(size_t pIndex, float pValue) {
	if (pIndex < 0 || pIndex > 1)
		throw std::range_error("Invalid parameter index for torus. Must be between 0 and 1");

	if (pValue < 0.0)
		throw std::range_error("Invalid radius value for torus. Must be larger than 0");

	m_dimensions[pIndex] = pValue;
}

std::ostream & Torus::toStream(std::ostream & o) const{
	return o << "Torus:    center = " << m_center << "; rTotal = " << m_dimensions[0] << "; rInt = " << m_dimensions[1] << ";";
}
