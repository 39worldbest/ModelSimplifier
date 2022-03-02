#include "StdAfx.h"
#include "Option.h"

bool COption::IsAnimation = false;
bool COption::IsAntialising = false;
bool COption::IsGourand = false;
bool COption::IsLighting = false;
bool COption::IsShowBackFace = true;
bool COption::IsVertexMode = false;
bool COption::IsFaceMode = false;
bool COption::IsWireFrameMode = false;
bool COption::IsFaceLineMode = false;
QColor COption::BackgroundColor = QColor(0, 0, 0, 255);
QColor COption::ForegroundColor = QColor(255, 255, 255, 255);
QColor COption::LightAmbientColor = QColor(178, 178, 178, 255);
QColor COption::LightDiffuseColor = QColor(204, 204, 204, 255);
QColor COption::LightSpecularColor = QColor(255, 255, 255, 255);


COption::COption(void)
{
}

COption::~COption(void)
{
}

void COption::LoadFromFile()
{
	QFile file("SaveOptions.xml");
	if (file.open(QIODevice::ReadOnly))
	{
		while (!file.atEnd())
		{
			QList<QByteArray> tokens = file.readLine().simplified().split(' ');
			QList<QByteArray>::const_iterator it = tokens.begin();
			if (it == tokens.end())
				continue;
			QByteArray type = *it;
			if (++it == tokens.end())
				continue;
			QByteArray name = *it;
			if (++it == tokens.end())
				continue;
			QByteArray value = *it;
			bool singleElement = (tokens.size() == 3);

			if (type == "option")
			{
				if (name == "BackgroundColor")
				{
					COption::BackgroundColor = QRgb(QString(value).toUInt());
				}
				else if (name == "ForegroundColor")
				{
					COption::ForegroundColor = QRgb(QString(value).toUInt());
				}
				else if (name == "LightAmbientColor")
				{
					COption::LightAmbientColor = QRgb(QString(value).toUInt());
				}
				else if (name == "LightDiffuseColor")
				{
					COption::LightDiffuseColor = QRgb(QString(value).toUInt());
				}
				else if (name == "LightSpecularColor")
				{
					COption::LightSpecularColor = QRgb(QString(value).toUInt());
				}
				else if (name == "IsAntiAliasing")
				{
					COption::IsAntialising = value == "1";
				}
				else if (name == "IsGourand")
				{
					COption::IsGourand = value == "1";
				}
				else if (name == "IsLighting")
				{
					COption::IsLighting = value == "1";
				}
				else if (name == "IsShowBackFace")
				{
					COption::IsShowBackFace = value == "1";
				}
				else if (name == "IsAnimation")
				{
					COption::IsAnimation = value == "1";
				}
				else if (name == "IsVertexMode")
				{
					COption::IsVertexMode = value == "1";
				}
				else if (name == "IsWireFrameMode")
				{
					COption::IsWireFrameMode = value == "1";
				}
				else if (name == "IsFaceMode")
				{
					COption::IsFaceMode = value == "1";
				}
				else if (name == "IsFaceLineMode")
				{
					COption::IsFaceLineMode = value == "1";
				}
			}
		}
	}
	file.close();
}

void COption::SaveToFile()
{
	QFile file("SaveOptions.xml");
	file.open(QIODevice::WriteOnly);
	QTextStream out(&file);

	out << "option BackgroundColor ";
	out << COption::BackgroundColor.rgba() << endl;
	out << "option ForegroundColor ";
	out << COption::ForegroundColor.rgba() << endl;
	out << "option LightAmbientColor ";
	out << COption::LightAmbientColor.rgba() << endl;
	out << "option LightDiffuseColor ";
	out << COption::LightDiffuseColor.rgba() << endl;
	out << "option LightSpecularColor ";
	out << COption::LightSpecularColor.rgba() << endl;

	out << "option IsAntiAliasing ";
	if (COption::IsAntialising)
		out << "1\n";
	else 
		out << "0\n";
	out << "option IsGourand ";
	if (COption::IsGourand)
		out << "1\n";
	else
		out << "0\n";
	out << "option IsLighting ";
	if (COption::IsLighting)
		out << "1\n";
	else
		out << "0\n";
	out << "option IsShowBackFace ";
	if (COption::IsShowBackFace)
		out << "1\n";
	else
		out << "0\n";
	out << "option IsAnimation ";
	if (COption::IsAnimation)
		out << "1\n";
	else
		out << "0\n";
	out << "option IsVertexMode ";
	if (COption::IsVertexMode)
		out << "1\n";
	else
		out << "0\n";
	out << "option IsWireFrameMode ";
	if (COption::IsWireFrameMode)
		out << "1\n";
	else
		out << "0\n";
	out << "option IsFaceMode ";
	if (COption::IsFaceMode)
		out << "1\n";
	else
		out << "0\n";
	out << "option IsFaceLineMode ";
	if (COption::IsFaceLineMode)
		out << "1\n";
	else
		out << "0\n";
	file.close();
}
