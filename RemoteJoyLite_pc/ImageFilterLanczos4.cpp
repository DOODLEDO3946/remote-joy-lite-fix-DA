#include <windows.h>
#include <wrl/client.h>
#include <d3d9.h>
#include <d3dx9.h>
#include "DxErr/src/dxerr.h"
#include "ImageFilterLanczos4.h"

extern const char* PIXEL_SHADER_LANCZOS4;
Microsoft::WRL::ComPtr<IDirect3DPixelShader9> ImageFilterLanczos4::pixelShaderCache;

ImageFilterLanczos4::ImageFilterLanczos4() : ImageFilterPixelShaderBase(PIXEL_SHADER_LANCZOS4) {
}

ImageFilterLanczos4::~ImageFilterLanczos4() {
}

const Microsoft::WRL::ComPtr<IDirect3DPixelShader9>& ImageFilterLanczos4::getPixelShaderCache() {
	return pixelShaderCache;
}

void ImageFilterLanczos4::setPixelShaderCache(const Microsoft::WRL::ComPtr<IDirect3DPixelShader9>& pixelShader) {
	pixelShaderCache = pixelShader;
}

void ImageFilterLanczos4::release() {
	pixelShaderCache = NULL;
}
