#include "StdAfx.h"
#include "drawWidget.h"
#include "Option.h"
#include <GL/glu.h>

const double PI = acos(-1.0);

CDrawWidget::CDrawWidget(QWidget *theParent) : QGLWidget(theParent)
{
	this->timer = new QTimer();
	connect(timer, SIGNAL(timeout()), this, SLOT(OnTimer()));

	this->mesh = NULL;
	this->IsInitializing = false;
	this->selectedFaces.clear();
	this->meshCenter = MyMesh::Point(0, 0, 0);
	this->meshScale = 0;
	m_RotationMatrix = new GLfloat[16];
	m_RotationMatrix[0] = 1;
	m_RotationMatrix[1] = 0;
	m_RotationMatrix[2] = 0;
	m_RotationMatrix[3] = 0;
	m_RotationMatrix[4] = 0;
	m_RotationMatrix[5] = 1;
	m_RotationMatrix[6] = 0;
	m_RotationMatrix[7] = 0;
	m_RotationMatrix[8] = 0;
	m_RotationMatrix[9] = 0;
	m_RotationMatrix[10] = 1;
	m_RotationMatrix[11] = 0;
	m_RotationMatrix[12] = 0;
	m_RotationMatrix[13] = 0;
	m_RotationMatrix[14] = 0;
	m_RotationMatrix[15] = 1;
	m_xTranslation = 0.0f;
	m_yTranslation = 0.0f;
	m_zTranslation = -5.0f;
	m_xScaling = 1.5f;
	m_yScaling = 1.5f;
	m_zScaling = 1.5f;

	//m_LightAmbientColor[0] = 0.7;
	//m_LightAmbientColor[1] = 0.7;
	//m_LightAmbientColor[2] = 0.7;
	//m_LightAmbientColor[3] = 1.0;

	//m_LightDiffuseColor[0] = 0.8;
	//m_LightDiffuseColor[1] = 0.8;
	//m_LightDiffuseColor[2] = 0.8;
	//m_LightDiffuseColor[3] = 1.0;

	//m_LightSpecularColor[0] = 1.0;
	//m_LightSpecularColor[1] = 1.0;
	//m_LightSpecularColor[2] = 1.0;
	//m_LightSpecularColor[3] = 1.0;
}

CDrawWidget::~CDrawWidget()
{
	delete[] m_RotationMatrix;
}

void CDrawWidget::initializeGL()
{
	glPointSize(3.0);
	//glShadeModel(GL_FLAT);
	glEnable(GL_NORMALIZE);

	glClearColor(COption::BackgroundColor.redF(), COption::BackgroundColor.greenF(), 
		COption::BackgroundColor.blueF(), COption::BackgroundColor.alphaF());
	glClearDepth( 1.0 );

	// Lights, material properties
	//0.7, 0.7, 0.7, 1.0较好
	InitializeLightAmbient(COption::LightAmbientColor);

	//0.8, 0.8, 0.8, 1.0较好
	InitializeLightDiffuse(COption::LightDiffuseColor);

	//1.0, 1.0, 1.0, 1.0较好
	InitializeLightSpecular(COption::LightSpecularColor);

	glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, 1.0);

	// Default : lighting
	glEnable(GL_LIGHT0);
	//glEnable(GL_LIGHTING);

	this->IsInitializing = true;
	if (COption::IsVertexMode)
	{
		this->ShowVertexMode();
	}
	if (COption::IsWireFrameMode)
	{
		this->ShowWireFrameMode();
	}
	if (COption::IsFaceMode)
	{
		this->ShowFaceMode();
	}

	this->ShowAntialias();
	this->ShowLighting();
	this->ShowSmooth();
	this->ShowAnimation();
	this->ShowBackFace();
	this->IsInitializing = false;
}

void CDrawWidget::InitializeLightAmbient( QColor& color )
{
	GLfloat	ambientProperties[]  = {color.redF(), color.greenF(), color.blueF(), 
		color.alphaF()};
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambientProperties);
}

void CDrawWidget::InitializeLightDiffuse( QColor& color )
{
	GLfloat	diffuseProperties[]  = {color.redF(), color.greenF(), color.blueF(), 
		color.alphaF()};
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseProperties);
}

