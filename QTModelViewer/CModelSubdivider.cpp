#include"StdAfx.h"
#include "CModelSubdivider.h"


ModelSubdivider::ModelSubdivider()
{

}
ModelSubdivider::~ModelSubdivider()
{

}

void ModelSubdivider::Init(MyMesh* mesh)
{
	mesh->add_property( vp_pos_ );
	mesh->add_property( ep_pos_ );
	mesh->add_property( fp_pos_ );
	mesh->add_property( creaseWeights_ );

	for( auto e_it = mesh->edges_begin(); e_it != mesh->edges_end(); ++e_it)
	{
		mesh->property(creaseWeights_, e_it.handle() ) = 0.0;
	}
    
}

void ModelSubdivider::Clear(MyMesh* mesh)
{
	mesh->remove_property( vp_pos_ );
	mesh->remove_property( ep_pos_ );
	mesh->remove_property( fp_pos_ );
	mesh->remove_property( creaseWeights_ );
}

void ModelSubdivider::DoSimplify(MyMesh* mesh,size_t n)
{
	Init(mesh);

	for ( size_t i = 0; i < n; ++i)
	{

		// 计算面的重心
		MyMesh::FaceIter f_itr   = mesh->faces_begin();
		MyMesh::FaceIter f_end   = mesh->faces_end();
		for ( ; f_itr != f_end; ++f_itr)
		{
		  MyMesh::Point centroid;
		  mesh->calc_face_centroid( f_itr.handle(), centroid);
		  mesh->property( fp_pos_, f_itr.handle() ) = centroid;
		}

		// 计算边的中心点
		MyMesh::EdgeIter e_itr=mesh->edges_begin();
		MyMesh::EdgeIter e_end=mesh->edges_end();
		for ( ;e_itr != e_end; ++e_itr)
		{
			ComputeMidpoint(mesh, e_itr.handle() );
		}
		  

		// 计算点的新点
		MyMesh::VertexIter v_itr = mesh->vertices_begin();
		MyMesh::VertexIter v_end = mesh->vertices_end();
		for ( ; v_itr != v_end; ++v_itr)
		{
			UpdateVertex( mesh, v_itr.handle() );
		}
	

		// 更改模型点位
		v_itr  = mesh->vertices_begin();
		for ( ; v_itr != v_end; ++v_itr)
		{
			mesh->set_point(v_itr, mesh->property( vp_pos_, v_itr ) );
		}

		// 根据之前计算好的边中点分割边
		e_itr = mesh->edges_begin();
		for ( ; e_itr != e_end; ++e_itr)
		{
			SplitEdge( mesh, e_itr.handle() );
		}

		// 根据之前计算好的面分割面片
		f_itr   = mesh->faces_begin();
		for ( ; f_itr != f_end; ++f_itr)
		{
			SplitFace(mesh, f_itr.handle());
		}
		  
	}
	
	
}

void ModelSubdivider::SplitFace(MyMesh* mesh,const MyMesh::FaceHandle& fhd)
{
	size_t valence = mesh->valence(fhd)/2;
	MyMesh::VertexHandle vh = mesh->add_vertex(mesh->property( fp_pos_, fhd ));

	MyMesh::HalfedgeHandle hend = mesh->halfedge_handle(fhd);
	MyMesh::HalfedgeHandle hh = mesh->next_halfedge_handle(hend);

	MyMesh::HalfedgeHandle hold = mesh->new_edge(mesh->to_vertex_handle(hend), vh);

	mesh->set_next_halfedge_handle(hend, hold);
	mesh->set_face_handle(hold, fhd);

	hold = mesh->opposite_halfedge_handle(hold);

	for(size_t i = 1; i < valence; i++)
	{
		MyMesh::HalfedgeHandle hnext = mesh->next_halfedge_handle(hh);

		MyMesh::FaceHandle fnew = mesh->new_face();

		mesh->set_halfedge_handle(fnew, hh);

		MyMesh::HalfedgeHandle hnew = mesh->new_edge(mesh->to_vertex_handle(hnext), vh);

		mesh->set_face_handle(hnew,  fnew);
		mesh->set_face_handle(hold,  fnew);
		mesh->set_face_handle(hh,    fnew);
		mesh->set_face_handle(hnext, fnew);

		mesh->set_next_halfedge_handle(hnew, hold);
		mesh->set_next_halfedge_handle(hold, hh);
		mesh->set_next_halfedge_handle(hh, hnext);
		hh = mesh->next_halfedge_handle(hnext);
		mesh->set_next_halfedge_handle(hnext, hnew);

		hold = mesh->opposite_halfedge_handle(hnew);
	}

	mesh->set_next_halfedge_handle(hold, hh);
	mesh->set_next_halfedge_handle(hh, hend);
	hh = mesh->next_halfedge_handle(hend);
	mesh->set_next_halfedge_handle(hend, hh);
	mesh->set_next_halfedge_handle(hh, hold);

	mesh->set_face_handle(hold, fhd);

	mesh->set_halfedge_handle(vh, hold);

}

