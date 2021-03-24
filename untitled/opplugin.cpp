#include "op.h"
#include "opplugin.h"

#include <QtPlugin>

opPlugin::opPlugin(QObject *parent)
    : QObject(parent)
{
    m_initialized = false;
}

void opPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (m_initialized)
        return;

    // Add extension registrations, etc. here

    m_initialized = true;
}

bool opPlugin::isInitialized() const
{
    return m_initialized;
}

QWidget *opPlugin::createWidget(QWidget *parent)
{
    return new op(parent);
}

QString opPlugin::name() const
{
    return QLatin1String("op");
}

QString opPlugin::group() const
{
    return QLatin1String("");
}

QIcon opPlugin::icon() const
{
    return QIcon();
}

QString opPlugin::toolTip() const
{
    return QLatin1String("");
}

QString opPlugin::whatsThis() const
{
    return QLatin1String("");
}

bool opPlugin::isContainer() const
{
    return false;
}

QString opPlugin::domXml() const
{
    return QLatin1String("<widget class=\"op\" name=\"op\">\n</widget>\n");
}

QString opPlugin::includeFile() const
{
    return QLatin1String("op.h");
}
#if QT_VERSION < 0x050000
Q_EXPORT_PLUGIN2(opplugin, opPlugin)
#endif // QT_VERSION < 0x050000
