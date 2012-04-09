#include <QtGui/QApplication>
#include <QTranslator>

#include "meetv.h"

Q_DECL_EXPORT int main(int argc, char *argv[])
{
    QScopedPointer<QApplication> app(createApplication(argc, argv));

    QString locale = QLocale::system().name();
    QTranslator translator;

    if (!(translator.load("tr."+locale, ":/")))
        translator.load("tr.en", ":/");

    app->installTranslator(&translator);

    MeeTv viewer;
    viewer.init();
    viewer.run();

    return app->exec();
}
