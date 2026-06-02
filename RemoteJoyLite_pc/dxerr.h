const WCHAR* DXGetErrorStringW(HRESULT hr);
const CHAR* DXGetErrorStringA(HRESULT hr);

#ifdef UNICODE
#define DXGetErrorString DXGetErrorStringW
#else
#define DXGetErrorString DXGetErrorStringA
#endif