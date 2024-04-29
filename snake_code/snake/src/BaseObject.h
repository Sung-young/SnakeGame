#ifndef __BASE_OBJECT_H__
#define __BASE_OBJECT_H__

// Object의 추상 클래스
class BaseObject {
public:
	BaseObject() {}
	virtual ~BaseObject() {}

	virtual void Update(float tic) = 0;
	virtual void Render() = 0;
};

#endif

// EOF
