//*****************************************************************************
//!	@file	CSprite2D.cpp
//!	@brief	2DSprite�����N���X
//!	@note	
//!	@author	�d�C��	2018-07-09
//*****************************************************************************
#pragma once
#ifndef _CSPRITE2D_H_
#define _CSPRITE2D_H_

//-----------------------------------------------------------------------------
//	Include header files.
//-----------------------------------------------------------------------------
#include	"GameUtil.h"
#include	"MathUtil.h"

<<<<<<< HEAD
#define		RIGHT		0;
#define		LEFT		1;
=======
>>>>>>> dev
//-----------------------------------------------------------------------------
//	�\���̒�`
//-----------------------------------------------------------------------------

// ���_�f�[�^�t�H�[�}�b�g
typedef struct tagVERTEX2D
{
	float x, y, z;
<<<<<<< HEAD
<<<<<<< Updated upstream
=======
<<<<<<< HEAD
>>>>>>> Stashed changes
	float rhw;
=======
>>>>>>> parent of a2402fe... PhiEngine
	float u, v;
}VERTEX2D;

//	�A�j���[�V�����N���b�v
typedef struct tagAnimationClip
{
	//	UV���_
	float originU;
	float originV;

	//	�����T�C�Y
	float divU;
	float divV;

	//	�t���[������
	unsigned int frameNum;
	//	����(�t���[��)
	unsigned int frameTime;
}AnimationClip;
=======
	float u, v;
}VERTEX2D;
>>>>>>> dev

//=============================================================================
//!	@class	CSprite2D
//!	@brief	CSprite2D�N���X
//=============================================================================
class CSprite2D
{

public:
	bool				m_isActive;		//	
	int					m_actionID;

private:
	VERTEX2D			m_v[4];			//	

	D3DXMATRIX			m_Mat;			//	�ϊ��s��
	D3DXMATRIX			m_MatTotal;		//	�ώZ�s��

<<<<<<< HEAD
	D3DXVECTOR3			m_rotation;		//	��]�p�x
	D3DXVECTOR3			m_position;		//	���S���W
	D3DXVECTOR3			m_scale;		//	�X�P�[����

	LPDIRECT3DTEXTURE9*	m_tex;			//	�e�N�X�`��
	
	//	�t���[���A�j���[�V����
	AnimationClip*		m_frameList;
	int					m_direction;
	int					m_frameCnt;

	bool				m_isTurn;
	bool				m_isAnimation;

public:

	//	�R���X�g���N�^
	CSprite2D() {
		m_direction = RIGHT;
		m_actionID = 0; 
		m_frameCnt = 0;
	}		

	//	�f�X�g���N�^
	~CSprite2D(){}						

	void Init(LPDIRECT3DDEVICE9 lpdev, LPCWSTR filename, D3DXVECTOR3& position, D3DXVECTOR3& rotation, D3DXVECTOR3& scale, bool isTurn);

	void SetAnimation(AnimationClip clip[], int actionNum);
=======
	D3DXVECTOR3			m_angle;		//	��]�p�x
	D3DXVECTOR3			m_trans;		//	�ړ���
	D3DXVECTOR3			m_scale;		//	�X�P�[����

	LPDIRECT3DTEXTURE9* m_tex;			//	�e�N�X�`��
	bool				m_isActive;		//	

public:
	CSprite2D(){}						//	�R���X�g���N�^
	~CSprite2D(){}						//	�f�X�g���N�^

	void Init(LPDIRECT3DDEVICE9 lpdev, LPCWSTR filename, D3DXVECTOR3& position, D3DXVECTOR3& rotation, D3DXVECTOR3& scale);
>>>>>>> dev

	void Update(LPDIRECT3DDEVICE9 lpdev);

	void Draw(LPDIRECT3DDEVICE9 lpdev);
	
	void Exit();

	void Translation(D3DXVECTOR3& position) { m_position = position; }
	void Rotate(D3DXVECTOR3& angle) { m_rotation = angle; }
	void Scaling(D3DXVECTOR3& scale) { m_scale = scale; }

	D3DXVECTOR3 GetPosition() { return m_position; }
	D3DXVECTOR3 GetRotation() { return m_rotation; }
	D3DXVECTOR3 GetScale() { return m_scale; }
};

<<<<<<< HEAD

=======
>>>>>>> dev
//*****************************************************************************
//	End of file.
//*****************************************************************************
#endif