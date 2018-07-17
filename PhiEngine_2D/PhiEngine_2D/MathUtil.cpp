//*****************************************************************************
//!	@file	MathUtil.h
//!	@brief	���w�n�̊֐�
//!	@note	
//!	@author	�d�C��	2018-07-11
//*****************************************************************************

//-----------------------------------------------------------------------------
//	Include header files.
//-----------------------------------------------------------------------------
#include "CSprite2D.h"
#include "MathUtil.h"

void MakeWorldMatrix(D3DXMATRIX& mat, const D3DXVECTOR3& trans, const D3DXVECTOR3& angle, const D3DXVECTOR3& scale)
{
	D3DXMATRIX	matx, maty, matz, mattrans, matscale;
	//	�g��k��
	D3DXMatrixScaling(&matscale, scale.x, scale.y, scale.z);
	//	��]
	D3DXMatrixRotationX(&matx, D3DX_PI*angle.x / 180.0f);
	D3DXMatrixRotationY(&maty, D3DX_PI*angle.y / 180.0f);
	D3DXMatrixRotationZ(&matz, D3DX_PI*angle.z / 180.0f);
	//	�ړ�
	D3DXMatrixTranslation(&mattrans, trans.x, trans.y, trans.z);
	mat = matscale*matx*maty*matz*mattrans;
}

void MakeWorldMatrix(D3DXMATRIX& mat, D3DXMATRIX& mattotal, const D3DXVECTOR3& trans, const D3DXVECTOR3& angle, const D3DXVECTOR3& scale)
{
	D3DXMATRIX	matx, maty, matz, mattrans, matscale;
	//	�g��k��
	D3DXMatrixScaling(&matscale, scale.x, scale.y, scale.z);
	//	��]
	D3DXMatrixRotationX(&matx, D3DX_PI*angle.x / 180.0f);
	D3DXMatrixRotationY(&maty, D3DX_PI*angle.y / 180.0f);
	D3DXMatrixRotationZ(&matz, D3DX_PI*angle.z / 180.0f);
	//	�ړ�
	D3DXMatrixTranslation(&mattrans, trans.x, trans.y, trans.z);

	mat = matscale*matx*maty*matz*mattrans;
<<<<<<< HEAD
<<<<<<< Updated upstream
=======
<<<<<<< HEAD
>>>>>>> Stashed changes
	//mat = mattotal*mat;
=======
>>>>>>> dev
	mattotal = mat*mattotal;
=======
	mat = mattotal*mat;
>>>>>>> parent of a2402fe... PhiEngine
}


//*****************************************************************************
//	End of file.
//*****************************************************************************