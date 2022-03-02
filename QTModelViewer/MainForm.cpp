#include "StdAfx.h"
#include "MainForm.h"
#include "Option.h"
#include "CModelSubdivider.h"

CMainForm::CMainForm(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	this->InitOptions();

	ui.setupUi(this);

	drawWidget = new CDrawWidget(this);
	ui.drawWidgetLayout->addWidget(drawWidget);

	layoutColor = new QHBoxLayout;
	layoutLight = new QHBoxLayout;
	layoutFront = new QHBoxLayout;
	backgroundColorEdit = new ColorEdit(COption::BackgroundColor.rgba());
	backgroundColorEdit->setMaximumHeight(20);
	lightAmbientColorEdit = new ColorEdit(COption::LightAmbientColor.rgba());
	lightAmbientColorEdit->setMaximumHeight(20);
	lightDiffuseColorEdit = new ColorEdit(COption::LightDiffuseColor.rgba());
	lightDiffuseColorEdit->setMaximumHeight(20);
	lightSpecularColorEdit = new ColorEdit(COption::LightSpecularColor.rgba());
	lightSpecularColorEdit->setMaximumHeight(20);
	foregroundColorEdit = new ColorEdit(COption::ForegroundColor.rgba());
	foregroundColorEdit->setMaximumHeight(20);

	ui.colorVLayout->addLayout(layoutColor);
	layoutColor->addWidget(new QLabel("背景"));
	layoutColor->addWidget(backgroundColorEdit);

	ui.colorVLayout->addLayout(layoutLight);
	layoutLight->addWidget(new QLabel("光源"));
	layoutLight->addWidget(lightSpecularColorEdit);
	layoutLight->addWidget(lightDiffuseColorEdit);
	layoutLight->addWidget(lightAmbientColorEdit);

	ui.colorVLayout->addLayout(layoutFront);
	layoutFront->addWidget(new QLabel("前景"));
	layoutFront->addWidget(foregroundColorEdit);

	connect(backgroundColorEdit, SIGNAL(colorChanged(QRgb)), this, 
		SLOT(on_backgroundColorEdit_colorChanged(QRgb)));
	connect(lightAmbientColorEdit, SIGNAL(colorChanged(QRgb)), this, 
		SLOT(on_lightAmbientColorEdit_colorChanged(QRgb)));
	connect(lightDiffuseColorEdit, SIGNAL(colorChanged(QRgb)), this, 
		SLOT(on_lightDiffuseColorEdit_colorChanged(QRgb)));
	connect(lightSpecularColorEdit, SIGNAL(colorChanged(QRgb)), this, 
		SLOT(on_lightSpecularColorEdit_colorChanged(QRgb)));
	connect(foregroundColorEdit, SIGNAL(colorChanged(QRgb)), this, 
		SLOT(on_foregroundColorEdit_colorChanged(QRgb)));

	this->mesh = NULL;
	this->InitUI();
}

CMainForm::~CMainForm()
{
	this->SaveOptions();
	delete layoutColor;
	delete layoutFront;
	delete layoutLight;
	delete backgroundColorEdit;
	delete lightAmbientColorEdit;
	delete lightDiffuseColorEdit;
	delete lightSpecularColorEdit;
	delete foregroundColorEdit;
	delete drawWidget;
	delete mesh;
}

void CMainForm::InitOptions()
{
	COption::LoadFromFile();
}

void CMainForm::SaveOptions()
{
	COption::SaveToFile();
}

void CMainForm::on_action_exit_triggered()
{
	this->close();
}

void CMainForm::on_action_about_triggered()
{
	CAboutForm *about = new CAboutForm();
	about->setFixedSize(about->width(), about->height());
	about->exec();
	delete about;
}

