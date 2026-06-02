#ifndef IMAGE_FILTER_PIXEL_SHADER_BASE_H
#define IMAGE_FILTER_PIXEL_SHADER_BASE_H

#include <wrl/client.h>
#include <d3d9.h>
#include "ImageFilter.h"

class ImageFilterPixelShaderBase : public ImageFilter {
public:
	virtual void set(IDirect3DDevice9* device);

protected:
	ImageFilterPixelShaderBase(const char* pixelShaderCode);
	virtual const Microsoft::WRL::ComPtr<IDirect3DPixelShader9>& getPixelShaderCache() = 0;
	virtual void setPixelShaderCache(const Microsoft::WRL::ComPtr<IDirect3DPixelShader9>& pixelShader) = 0;

private:
	const char* pixelShaderCode;
};

#endif
