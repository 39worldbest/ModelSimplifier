#pragma once
#include "StdAfx.h"
//#include <QtOpenGL/QGLFramebufferObject>
#include <QGLWidget>

#include <OpenMesh/Core/IO/MeshIO.hh>
#include <OpenMesh/Core/Mesh/TriMesh_ArrayKernelT.hh>
#include <OpenMesh/Core/Mesh/Handles.hh>

using namespace std;

typedef OpenMesh::TriMesh_ArrayKernelT<>  MyMesh;

class CDrawWidget : public QGLWidget
{
Q_OBJECT

public:
	set<MyMesh::FaceHandle> selectedFaces; 

	CDrawWidget(QWidget* theParent = 0);
	virtual ~CDrawWidget();
	void SetMesh(MyMesh* theMesh);	
	void ShowVertexMode();
	void ShowWireFrameMode();
	void ShowFaceMode();
	void ShowFaceLineMode();
	void ShowLighting();
	void ShowAntialias();
	void ShowSmooth();
	void ShowAnimation();
	void ShowBackFace();
	void SetBackColor(QRgb color);
	void SetFrontColor(QRgb color);
	void SetLightAmbientColor(QRgb color); 
	void SetLightDiffuseColor(QRgb color);
	void SetLightSpecularColor(QRgb color);
public slots:
	void OnTimer();

protected:
	//∏≤∏«∏∏¿‡∑Ω∑®
	void initializeGL();
	void resizeGL(int width, int height);
	void paintGL();
	void mousePressEvent(QMouseEvent* theEvent);
	void mouseMoveEvent(QMouseEvent* theEvent);
	void wheelEvent(QWheelEvent* theEvent);
	void mouseDoubleClickEvent(QMouseEvent* theEvent);
	//

private:
	MyMesh* mesh;
	bool IsInitializing;
	QPoint m_LeftDownPos;

	// Position, rotation ,scaling
	GLfloat* m_RotationMatrix;
	float m_xTranslation;
	float m_yTranslation;
	float m_zTranslation;
	float m_xScaling;
	float m_yScaling;
	float m_zScaling;
	MyMesh::Point meshCenter;
	GLfloat meshScale;

	QTimer *timer;

	void InitializeLightAmbient(QColor& color);
	void InitializeLightDiffuse(QColor& color);
	void InitializeLightSpecular(QColor& color);
	GLfloat* GetXRotationMatrix( float xRotationAngle );
	GLfloat* GetYRotationMatrix( float yRotationAngle );
	GLfloat* MultiMatrix( GLfloat* matrix1, GLfloat* matrix2 );
	double CalculateScaleOfMesh();
	void RenderScene();
	void GetSelectedFaceAtPosition(const QPoint& pos);

	void SetProjection();
	MyMesh::Point GetCenter(MyMesh& theMesh);
};