#include <QtCore>

#include <qscriptengine.h>
#include <qscriptcontext.h>
#include <qscriptvalueiterator.h>

#include "plugin.h"


int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);
	QScriptEngine *m_engine = new QScriptEngine();
	
	Base *b = CreatePlugin(m_engine);
	//b->print();

	m_engine->evaluate("myObject.intProperty = 1;");
	return a.exec();
}

//#include "tst_app.moc"