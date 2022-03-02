#pragma once
#include "StdAfx.h"

class COption
{
private:
	COption(void);
	virtual ~COption(void);

public:
	static bool IsAnimation;
	static bool IsVertexMode;
	static bool IsWireFrameMode;
	static bool IsFaceMode;
	static bool IsLighting;
	static bool IsAntialising;
	static bool IsGourand;
	static bool IsShowBackFace;
	static bool IsFaceLineMode;

	static QColor BackgroundColor;
	static QColor ForegroundColor;
	static QColor LightAmbientColor;
	static QColor LightDiffuseColor;
	static QColor LightSpecularColor;
	static void LoadFromFile();
	static void SaveToFile();
};
