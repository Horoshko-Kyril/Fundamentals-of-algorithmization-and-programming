#ifndef BINARYHEAPLIST_GLOBAL_H
#define BINARYHEAPLIST_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(BINARYHEAPLIST_LIBRARY)
#define BINARYHEAPLIST_EXPORT Q_DECL_EXPORT
#else
#define BINARYHEAPLIST_EXPORT Q_DECL_IMPORT
#endif

#endif // BINARYHEAPLIST_GLOBAL_H
