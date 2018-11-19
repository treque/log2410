///////////////////////////////////////////////////////////
//  XMLPrintCmd.h
//  Implementation of the Class XMLPrintCmd
//  Created on:      08-nov.-2018 21:04:52
//  Original author: p482457
///////////////////////////////////////////////////////////

#if !defined(EA_B5392DB3_2BFC_4507_AC64_C4C9EABE1E1D__INCLUDED_)
#define EA_B5392DB3_2BFC_4507_AC64_C4C9EABE1E1D__INCLUDED_

#include "CommandAbs.h"
#include "Object3DAbs.h"

class XMLPrintCmd : public CommandAbs
{

public:
	XMLPrintCmd(const Object3DAbs& obj3d);
	virtual ~XMLPrintCmd() = default;

	virtual void cancel();
	virtual void execute();

private:
	const Object3DAbs& m_obj3d;
};
#endif // !defined(EA_B5392DB3_2BFC_4507_AC64_C4C9EABE1E1D__INCLUDED_)
