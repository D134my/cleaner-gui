#ifndef BRIDGE_HPP
#define BRIDGE_HPP

#include "cleaner/clean.hpp"
#include <QObject>
#include <variant>

// this class will connect js input to cleaner-core

class Bridge : public QObject {
  Q_OBJECT
public:
  explicit Bridge(QObject *parent = nullptr);

signals:

public slots:
  void do_clean(QString const &path);
};

#endif // BRIDGE_HPP