void CMainForm::on_action_open_triggered()
{
	QString fileName = QFileDialog::getOpenFileName(this, "Open File", 
		"e:/MyProjects/MeshProcessor/ModelData/trunk/带洞模型/",
		"Mesh Models (*.ply *.obj *.liu)");
	if (fileName.isEmpty())
	{
		return;
	}

	if (mesh != NULL)
	{
		delete mesh;
	}
	mesh = new MyMesh();

	if (!OpenMesh::IO::read_mesh(*mesh, fileName.toLocal8Bit().data()))
	{
		QMessageBox::warning(this, tr("Can't read specified file!"), fileName);
		return;
	}  
	drawWidget->SetMesh(mesh);
	drawWidget->updateGL();
}

void CMainForm::on_action_close_triggered()
{
	if (this->mesh != NULL)
	{
		this->mesh->release_vertex_normals();
		this->mesh->release_face_normals();
	}

	delete this->mesh;
	this->mesh = NULL;

	delete drawWidget;
	drawWidget = new CDrawWidget(0);
	ui.drawWidgetLayout->addWidget(drawWidget);
}

void CMainForm::on_radFace_clicked()
{
	COption::IsVertexMode = false;
	COption::IsWireFrameMode = false;
	COption::IsFaceMode = true;
	COption::IsFaceLineMode = false;
	this->drawWidget->ShowFaceMode();
}

void CMainForm::on_radLine_clicked()
{
	COption::IsVertexMode = false;
	COption::IsWireFrameMode = true;
	COption::IsFaceMode = false;
	COption::IsFaceLineMode = false;
	this->drawWidget->ShowWireFrameMode();
}

void CMainForm::on_radPoint_clicked()
{
	COption::IsVertexMode = true;
	COption::IsWireFrameMode = false;
	COption::IsFaceMode = false;
	COption::IsFaceLineMode = false;
	this->drawWidget->ShowVertexMode();
}

void CMainForm::on_chkRotation_stateChanged( int state )
{
	COption::IsAnimation = state == Qt::Checked ? true : false;
	this->drawWidget->ShowAnimation();
}

void CMainForm::on_chkLighting_stateChanged( int state )
{
	COption::IsLighting = state == Qt::Checked ? true : false;
	this->drawWidget->ShowLighting();
}

void CMainForm::on_chkAntiAliasing_stateChanged( int state )
{
	COption::IsAntialising = state == Qt::Checked ? true : false;
	this->drawWidget->ShowAntialias();
}

void CMainForm::on_chkGourand_stateChanged( int state )
{
	COption::IsGourand = state == Qt::Checked ? true : false;
	this->drawWidget->ShowSmooth();
}

void CMainForm::on_chkShowBackFace_stateChanged( int state )
{
	COption::IsShowBackFace = state == Qt::Checked ? true : false;
	this->drawWidget->ShowBackFace();
}

void CMainForm::on_backgroundColorEdit_colorChanged( QRgb color )
{
	drawWidget->SetBackColor(color);
}

void CMainForm::on_lightAmbientColorEdit_colorChanged( QRgb color )
{
	drawWidget->SetLightAmbientColor(color);
}

void CMainForm::on_lightDiffuseColorEdit_colorChanged( QRgb color )
{
	drawWidget->SetLightDiffuseColor(color);
}

void CMainForm::on_lightSpecularColorEdit_colorChanged( QRgb color )
{
	drawWidget->SetLightSpecularColor(color);
}

void CMainForm::on_foregroundColorEdit_colorChanged( QRgb color )
{
	drawWidget->SetFrontColor(color);
}

void CMainForm::InitUI()
{
	this->ui.chkAntiAliasing->setChecked(COption::IsAntialising);
	this->ui.chkGourand->setChecked(COption::IsGourand);
	this->ui.chkLighting->setChecked(COption::IsLighting);
	this->ui.chkRotation->setChecked(COption::IsAnimation);
	this->ui.chkShowBackFace->setChecked(COption::IsShowBackFace);
	this->ui.radPoint->setChecked(COption::IsVertexMode);
	this->ui.radLine->setChecked(COption::IsWireFrameMode);
	this->ui.radFace->setChecked(COption::IsFaceMode);
	this->ui.radFaceLine->setChecked(COption::IsFaceLineMode);
}

void CMainForm::on_action_save_triggered()
{
	QMessageBox::warning(this, "信息", "此功能未实现！");
}

