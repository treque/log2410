///////////////////////////////////////////////////////////
//  SelectPrimitiveCmd.cpp
//  Implementation of the Class SelectPrimitiveCmd
//  Created on:      08-nov.-2018 21:05:02
//  Original author: p482457
///////////////////////////////////////////////////////////

#include "SelectPrimitiveCmd.h"
#include "VisitorPrimitiveSelector.h"

SelectPrimitiveCmd::SelectPrimitiveCmd(PRIMITIVE_TYPE typ, Object3DAbs & obj3d)
	: m_type(typ), m_obj3d(obj3d)
{
}

SelectPrimitiveCmd::~SelectPrimitiveCmd()
{
}

void SelectPrimitiveCmd::cancel()
{
	// A COMPLETER: Vider le conteneur local a la commande d'objets selectionnes
	// unclear....
	m_selectObjContainer.clear();
}


void SelectPrimitiveCmd::execute()
{
	// A COMPLETER:
	//		- Construire un visiteur de selection
	VisitorPrimitiveSelector selectionVisitor = VisitorPrimitiveSelector(m_type);
	//		- Appliquer le visiteur a l'objet 3d
	m_obj3d.accept(selectionVisitor);
	//		- Recuperer les objets selectionnes dans le conteneur local de la commande
	selectionVisitor.getSelectObjects(m_selectObjContainer);
}

void SelectPrimitiveCmd::getSelectObjects(Obj3DIteratorContainer & objContainer)
{
	// A COMPLETER:
	// Transferer les objets selectionnes du conteneur local a la commande
	// vers le conteneur fourni en argument
	for (auto it = m_selectObjContainer.begin(); it != m_selectObjContainer.end(); it++) {
		objContainer.push_back(*it);
	}
}
 