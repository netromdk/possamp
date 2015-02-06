// Copyright (c) Burator 2014-2015
#include <QDir>
#include <QFile>
#include <QString>
#include <QFileInfo>

#include "Util.h"

B_BEGIN_NAMESPACE

bool Util::isSupportedImage(const QString &path) {
  static const QStringList exts =
    QStringList{"jpg", "jpeg", "png", "tif", "tiff"};
  return exts.contains(QFileInfo(path).suffix().toLower());
}

QString Util::rectToStr(const QRect &rect) {
  return QString("(%1, %2) %3x%4")
    .arg(rect.x()).arg(rect.y()).arg(rect.width()).arg(rect.height());
}

QRect Util::scaleRect(const QRect &rect, float factor) {
  return QRect(float(rect.x()) * factor,
               float(rect.y()) * factor,
               float(rect.width()) * factor,
               float(rect.height()) * factor);
}

QStringList Util::getImages(const QString &folder) {
  QStringList images;
  foreach (const QFileInfo &entry,
           QDir(folder).entryInfoList(QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot)) {
    QString file = entry.fileName();
    if (entry.isDir()) {
      images.append(getImages(file));
    }
    else if (entry.isFile() && isSupportedImage(file)) {
      images << file;
    }
  }
  return images;
}

B_END_NAMESPACE