void CMainForm::on_action_saveAs_triggered()
{
	QString fileName = QFileDialog::getSaveFileName(this, "网格模型另存为", 
		"e:/MyProjects/MeshProcessor/ModelData/trunk/带洞模型/",
		"网格模型 (*.ply *.obj)");
	if (fileName.isEmpty())
	{
		return;
	}

	if (!OpenMesh::IO::write_mesh(*mesh, fileName.toLocal8Bit().data()))
	{
		QMessageBox::warning(this, "保存网格模型失败！", fileName);
		return;
	}
	else
	{
		QMessageBox::information(this, "保存网格模型完成！", fileName);
	}
}

void CMainForm::on_action_Segmentation_triggered()
{
	if (this->mesh == NULL)
	{
		return;
	}
	if (this->drawWidget->selectedFaces.size() == 0)
	{
		QMessageBox::information(this, "信息", "请先选择种子面片！");
		return;
	}
}

void CMainForm::on_action_FillHole_triggered()
{

}

void CMainForm::on_action_Simplify_triggered()
{
	int n_vertices=this->mesh->n_vertices();
	int n_faces=this->mesh->n_faces();
	int n_edges=this->mesh->n_edges();
	auto newModelSimplifier=std::make_shared<ModelSubdivider>();
	newModelSimplifier->DoSimplify(this->mesh,1);
	this->drawWidget->SetMesh(this->mesh);
	this->drawWidget->updateGL();
	string s1="顶点数:"+to_string(static_cast<long long>(n_vertices))+"->"+to_string(static_cast<long long>(this->mesh->n_vertices()));
	string s2="面片数:"+to_string(static_cast<long long>(n_faces))+"->"+to_string(static_cast<long long>(this->mesh->n_faces()));
	string s3="边   数:"+to_string(static_cast<long long>(n_edges))+"->"+to_string(static_cast<long long>(this->mesh->n_edges()));
	QMessageBox::information(this,"信息",(s1+"\n"+s2+"\n"+s3).data()); 
}

void CMainForm::on_radFaceLine_clicked()
{
	COption::IsVertexMode = false;
	COption::IsWireFrameMode = false;
	COption::IsFaceMode = false;
	COption::IsFaceLineMode = true;
	this->drawWidget->ShowFaceLineMode();
}

ColorEdit::ColorEdit(QRgb initialColor)
	: m_color(initialColor)
{
	layout = new QHBoxLayout;
	setLayout(layout);
	layout->setContentsMargins(0, 0, 0, 0);

	m_button = new QFrame;
	QPalette palette = m_button->palette();
	palette.setColor(QPalette::Window, QColor(m_color));
	m_button->setPalette(palette);
	m_button->setAutoFillBackground(true);
	m_button->setMinimumSize(32, 0);
	m_button->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
	m_button->setFrameStyle(QFrame::StyledPanel | QFrame::Sunken);

	layout->addWidget(m_button);

	m_dialogParentScene = NULL;
}

void ColorEdit::mousePressEvent(QMouseEvent *event)
{
	if (event->button() == Qt::LeftButton) {
		QColor color(m_color);
		QColorDialog dialog(color, 0);
		dialog.setOption(QColorDialog::ShowAlphaChannel, true);
		// The ifdef block is a workaround for the beta, TODO: remove when bug 238525 is fixed
#ifdef Q_WS_MAC
		dialog.setOption(QColorDialog::DontUseNativeDialog, true);
#endif
		dialog.move(280, 120);
		if (dialog.exec() == QDialog::Rejected)
			return;
		QRgb newColor = dialog.selectedColor().rgba();
		if (newColor == m_color)
			return;
		setColor(newColor);
	}
}

void ColorEdit::setColor(QRgb color)
{
	m_color = color;
	QPalette palette = m_button->palette();
	palette.setColor(QPalette::Window, QColor(m_color));
	m_button->setPalette(palette);
	emit colorChanged(m_color);
}

ColorEdit::~ColorEdit()
{
	delete layout;
}