void CDrawWidget::InitializeLightSpecular( QColor& color )
{
	GLfloat	specularProperties[] = {color.redF(), color.greenF(), color.blueF(), 
		color.alphaF()};
	glLightfv(GL_LIGHT0, GL_SPECULAR, specularProperties);
}

void CDrawWidget::resizeGL(int theWidth, int theHeight)
{
	//if ( height == 0 )
	//{   
	//	height = 1;  
	//}
	//glViewport( 0, 0, (GLint)width, (GLint)height );
	//glMatrixMode(GL_PROJECTION);
	//glLoadIdentity();
	//gluPerspective( 45.0, (GLfloat)width/(GLfloat)height, 0.1, 100 );
	//glMatrixMode(GL_MODELVIEW);
	//glLoadIdentity();
	//glDrawBuffer(GL_BACK);
	//glEnable(GL_DEPTH_TEST);


	this->makeCurrent();

	// Set OpenGL perspective, viewport and mode
	glViewport(0, 0, theWidth, theHeight);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	this->SetProjection();
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	//glDrawBuffer(GL_BACK);
	glEnable(GL_DEPTH_TEST);
}

void CDrawWidget::paintGL()
{
	glMatrixMode(GL_MODELVIEW);
	this->makeCurrent();

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glClearColor(COption::BackgroundColor.redF(), COption::BackgroundColor.greenF(), 
		COption::BackgroundColor.blueF(), COption::BackgroundColor.alphaF());

	glPushMatrix();

	// Position / translation / scale
	m_xTranslation = -this->meshCenter.data()[0];
	m_yTranslation = -this->meshCenter.data()[1];
	m_zTranslation = -this->meshCenter.data()[2];

	glTranslatef(0, 0, -5);

	glMultMatrixf(m_RotationMatrix);

	//m_xScaling /= pDoc->ModelScale;
	//m_yScaling /= pDoc->ModelScale;
	//m_zScaling /= pDoc->ModelScale;
	glScalef(m_xScaling / this->meshScale, m_yScaling / this->meshScale,
		m_zScaling / this->meshScale);

	glTranslatef(m_xTranslation, m_yTranslation, m_zTranslation);

	// Start rendering...
	this->RenderScene();

	glPopMatrix();

	// Double buffer
	// QT 4.8开始，swapBuffers是系统在每次paintGL后自动调用的，手动调用的话，
	// 反而会连续swap两次，导致绘制不出来。
	//this->swapBuffers();



	//this->makeCurrent();

	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	
	//glClearColor(backColor[0], backColor[1], backColor[2], backColor[3]);
	//glPushMatrix();
	//gluLookAt(1.0,1.0,1.0,
	//		  0.0,0.0,0.0,
	//		  0.0,1.0,0.0);
	//glTranslatef(  -3.8,  -3.0, zoom );
	//glRotatef( xRot,  1.0,  0.0,  0.0 );
	//glRotatef( yRot,  0.0,  1.0,  0.0 );
	//glScalef(scale,scale,scale);
	//if (model == NULL)
	//{
	//	QMessageBox::warning(this, tr("No Model!"),"No Model!");
	//	return;
	//}
	//else
	//{
	//	//画所有的点。
	//	glBegin(GL_POINTS);
	//	glPointSize(3);
	//	glColor3f(frontColor[0], frontColor[1], frontColor[2]);
	//	for (int i = 0; i < this->model->Vertices.size(); i++)
	//	{
	//		glVertex3f(this->model->Vertices[i].x, this->model->Vertices[i].y, 
	//			this->model->Vertices[i].z);     
	//	}
	//	glEnd();
	//	//画模型
	//	for (int i = 0; i < this->model->Faces.size(); i++)
	//	{
	//		CFace& face = this->model->Faces[i];
	//		if (this->model->Regions.size() > 0)
	//		{
	//			glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
	//			glEnable(GL_COLOR_MATERIAL);
	//			GLfloat hue = (float)face.OwnerRegion/this->model->Regions.size();
	//			GLfloat red, green, blue;
	//			HSLtoRGB(hue, 1.0, 0.5, red, green, blue);
	//			//glColor3f(red, green, blue);
	//			glColor3f(frontColor[0],frontColor[1],frontColor[2]);
	//		}
	//		glBegin(GL_POLYGON);
	//		for (int j = 0; j < face.Vertex.size(); j++)
	//		{
	//			int vertexNormalIndex = face.VertexNormal[j];
	//			if (vertexNormalIndex > -1 && vertexNormalIndex < 
	//				this->model->VertexNormals.size())
	//			{
	//				CVertex &vertexNormal = this->model->VertexNormals[vertexNormalIndex];
	//				glNormal3f(vertexNormal.x, vertexNormal.y, vertexNormal.z);
	//			}
	//			int vertexIndex = face.Vertex[j];
	//			if (vertexIndex > -1 && vertexIndex < this->model->Vertices.size())
	//			{
	//				CVertex &vertex = this->model->Vertices[vertexIndex];
	//				glVertex3f(vertex.x, vertex.y, vertex.z);
	//			}
	//			else
	//			{
	//				QMessageBox::warning(this, tr("非法"),"数据文件中某些Face数据非法！");
	//				if (this->model != NULL)
	//				{
	//					delete this->model;
	//					this->model = NULL;
	//				}
	//			}
	//		}
	//		glEnd();  	
	//	}
	//}
	//glPopMatrix();
	//glFlush();
}

