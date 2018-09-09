#ifndef NURBS_GLOBAL_H
#define NURBS_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(NURBS_LIBRARY)
#  define NURBSSHARED_EXPORT Q_DECL_EXPORT
#else
#  define NURBSSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // NURBS_GLOBAL_H
