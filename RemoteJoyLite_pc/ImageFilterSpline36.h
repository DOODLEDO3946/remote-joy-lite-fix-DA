#ifndef IMAGE_FILTER_SPLINE36_H
#define IMAGE_FILTER_SPLINE36_H

#include "ImageFilterPixelShaderBase.h"

class ImageFilterSpline36 : public ImageFilterPixelShaderBase {
public:
	ImageFilterSpline36();
	virtual ~ImageFilterSpline36();
	virtual const Microsoft::WRL::ComPtr<IDirect3DPixelShader9>& getPixelShaderCache();
	virtual void setPixelShaderCache(const Microsoft::WRL::ComPtr<IDirect3DPixelShader9>& pixelShader);
	static void release();

private:
	static Microsoft::WRL::ComPtr<IDirect3DPixelShader9> pixelShaderCache;
};

#endif
