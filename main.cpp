#include <QDebug>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QSslSocket>
#include <sstream>

int main(int argc, char *argv[]) {
  QGuiApplication app(argc, argv);

  QString message;
  QTextStream out(&message);
  out << "\nSupports: " << QString(QSslSocket::supportsSsl() ? "yes" : "no")
      << "\nBuild library: " << QSslSocket::sslLibraryBuildVersionString()
      << "\nLinked library: " << QSslSocket::sslLibraryVersionString()
      << "\nActive backend: " << QSslSocket::activeBackend();

  QQmlApplicationEngine engine;
  engine.rootContext()->setContextProperty("message", message);

  const QUrl url("qrc:/main.qml");
  QObject::connect(
      &engine, &QQmlApplicationEngine::objectCreated, &app,
      [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
          QCoreApplication::exit(-1);
      },
      Qt::QueuedConnection);
  engine.load(url);

  return app.exec();
}
