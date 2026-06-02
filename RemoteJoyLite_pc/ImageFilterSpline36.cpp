#include <windows.h>
#include <wrl/client.h>
#include <d3d9.h>
#include <d3dx9.h>
#include "DxErr/src/dxerr.h"
#include "ImageFilterSpline36.h"

extern const char* PIXEL_SHADER_SPLINE36;
Microsoft::WRL::ComPtr<IDirect3DPixelShader9> ImageFilterSpline36::pixelShaderCache;

ImageFilterSpline36::ImageFilterSpline36() : ImageFilterPixelShaderBase(PIXEL_SHADER_SPLINE36) {
}

ImageFilterSpline36::~ImageFilterSpline36() {
}

const Microsoft::WRL::ComPtr<IDirect3DPixelShader9>& ImageFilterSpline36::getPixelShaderCache() {
	return pixelShaderCache;
}

void ImageFilterSpline36::setPixelShaderCache(const Microsoft::WRL::ComPtr<IDirect3DPixelShader9>& pixelShader) {
	pixelShaderCache = pixelShader;
}

void ImageFilterSpline36::release() {
	pixelShaderCache.Reset();
}