//鼠标单击事件
void CDrawWidget::mousePressEvent(QMouseEvent *theEvent)
{
	m_LeftDownPos = theEvent->pos();
	//updateGL();
}

//鼠标移动事件
void CDrawWidget::mouseMoveEvent(QMouseEvent *theEvent)
{
	//int dx = event->x() - m_LeftDownPos.x();
	//int dy = event->y() - m_LeftDownPos.y();

	//if (event->buttons() & Qt::LeftButton) {
	//	xRot += dx * 8;
	//	yRot += dy * 8;
	//	zRot += 0;;
	//} else if (event->buttons() & Qt::RightButton) {
	//	xRot += dy * 8;
	//	yRot += 0;
	//	zRot += dx * 8;
	//}
	//m_LeftDownPos = event->pos();

	float yRotationAngle = (float)(theEvent->x() - m_LeftDownPos.x())/3.0f;
	float xRotationAngle = (float)(theEvent->y() - m_LeftDownPos.y())/3.0f;
	GLfloat* xRotationMatrix = this->GetXRotationMatrix(xRotationAngle);
	GLfloat* yRotationMatrix = this->GetYRotationMatrix(yRotationAngle);
	m_RotationMatrix = MultiMatrix(xRotationMatrix, m_RotationMatrix);
	m_RotationMatrix = MultiMatrix(yRotationMatrix, m_RotationMatrix);
	delete xRotationMatrix;
	delete yRotationMatrix;
	m_LeftDownPos = theEvent->pos();

	updateGL();
}

//鼠标滚轮滑动事件
void CDrawWidget::wheelEvent(QWheelEvent *theEvent)
{															 
	//int numDegrees = event->delta() / 8;
	//int numSteps = numDegrees / 15;
	//this->scale += double(numSteps) / 10.0;
	//event->accept();
	//updateGL();

	double step = 0.2;
	//if (nFlags == MK_CONTROL)
	//{
	//	step = 3 * step;
	//}

	int numDegrees = theEvent->delta() / 8;
	int numSteps = numDegrees / 15;
	step *= numSteps;
	this->m_xScaling -= step;
	this->m_yScaling -= step;
	this->m_zScaling -= step;

	this->updateGL();
}

//模型旋转事件
void CDrawWidget::OnTimer()
{
	//xRot += xSpeed;
	//yRot += ySpeed;
	//updateGL();
	//timer->start();
	GLfloat* yRotationMatrix = NULL;
	float yRotationAngle = 5.0;
	yRotationMatrix	= this->GetYRotationMatrix(yRotationAngle);
	m_RotationMatrix = MultiMatrix(yRotationMatrix, m_RotationMatrix);
	delete yRotationMatrix;
	this->updateGL();
}

