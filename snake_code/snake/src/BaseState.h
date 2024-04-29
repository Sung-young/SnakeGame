#ifndef __BASE_STATE_H__
#define __BASE_STATE_H__

// State의 추상 클래스
class BaseState {
public:
	BaseState() {}
	virtual ~BaseState() {}

	virtual void Update(float tic) = 0;
	virtual void Render() = 0;
};

#endif

// EOF
