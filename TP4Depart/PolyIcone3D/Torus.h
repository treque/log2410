#pragma once
///////////////////////////////////////////////////////////
//  Torus.h
//  Implementation of the Class Torus
//  Created on:      11-nov.-2018 00:12:09
//  Original author: Huyen Trang Dinh
///////////////////////////////////////////////////////////

#if !defined(EA_7AFCD1D8_33C4_440c_AB86_C25104795AAG__INCLUDED_)
#define EA_7AFCD1D8_33C4_440c_AB86_C25104795AAG__INCLUDED_

#include "../TP4Code/PrimitiveAbs.h"

class Torus : public PrimitiveAbs
{

public:
	Torus(const Point3D& pt, float rTotal, float rInt);
	virtual ~Torus();
	virtual Torus* clone() const;

	virtual size_t getNbParameters() const;
	virtual PrimitiveParams getParameters() const;
	virtual void setParameter(size_t pIndex, float pValue);

private:
	virtual std::ostream& toStream(std::ostream& o) const;

	float m_dimensions[2];
};
#endif // !defined(EA_7AFCD1D8_33C4_440c_AB86_C25104795AAG__INCLUDED_)
