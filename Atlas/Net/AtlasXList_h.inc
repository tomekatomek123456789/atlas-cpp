#include "Python.h"

#ifdef STDC_HEADERS
#include <stddef.h>
#else
#include <sys/types.h>		/* For size_t */
#endif


#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
        PyObject_VAR_HEAD
        PyObject **ob_item;
} X(ListObject);

extern DL_EXPORT(PyTypeObject) X(List_Type);


extern DL_IMPORT(PyObject *)	X(List_New) 		Py_PROTO((int size));
extern DL_IMPORT(int)		X(List_Size)		Py_PROTO((PyObject *));
extern DL_IMPORT(PyObject *)	X(List_GetItem)		Py_PROTO((PyObject *, int));
extern DL_IMPORT(int)		X(List_SetItem)		Py_PROTO((PyObject *, int, PyObject *));
extern DL_IMPORT(int)		X(List_Insert)		Py_PROTO((PyObject *, int, PyObject *));
extern DL_IMPORT(int)		X(List_Append)		Py_PROTO((PyObject *, PyObject *));
extern DL_IMPORT(PyObject *)	X(List_GetSlice)	Py_PROTO((PyObject *, int, int));
extern DL_IMPORT(int)		X(List_SetSlice)	Py_PROTO((PyObject *, int, int, PyObject *));
extern DL_IMPORT(int)		X(List_Sort)		Py_PROTO((PyObject *));
extern DL_IMPORT(int)		X(List_Reverse)		Py_PROTO((PyObject *));
extern DL_IMPORT(PyObject *)	X(List_AsTuple)		Py_PROTO((PyObject *));


DL_EXPORT(void) X2(init,List)();

#ifndef __implementation__
#undef X
#undef X2
#undef TYPE_STR
#endif

#ifdef __cplusplus
}
#endif