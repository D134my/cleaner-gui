#include "bridge.hpp"
#include <QDebug>

Bridge::Bridge(QObject *parent) : QObject{parent} {}

void Bridge::do_clean(const QString &path) {
  Clean clean;
  if (path != "dEfAuLt")
    clean.set_path(path.toStdString() + "/");
  else
    clean.set_path();

  clean.start();
}
