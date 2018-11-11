///////////////////////////////////////////////////////////
//  Objet3DComposite.cpp
//  Implementation of the Class Objet3DComposite
//  Created on:      25-oct.-2018 20:40:33
//  Original author: p482457
///////////////////////////////////////////////////////////

#include "Objet3DComposite.h"


Objet3DComposite::Objet3DComposite(){

}

Objet3DComposite::Objet3DComposite(const Objet3DComposite & mdd)
{
	// A Completer...
	// Not sure what this attribute is, but we're initializing it.
	outputIndent = mdd.outputIndent;
	// Making a composite object out of another composite object
	// by cloning their children
	for (const Objet3DPtr& objet3d : mdd.m_objetContainer) {
		addChild(*objet3d);
	}
}

Objet3DComposite::~Objet3DComposite(){
}

Objet3DComposite * Objet3DComposite::clone() const
{
	// a completer
	Objet3DComposite* ptr = new Objet3DComposite();
	for (auto it = cbegin(); it != cend(); it++) {
		ptr->addChild(*it);
	}
	return ptr;
}

void Objet3DComposite::addChild(const Objet3DAbs& obj3d)
{
	// A Completer...
	// Only takes pointers, so construct the pointer
	m_objetContainer.push_back(Objet3DPtr(obj3d.clone()));
}

Objet3DIterator Objet3DComposite::begin(){

	// A Completer...
	return m_objetContainer.begin();
}

Objet3DIterator_const Objet3DComposite::cbegin() const {

	// A Completer...
	return m_objetContainer.cbegin();
}

Objet3DIterator_const Objet3DComposite::cend() const {

	// A Completer...
	return m_objetContainer.cend();
}

Objet3DIterator Objet3DComposite::end(){

	// A Completer...
	return m_objetContainer.end();
}

Point3D Objet3DComposite::getCenter() const {
	
	// A Completer...
	return computeCenter();
}

size_t Objet3DComposite::getNbParameters() const 
{
	return 0;
}

PrimitiveParams Objet3DComposite::getParameters() const {

	return  PrimitiveParams();
}

void Objet3DComposite::removeChild(Objet3DIterator_const obj3dIt)
{
	// A Completer...
	m_objetContainer.erase(obj3dIt);
}

void Objet3DComposite::moveCenter(const Point3D & delta)
{
	// A Completer...
	// On parcourt chaque reference de chaque enfant
	for (Objet3DPtr& objet3d : m_objetContainer) {
		objet3d->moveCenter(delta);
	}
}

void Objet3DComposite::setCenter(const Point3D& center){
	// A Completer...
	// Parce que getCenter compute le centre, je veux que le computing
	// donne ce nouveau centre. On parcourt chaque reference de chaque enfant
	for (Objet3DPtr& objet3d : m_objetContainer) {
		objet3d->setCenter(center);
	}
}

void Objet3DComposite::setParameter(size_t pIndex, float pValue){

}

Point3D Objet3DComposite::computeCenter() const
{
	// Calcul la moyenne des centres de tous les enfants
	// S'il n'y a pas d'enfant, initialise a (0,0,0)

	// A Completer...
	Point3D m_center = Point3D(0,0,0);;

	// S'il y a des enfants, parcourir ceux-ci
	// Calcul du CENTROIDE
	if (m_objetContainer.size() > 0) {
		for (auto it = cbegin(); it != cend(); it++) {
			m_center += it->getCenter();
		}
		m_center /= m_objetContainer.size();
	}
	return m_center;
}

// Variable statique permettant de stocker le niveau d'indentation
size_t Objet3DComposite::outputIndent = 0;

std::ostream& indentation(std::ostream& o, size_t indentLevel)
{
	for (auto iindent = 0; iindent < indentLevel; ++iindent)
		o << "\t";
	return o;
}

std::ostream & Objet3DComposite::toStream(std::ostream & o) const
{
	o << "Composite: center = " << computeCenter() << ": {" << std::endl;
	++outputIndent;
	for (auto it = cbegin(); it != cend(); ++it)
		indentation(o, outputIndent) << *it << std::endl;
	--outputIndent;
	indentation(o, outputIndent) << "}";

	return o;
}
