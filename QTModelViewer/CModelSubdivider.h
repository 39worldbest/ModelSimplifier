#include"StdAfx.h"
#include"DrawWidget.h"
#define PI 3.14159265 


class ModelSubdivider{
private:
	OpenMesh::VPropHandleT< MyMesh::Point > vp_pos_; // next vertex pos
	OpenMesh::EPropHandleT< MyMesh::Point > ep_pos_; // new edge pts
	OpenMesh::FPropHandleT< MyMesh::Point > fp_pos_; // new face pts
	OpenMesh::EPropHandleT<double> creaseWeights_;// crease weights
public:
	ModelSubdivider(void);
	virtual ~ModelSubdivider(void);
	void DoSimplify(MyMesh*,size_t);
	void Init(MyMesh*);
	void Clear(MyMesh*);
	void SplitFace(MyMesh*,const MyMesh::FaceHandle&);
	void SplitEdge(MyMesh*,const MyMesh::EdgeHandle&);
	void ComputeMidpoint(MyMesh*,const MyMesh::EdgeHandle&);
	void UpdateVertex(MyMesh*,const MyMesh::VertexHandle&);
};