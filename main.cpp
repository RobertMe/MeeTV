#include <QtGui/QApplication>

#include "meetv.h"

Q_DECL_EXPORT int main(int argc, char *argv[])
{
    QScopedPointer<QApplication> app(createApplication(argc, argv));

    MeeTv viewer;
    viewer.init();
    viewer.run();

    return app->exec();
}
