#ifndef ROBONAUTX_GLOBAL_H
#define ROBONAUTX_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(ROBONAUTX_LIBRARY)
#  define ROBONAUTXSHARED_EXPORT Q_DECL_EXPORT
#else
#  define ROBONAUTXSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // ROBONAUTX_GLOBAL_H
