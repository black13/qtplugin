#include <QDebug>
#include <qscriptcontext.h>
#include <qscriptvalueiterator.h>

#include <qscriptengine.h>
#include "plugin.h"

class BaseMessage : public QObject
{
	Q_OBJECT

	Q_PROPERTY(int intProperty READ intProperty WRITE setIntProperty)
		
public:
	
		BaseMessage(QObject *parent = 0)
		: QObject(parent),
		m_intValue(123)
	
	{ }

	int intProperty() const
	{
		qDebug() << m_intValue;
		return m_intValue;
	}
	void setIntProperty(int value)
	{
		qDebug() << value;
		m_intValue = value;
	}

protected:
	int m_intValue;

};


class Quelle : public Base {
public:
	Quelle(QScriptEngine *_eng)
		: m_engine(_eng)
	{
		m_myObject = new BaseMessage();
		m_engine->globalObject().setProperty("myObject", m_engine->newQObject(m_myObject));
		m_engine->globalObject().setProperty("global", m_engine->globalObject());
		//construct all the messages.
	}
	virtual ~Quelle()
	{

	}

	virtual void construct(QScriptEngine *_engine);

private:
	QScriptEngine *m_engine;
	BaseMessage   *m_myObject;
};

Base* CreatePlugin(QScriptEngine * _eng) {
	return static_cast<Base*>(new Quelle(_eng));
}


void Quelle::construct(QScriptEngine *_engine)
{
	//m_engine = _engine;
}

#include "plugin.moc"