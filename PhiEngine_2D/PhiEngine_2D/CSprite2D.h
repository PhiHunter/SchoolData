//*****************************************************************************
//!	@file	CSprite2D.cpp
//!	@brief	2DSpriteNX
//!	@note	
//!	@author	dCท	2018-07-09
//*****************************************************************************
#pragma once
#ifndef _CSPRITE2D_H_
#define _CSPRITE2D_H_

#include	"GameUtil.h"



class CSprite2D
{
private:
	D3DXMATRIX		m_Mat;				//	ฯทs๑
	D3DXMATRIX		m_MatTotal;			//	ฯZs๑

	D3DXVECTOR3		m_angle;			//	๑]px
	D3DXVECTOR3		m_trans;			//	ฺฎส

	LPDIRECT3DTEXTURE9* m_tex;			//	eNX`
	bool			m_isActive;			//	

public:
	CSprite2D(LPCWSTR filename);
	~CSprite2D();

	void Init(LPDIRECT3DDEVICE9 lpdev);

	void Update(LPDIRECT3DDEVICE9 lpdev);

	void Draw(LPDIRECT3DDEVICE9 lpdev);
	
	void Exit();

};



#endif