void ModelSubdivider::SplitEdge(MyMesh* mesh,const MyMesh::EdgeHandle& ehd)
{
	MyMesh::HalfedgeHandle heh     = mesh->halfedge_handle(ehd, 0);
	MyMesh::HalfedgeHandle opp_heh = mesh->halfedge_handle(ehd, 1);

	MyMesh::HalfedgeHandle new_heh, opp_new_heh, t_heh;
	MyMesh::VertexHandle   vh;
	MyMesh::VertexHandle   vh1( mesh->to_vertex_handle(heh));
	MyMesh::Point zero(0,0,0);

	vh= mesh->new_vertex( zero );
	mesh->set_point( vh, mesh->property( ep_pos_, ehd ) );

	if (mesh->is_boundary(ehd))
	{
		for (t_heh = heh;
			mesh->next_halfedge_handle(t_heh) != opp_heh;
			t_heh = mesh->opposite_halfedge_handle(mesh->next_halfedge_handle(t_heh)))
		{}
	}
	else
	{
		for (t_heh = mesh->next_halfedge_handle(opp_heh);
			mesh->next_halfedge_handle(t_heh) != opp_heh;
			t_heh = mesh->next_halfedge_handle(t_heh) )
		{}
	}

	new_heh     = mesh->new_edge(vh, vh1);
	opp_new_heh = mesh->opposite_halfedge_handle(new_heh);
	mesh->set_vertex_handle( heh, vh );

	mesh->set_next_halfedge_handle(t_heh, opp_new_heh);
	mesh->set_next_halfedge_handle(new_heh, mesh->next_halfedge_handle(heh));
	mesh->set_next_halfedge_handle(heh, new_heh);
	mesh->set_next_halfedge_handle(opp_new_heh, opp_heh);

	if (mesh->face_handle(opp_heh).is_valid())
	{
		mesh->set_face_handle(opp_new_heh, mesh->face_handle(opp_heh));
		mesh->set_halfedge_handle(mesh->face_handle(opp_new_heh), opp_new_heh);
	}

	if( mesh->face_handle(heh).is_valid())
	{
		mesh->set_face_handle( new_heh, mesh->face_handle(heh) );
		mesh->set_halfedge_handle( mesh->face_handle(heh), heh );
	}

	mesh->set_halfedge_handle( vh, new_heh);
	mesh->set_halfedge_handle( vh1, opp_new_heh );

	mesh->adjust_outgoing_halfedge( vh );
	mesh->adjust_outgoing_halfedge( vh1 );
}

void ModelSubdivider::ComputeMidpoint(MyMesh* mesh,const MyMesh::EdgeHandle& ehd)
{
	MyMesh::HalfedgeHandle heh, opp_heh;

	heh      = mesh->halfedge_handle( ehd, 0);
	opp_heh  = mesh->halfedge_handle( ehd, 1);

	MyMesh::Point pos( mesh->point( mesh->to_vertex_handle( heh)));

	pos +=  mesh->point( mesh->to_vertex_handle( opp_heh));

	if (mesh->is_boundary(ehd) )
	{
		pos *= 0.5;
	}
	else
	{
		pos += mesh->property(fp_pos_, mesh->face_handle(heh));
		pos += mesh->property(fp_pos_, mesh->face_handle(opp_heh));
		pos *= 0.25;
	}
	mesh->property( ep_pos_, ehd ) = pos;
}

void ModelSubdivider::UpdateVertex(MyMesh* mesh,const MyMesh::VertexHandle& vhd)
{
	MyMesh::Point pos(0.0,0.0,0.0);
	if ( mesh->is_boundary( vhd))       //边界点处理
	{
		MyMesh::Normal   Vec;
		pos = mesh->point(vhd);
		MyMesh::VertexEdgeIter   ve_itr;
		for ( ve_itr = mesh->ve_iter( vhd); ve_itr; ++ve_itr)
		{
			if ( mesh->is_boundary( ve_itr.handle()))
			{
				pos += mesh->property( ep_pos_, ve_itr.handle());
			}
		}
		pos /= 3.0;
	}
	else								//非边界点处理
	{
		float valence(0.0);
		MyMesh::VOHIter voh_it = mesh->voh_iter( vhd );
		for( ; voh_it; ++voh_it )
		{
			pos += mesh->point( mesh->to_vertex_handle( voh_it ) );
			valence+=1.0;
		}
		pos /= valence*valence;
		pos*=2;
		//此处可不乘2

		MyMesh::VertexFaceIter vf_itr;
		MyMesh::Point	Q(0, 0, 0);

		for ( vf_itr = mesh->vf_iter( vhd); vf_itr; ++vf_itr) 
		{
			Q += mesh->property(fp_pos_, vf_itr.handle());
		}

		Q /= valence*valence;

		pos += mesh->point(vhd) * (valence - float(3.0) )/valence + Q;
		//pos += mesh->point(vhd) * (valence - float(2.0) )/valence + Q;

	}

	mesh->property( vp_pos_, vhd ) = pos;
}