//绘制点模型
void CDrawWidget::ShowVertexMode()
{
	this->makeCurrent();
	glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);

	if (!this->IsInitializing)
	{
		this->updateGL();
	}
}

//绘制线模型
void CDrawWidget::ShowWireFrameMode()
{
	this->makeCurrent();
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	if (!this->IsInitializing)
	{
		this->updateGL();
	}
}

//绘制面模型
void CDrawWidget::ShowFaceMode()
{
	this->makeCurrent();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	if (!this->IsInitializing)
	{
		this->updateGL();
	}
}

//是否开启模型光照
void CDrawWidget::ShowLighting()
{
	this->makeCurrent();
	if(COption::IsLighting)
		glEnable(GL_LIGHTING);
	else
		glDisable(GL_LIGHTING);

	if (!this->IsInitializing)
	{
		this->updateGL();
	}
}

//是否开启模型反锯齿
void CDrawWidget::ShowAntialias()
{
	this->makeCurrent();
	if(COption::IsAntialising)
	{
		glEnable(GL_LINE_SMOOTH);
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
		glLineWidth(1.5);
	}
	else
	{
		glDisable(GL_LINE_SMOOTH);
		glDisable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
		glLineWidth(1.0);
	}

	if (!this->IsInitializing)
	{
		this->updateGL();
	}
}

//是否开启模型Grourand着色
void CDrawWidget::ShowSmooth()
{
	this->makeCurrent();
	if(COption::IsGourand)
	{
		//ChangeCalculationMethodOfNormalsOfModel(true);
		glShadeModel(GL_SMOOTH);
	}
	else
	{
		//ChangeCalculationMethodOfNormalsOfModel(false);
		glShadeModel(GL_FLAT);
	}

	if (!this->IsInitializing)
	{
		this->updateGL();
	}
}

void CDrawWidget::ShowAnimation()
{
	if (COption::IsAnimation)
	{
		timer->start(20);
	}
	else
	{
		timer->stop();
	}
}

void CDrawWidget::SetBackColor(QRgb bColor)
{
	COption::BackgroundColor = QColor(bColor);
	updateGL();
}

void CDrawWidget::SetFrontColor(QRgb fColor)
{
	COption::ForegroundColor = QColor(fColor);
	updateGL();
}

void CDrawWidget::SetLightAmbientColor(QRgb lAColor)
{
	COption::LightAmbientColor = QColor(lAColor);
	InitializeLightAmbient(COption::LightAmbientColor);
	updateGL();
}

void CDrawWidget::SetLightDiffuseColor(QRgb lDColor)
{
	COption::LightDiffuseColor = QColor(lDColor);
	InitializeLightDiffuse(COption::LightDiffuseColor);
	updateGL();
}

void CDrawWidget::SetLightSpecularColor(QRgb lSColor)
{
	COption::LightSpecularColor = QColor(lSColor);
	InitializeLightSpecular(COption::LightSpecularColor);
	updateGL();
}

//将HSL变为RGB表示，其中，hue表示色调，可以通过改变hue，得到各种颜色，基本线性。
//saturation一般可取1.0，luminance不可取1.0，否则太亮成白色，一般可取0.5。
//返回的RGB也是0-1.0之间的。
void HSLtoRGB(const float hue, const float saturation, const float luminance,
	float& red, float& green, float& blue)
{   
	float h = hue;            // h must be [0, 1]   
	float s = saturation;     // s must be [0, 1]   
	float l = luminance;      // l must be [0, 1]   
	float R, G, B;   
	if(saturation == 0)   
	{   
		// achromatic color (gray scale)   
		R = G = B = l;   
	}   
	else  
	{   
		float q = (l<0.5f)?(l * (1.0f+s)):(l+s - (l*s));   
		float p = (2.0f * l) - q;   
		float Hk = h;   
		float T[3];   
		T[0] = Hk + 0.3333333f; // Tr   0.3333333f=1.0/3.0   
		T[1] = Hk;              // Tb   
		T[2] = Hk - 0.3333333f; // Tg   
		for(int i=0; i<3; i++)   
		{   
			if(T[i] < 0) T[i] += 1.0f;   
			if(T[i] > 1) T[i] -= 1.0f;   
			if((T[i]*6) < 1)   
			{   
				T[i] = p + ((q-p)*6.0f*T[i]);   
			}   
			else if((T[i]*2.0f) < 1) //(1.0/6.0)<=T[i] && T[i]<0.5   
			{   
				T[i] = q;   
			}   
			else if((T[i]*3.0f) < 2) // 0.5<=T[i] && T[i]<(2.0/3.0)   
			{   
				T[i] = p + (q-p) * ((2.0f/3.0f) - T[i]) * 6.0f;   
			}   
			else T[i] = p;   
		}   
		R = T[0];   
		G = T[1];   
		B = T[2];   
	}   
	red = ((R>1)? 1 : ((R<0)?0 : R));   
	green = ((G>1)? 1 : ((G<0)?0 : G));   
	blue = ((B>1)? 1 : ((B<0)?0 : B));   
}   

