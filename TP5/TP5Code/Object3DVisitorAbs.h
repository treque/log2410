///////////////////////////////////////////////////////////
//  Object3DVisitorAbs.h
//  Implementation of the Class Object3DVisitorAbs
//  Created on:      02-nov.-2018 17:57:42
//  Original author: p482457
///////////////////////////////////////////////////////////

#if !defined(EA_CFF1398C_2BC6_451d_888E_DACED46DFF6D__INCLUDED_)
#define EA_CFF1398C_2BC6_451d_888E_DACED46DFF6D__INCLUDED_

class Object3DVisitorAbs
{

public:
	Object3DVisitorAbs() = default;
	virtual ~Object3DVisitorAbs() = default;

	// Version des methodes traitant des objets const 
	// Par defaut, ces methodes appellent la methode traitant une primitive const
	virtual void visitCube(const class Cube& cub);
	virtual void visitCylinder(const class Cylinder& cyl);
	virtual void visitSphere(const class Sphere& sph);
	virtual void visitTransformedObj(const class TransformedObject3D& tobj);

	// Methode de traitement d'un objet composite const.
	// La methode defaultVisitObjComposite fournit une version par defaut
	virtual void visitObjComposite(const class Object3DComposite& comp) = 0;

	// Version des methodes traitant des objets non-const
	// Par defaut, ces methodes appellent les methodes traitant des objets const
	virtual void visitCube(class Cube& cub);
	virtual void visitCylinder(class Cylinder& cyl);
	virtual void visitObjComposite(class Object3DComposite& comp);
	virtual void visitSphere(class Sphere& sph);
	virtual void visitTransformedObj(class TransformedObject3D& tobj);

protected:
	friend class PrimitiveAbs;
	// Methode de traitement des primitves const
	// Toutes les methodes de traitement pointent vers celle-ci par defaut
	virtual void visitPrimitive(const class PrimitiveAbs& prim) = 0;
	virtual void visitPrimitive(class PrimitiveAbs& prim);

	// Methode de traitement par defaut des composite
	// Invoque le visiteur sur chacun des enfants du composite
	void defaultVisitObjComposite(const class Object3DComposite& comp);
};
#endif // !defined(EA_CFF1398C_2BC6_451d_888E_DACED46DFF6D__INCLUDED_)
