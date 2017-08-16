#ifndef MTDMED_GLOBAL_H
#define MTDMED_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(MTDMED_LIBRARY)
#  define MTDMEDSHARED_EXPORT Q_DECL_EXPORT
#else
#  define MTDMEDSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // MTDMED_GLOBAL_H
