#include <QtCore>

#include <qscriptengine.h>
#include <qscriptcontext.h>
#include <qscriptvalueiterator.h>

#include "plugin.h"


int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);
	QScriptEngine *m_engine = new QScriptEngine();
	CreatePlugin(m_engine);

	return a.exec();
}

#include "tst_app.moc"