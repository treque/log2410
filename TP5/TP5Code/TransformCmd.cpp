///////////////////////////////////////////////////////////
//  TransformCmd.cpp
//  Implementation of the Class TransformCmd
//  Created on:      08-nov.-2018 21:05:11
//  Original author: p482457
///////////////////////////////////////////////////////////

#include "TransformCmd.h"
#include "TransformedObject3D.h"

TransformCmd::TransformCmd(Object3DIterator objIter, const Point3D & translat, float scal)
	: m_objIter(objIter), m_translate(translat), m_scale(scal)
{
}

TransformCmd::~TransformCmd()
{
}

void TransformCmd::cancel()
{
	try
	{
		TransformedObject3D* transformedObject = dynamic_cast<TransformedObject3D*>(&(*m_objIter));
		// A COMPLETER:
		//		- Verifier si l'objet sur lequel pointe l'iterateur est un objet transforme
		if (transformedObject) {
					//		- Recuperer la primitive decoree par l'objet transforme
		//		- Remplacer l'objet sur lequel pointe l'iterateur par la primitive
			m_objIter->getParent().replaceChild(m_objIter, transformedObject->getObject3D());
		}

	}
	catch (std::bad_cast& err)
	{
		std::cerr << "Erreur en annulant une commande de transformation: l'iterateur ne pointe pas sur un objet transforme" 
			<< std::endl << err.what() << std::endl;
	}
}

void TransformCmd::execute()
{
	try 
	{
		// A COMPLETER:
		//		- Verifier si l'objet sur lequel pointe l'iterateur est une primitive
		PrimitiveAbs* primitiveObject = dynamic_cast<PrimitiveAbs*>(&(*m_objIter));
		if (primitiveObject) {
			//		- Construire un nouvel objet transforme en ajoutant un decorateur
			TransformedObject3D* transformedObject = new TransformedObject3D(m_objIter->getParent(), *primitiveObject, m_translate, m_scale);
			//		- Remplacer l'objet sur lequel pointe l'iterateur par l'objet transforme
			m_objIter->getParent().replaceChild(m_objIter, *transformedObject);
		}


	}
	catch (std::bad_cast& err)
	{
		std::cerr << "Erreur en executant une commande de transformation: l'objet a transformer n'est pas une primitive"
			<< std::endl << err.what() << std::endl;
	}
}