void CDrawWidget::RenderScene()
{
	if (mesh == NULL)
	{
		return;
	}

	//画模型
	glColor4f(COption::ForegroundColor.redF(), COption::ForegroundColor.greenF(), 
		COption::ForegroundColor.blueF(), COption::ForegroundColor.alphaF());
	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
	glEnable(GL_COLOR_MATERIAL);

	for (auto face = this->mesh->faces_begin(); face != this->mesh->faces_end(); ++face)
	{
		//绘制区域
		//if (this->model->Regions.size() > 0)
		//{
		//	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
		//	glEnable(GL_COLOR_MATERIAL);
		//	GLfloat hue = (float)face.OwnerRegion 
		//		/ this->model->Regions.size();
		//	GLfloat red, green, blue;
		//	HSLtoRGB(hue, 1.0, 0.5, red, green, blue);
		//	glColor3f(red, green, blue);
		//	if (std::find(this->selectedFaces.begin(), this->selectedFaces.end(), i) 
		//		!= this->selectedFaces.end())
		//	{
		//		glColor3f(0, 0, 0);
		//	}
		//}
		//else
		//{
		//绘制选中面片
		if (std::find(this->selectedFaces.begin(), this->selectedFaces.end(), face.handle()) 
			!= this->selectedFaces.end())
		{
			glColor3f(255, 0, 0);
		}
		else
		{
			glColor4f(COption::ForegroundColor.redF(), COption::ForegroundColor.greenF(), 
				COption::ForegroundColor.blueF(), COption::ForegroundColor.alphaF());
		}
		//}

		glLoadName(face.handle().idx());
		glBegin(GL_POLYGON);
		for (auto vertex = this->mesh->cfv_begin(face.handle()); 
			vertex != this->mesh->cfv_end(face.handle()); ++vertex)
		{		
			MyMesh::Normal normal;
			if (COption::IsGourand)
			{
				normal = this->mesh->normal(vertex.handle());
			}
			else
			{
				normal = this->mesh->normal(face.handle());
			}
			glNormal3f(normal.data()[0], normal.data()[1], normal.data()[2]);

			auto point = this->mesh->point(vertex.handle());
			glVertex3f(point.data()[0], point.data()[1], point.data()[2]);
		}
		glEnd();  

		if (COption::IsFaceLineMode)
		{
			glColor3f(0, 0, 0);
			glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
			glBegin(GL_POLYGON);
			for (auto vertex = this->mesh->cfv_begin(face.handle()); 
				vertex != this->mesh->cfv_end(face.handle()); ++vertex)
			{		
				MyMesh::Normal normal = this->mesh->normal(vertex.handle());
				auto point = this->mesh->point(vertex.handle());
				point += normal.normalize() * 0.001 * meshScale;
				glVertex3f(point.data()[0], point.data()[1], point.data()[2]);
			}
			glEnd();
			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		}
	}
}

void CDrawWidget::SetMesh( MyMesh* theMesh )
{
	this->mesh = theMesh;

	this->meshScale = this->CalculateScaleOfMesh();
	this->meshCenter = this->GetCenter(*theMesh);

	if (!this->mesh->has_vertex_normals())
	{
		this->mesh->request_vertex_normals();
	}
	if (!this->mesh->has_face_normals())
	{
		this->mesh->request_face_normals();
	}
	this->mesh->update_normals();
}

