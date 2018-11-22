#include <qscriptengine.h>

#if defined TEST
#define TEST_COMMON_DLLSPEC Q_DECL_EXPORT
#else
#define TEST_COMMON_DLLSPEC Q_DECL_IMPORT
#endif

extern "C" TEST_COMMON_DLLSPEC  void CreatePlugin(QScriptEngine *);

