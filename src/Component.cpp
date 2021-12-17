#include "Component.h"

namespace cwing {

	Component::Component(int x, int y, int w, int h) :rect{ x,y,w,h }
	{
	}
    template<class T1, class T2> bool isIntersecting(T1& mA, T1&mB)
 {
	 return mA.rect.x >= mB.rect.x && mA.rect.x <= mB.rect.x 
	 && mA.rect.y >= mB.rect.y && mA.rect.y <= mB.rect.y; 
 }


	Component::~Component()
	{
	}
}