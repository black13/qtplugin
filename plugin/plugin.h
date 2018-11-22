#include <qscriptengine.h>

#if defined TEST
#define TEST_COMMON_DLLSPEC Q_DECL_EXPORT
#else
#define TEST_COMMON_DLLSPEC Q_DECL_IMPORT
#endif


class Base  {
	
public:
	virtual ~Base() = default;
	virtual void construct(QScriptEngine *) = 0;
};


// DLL export funcs

// Get an instance of the derived class
// contained in the DLL.
extern "C" TEST_COMMON_DLLSPEC Base* CreatePlugin(QScriptEngine *);