double CDrawWidget::CalculateScaleOfMesh()
{
	if (this->mesh == NULL)
	{
		throw "模型不能为空！";
	}

	double xScale = 0;
	double yScale = 0;
	double zScale = 0;
	for(auto vertex = mesh->vertices_begin(); vertex != mesh->vertices_end(); ++vertex)
	{
		auto point = this->mesh->point(vertex.handle());
		if (abs(point.data()[0]) > xScale)
		{
			xScale = abs(point.data()[0]);
		}
		if (abs(point.data()[1]) > yScale)
		{
			yScale = abs(point.data()[1]);
		}
		if (abs(point.data()[2]) > zScale)
		{
			zScale = abs(point.data()[2]);
		}
	}
	return max(max(xScale, yScale), zScale);
}

GLfloat* CDrawWidget::GetXRotationMatrix( float xRotationAngle )
{
	xRotationAngle = xRotationAngle / 180 * PI;
	GLfloat* result = new GLfloat[16];
	result[0] = 1;
	result[1] = 0;
	result[2] = 0;
	result[3] = 0;
	result[4] = 0;
	result[5] = cos(xRotationAngle);
	result[6] = sin(xRotationAngle);
	result[7] = 0;
	result[8] = 0;
	result[9] = -result[6];
	result[10] = result[5];
	result[11] = 0;
	result[12] = 0;
	result[13] = 0;
	result[14] = 0;
	result[15] = 1;
	return result;
}

GLfloat* CDrawWidget::GetYRotationMatrix( float yRotationAngle )
{
	yRotationAngle = yRotationAngle / 180 * PI;
	GLfloat* result = new GLfloat[16];
	result[0] = cos(yRotationAngle);
	result[1] = 0;
	result[2] = -sin(yRotationAngle);
	result[3] = 0;
	result[4] = 0;
	result[5] = 1;
	result[6] = 0;
	result[7] = 0;
	result[8] = -result[2];
	result[9] = 0;
	result[10] = result[0];
	result[11] = 0;
	result[12] = 0;
	result[13] = 0;
	result[14] = 0;
	result[15] = 1;
	return result;
}

GLfloat* CDrawWidget::MultiMatrix( GLfloat* matrix1, GLfloat* matrix2 )
{
	GLfloat* result = new GLfloat[16];
	result[0] = matrix1[0]*matrix2[0] + matrix1[4]*matrix2[1] + 
		matrix1[8]*matrix2[2] + matrix1[12]*matrix2[3];
	result[1] = matrix1[1]*matrix2[0] + matrix1[5]*matrix2[1] + 
		matrix1[9]*matrix2[2] + matrix1[13]*matrix2[3];
	result[2] = matrix1[2]*matrix2[0] + matrix1[6]*matrix2[1] + 
		matrix1[10]*matrix2[2] + matrix1[14]*matrix2[3];
	result[3] = matrix1[3]*matrix2[0] + matrix1[7]*matrix2[1] + 
		matrix1[11]*matrix2[2] + matrix1[15]*matrix2[3];
	result[4] = matrix1[0]*matrix2[4] + matrix1[4]*matrix2[5] + 
		matrix1[8]*matrix2[6] + matrix1[12]*matrix2[7];
	result[5] = matrix1[1]*matrix2[4] + matrix1[5]*matrix2[5] + 
		matrix1[9]*matrix2[6] + matrix1[13]*matrix2[7];
	result[6] = matrix1[2]*matrix2[4] + matrix1[6]*matrix2[5] + 
		matrix1[10]*matrix2[6] + matrix1[14]*matrix2[7];
	result[7] = matrix1[3]*matrix2[4] + matrix1[7]*matrix2[5] + 
		matrix1[11]*matrix2[6] + matrix1[15]*matrix2[7];
	result[8] = matrix1[0]*matrix2[8] + matrix1[4]*matrix2[9] + 
		matrix1[8]*matrix2[10] + matrix1[12]*matrix2[11];
	result[9] = matrix1[1]*matrix2[8] + matrix1[5]*matrix2[9] + 
		matrix1[9]*matrix2[10] + matrix1[13]*matrix2[11];
	result[10] = matrix1[2]*matrix2[8] + matrix1[6]*matrix2[9] + 
		matrix1[10]*matrix2[10] + matrix1[14]*matrix2[11];
	result[11] = matrix1[3]*matrix2[8] + matrix1[7]*matrix2[9] + 
		matrix1[11]*matrix2[10] + matrix1[15]*matrix2[11];
	result[12] = matrix1[0]*matrix2[12] + matrix1[4]*matrix2[13] + 
		matrix1[8]*matrix2[14] + matrix1[12]*matrix2[15];
	result[13] = matrix1[1]*matrix2[12] + matrix1[5]*matrix2[13] + 
		matrix1[9]*matrix2[14] + matrix1[13]*matrix2[15];
	result[14] = matrix1[2]*matrix2[12] + matrix1[6]*matrix2[13] + 
		matrix1[10]*matrix2[14] + matrix1[14]*matrix2[15];
	result[15] = matrix1[3]*matrix2[12] + matrix1[7]*matrix2[13] + 
		matrix1[11]*matrix2[14] + matrix1[15]*matrix2[15];
	delete matrix2;
	return result;
}

