#ifndef IMAGE_FILTER_LANCZOS4_H
#define IMAGE_FILTER_LANCZOS4_H

// #include <atlbase.h>
#include <wrl/client.h>
#include "ImageFilterPixelShaderBase.h"

struct IDirect3DPixelShader9;

class ImageFilterLanczos4 : public ImageFilterPixelShaderBase {
public:
	ImageFilterLanczos4();
	virtual ~ImageFilterLanczos4();
	virtual const Microsoft::WRL::ComPtr<IDirect3DPixelShader9>& getPixelShaderCache();
	virtual void setPixelShaderCache(const Microsoft::WRL::ComPtr<IDirect3DPixelShader9>& pixelShader);
	static void release();

private:
	static Microsoft::WRL::ComPtr<IDirect3DPixelShader9> pixelShaderCache;
};

#endif
