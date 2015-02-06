// Copyright (c) Burator 2014-2015
#ifndef B_UTIL_H
#define B_UTIL_H

#include <QRect>
#include <QString>
#include <QStringList>

#include "Global.h"

B_BEGIN_NAMESPACE

class Util {
public:
  /**
   * Checks whether the extension of the file is a supported image
   * file.
   */
  static bool isSupportedImage(const QString &path);

  /**
   * Represent rect as string.
   */
  static QString rectToStr(const QRect &rect);

  /**
   * Scales the rect by the factor.
   */
  static QRect scaleRect(const QRect &rect, float factor);

  /**
   * Search recursively for supported image files.
   */
  static QStringList getImages(const QString &folder);
};

B_END_NAMESPACE

#endif // B_UTIL_H