void CDrawWidget::GetSelectedFaceAtPosition(const QPoint& point)
{
	const int maxSize = 512;
	GLuint buffer[maxSize];
	GLint viewport[4];

	makeCurrent();

	glGetIntegerv(GL_VIEWPORT, viewport);
	glSelectBuffer(maxSize, buffer);
	glRenderMode(GL_SELECT);

	glInitNames();
	glPushName(0);

	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluPickMatrix(point.x(), viewport[3] - point.y(), 1.0, 1.0, viewport);

	this->SetProjection();
	this->paintGL();
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();

	GLint hits = glRenderMode(GL_RENDER);
	if (hits == 0)
	{
		return;
	}
	GLuint* pBuffer = &buffer[0];
	vector<MyMesh::FaceHandle> tmpSelectedFaces;
	GLuint oldZMin = -1;
	for (int i = 0; i < hits; i++)
	{
		int nameCount = *pBuffer;
		pBuffer ++;
		GLuint zMin = *pBuffer;
		pBuffer += 2;
		if (zMin < oldZMin)
		{
			oldZMin = zMin;
			tmpSelectedFaces.clear();
			for (int j = 0; j < nameCount; j++)
			{
				tmpSelectedFaces.push_back(this->mesh->face_handle(*pBuffer));
				pBuffer++;
			}
		}
		else
		{
			pBuffer += nameCount;
		}
	}
	for(auto it = tmpSelectedFaces.begin(); it != tmpSelectedFaces.end(); ++it)
	{
		if (this->selectedFaces.find(*it) == this->selectedFaces.end())
		{
			this->selectedFaces.insert(*it);
		}
		else
		{
			this->selectedFaces.erase(*it);
		}
	}
}

void CDrawWidget::mouseDoubleClickEvent(QMouseEvent* theEvent)
{
	this->GetSelectedFaceAtPosition(theEvent->pos());
	this->updateGL();
}

void CDrawWidget::SetProjection()
{
	double aspect = (height() == 0) ? (double)width() : (double)width() / (double)height();
	gluPerspective(45, aspect, 1, 15.0);
}

MyMesh::Point CDrawWidget::GetCenter( MyMesh& theMesh )
{
	MyMesh::Point result(0, 0, 0);
	for (auto vertex = theMesh.vertices_begin(); vertex != theMesh.vertices_end(); 
		++vertex)
	{
		result += theMesh.point(vertex.handle());
	}

	result /= (double)theMesh.n_vertices();

	return result;
}

void CDrawWidget::ShowBackFace()
{
	this->makeCurrent();
	if(COption::IsShowBackFace)
	{
		glDisable(GL_CULL_FACE);
	}
	else
	{
		glEnable(GL_CULL_FACE);
		glCullFace(GL_BACK);
	}

	if (!this->IsInitializing)
	{
		this->updateGL();
	}
}

void CDrawWidget::ShowFaceLineMode()
{
	this->makeCurrent();

	if (!this->IsInitializing)
	{
		this->updateGL();
	}
}
