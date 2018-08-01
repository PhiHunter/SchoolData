//*****************************************************************************
//!	@file	game.cpp
//!	@brief	�Q�[������
//!	@note	
//!	@author	
//*****************************************************************************

//-----------------------------------------------------------------------------
//	Include header files.
//-----------------------------------------------------------------------------
#include "game.h"

//-----------------------------------------------------------------------------
// �O���[�o���ϐ�
//-----------------------------------------------------------------------------
CDirectXGraphics	*g_DXGrobj = nullptr;		// DirectX Graphics�I�u�W�F�N�g

D3DXMATRIX			g_MatView;			// �J�����s��
D3DXMATRIX			g_MatProjection;	// �v���W�F�N�V�����ϊ��s��
D3DXMATRIX			g_MatWorld;			// ���[���h�ϊ��s��

HANDLE				g_hEventHandle;		// �C�x���g�n���h��
bool				g_EndFlag = false;	// �I���t���O
std::thread			g_gamemainthread;	// �Q�[�����C���X���b�h

SceneType			g_SceneStage;

CSprite2D			g_player;
<<<<<<< HEAD
CSprite2D			g_player2;
=======
>>>>>>> dev

//=============================================================================
//!	@fn		GameInit
//!	@brief	�Q�[����������
//!	@param	�C���X�^���X�l
//!	@param	�E�C���h�E�n���h���l
//!	@param	�E�C���h�E�T�C�Y���i�␳�ς݂̒l�j
//!	@param	�E�C���h�E�T�C�Y�����i�␳�ς݂̒l�j
//!	@param�@	�t���X�N���[���t���O�@true ; �t���X�N���[���@false : �E�C���h�E
//!	@retval	true �����@false ���s
//=============================================================================
bool GameInit(HINSTANCE hinst, HWND hwnd, int width, int height, bool fullscreen)
{
	bool sts;
	g_DXGrobj = new CDirectXGraphics();	// DirectX Graphics�I�u�W�F�N�g����
	sts = g_DXGrobj->Init(hwnd, fullscreen, width, height);	// DirectX Graphics�I�u�W�F�N�g������

	if (!sts) {
		MessageBox(hwnd, L"ERROR!!", L"DirectX �������G���[", MB_OK);
		return false;
	}

	// �J�����ϊ��s��쐬
	D3DXMatrixLookAtLH(&g_MatView,
		&D3DXVECTOR3(0.0f, 0.0f, -10.0f),		// ���_
		&D3DXVECTOR3(0.0f, 0.0f, 0.0f),		// �����_
		&D3DXVECTOR3(0.0f, 1.0f, 0.0f));		// �����

												// �J�����s����Œ�p�C�v���C���փZ�b�g
	g_DXGrobj->GetDXDevice()->SetTransform(D3DTS_VIEW, &g_MatView);

	// �v���W�F�N�V�����ϊ��s��쐬
	D3DXMatrixPerspectiveFovLH(&g_MatProjection,
		D3DX_PI / 2,					// ����p
		(float)width / (float)height,	// �A�X�y�N�g��
		1.0f,						// �j�A�v���[��
		1000.0f);					// �t�@�[�v���[��

	// �ˉe�ϊ��s����Œ�p�C�v���C���փZ�b�g
	g_DXGrobj->GetDXDevice()->SetTransform(D3DTS_PROJECTION, &g_MatProjection);
	// �y�o�b�t�@�L��
	g_DXGrobj->GetDXDevice()->SetRenderState(D3DRS_ZENABLE, TRUE);

	g_DXGrobj->GetDXDevice()->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);
	// ���C�g�L��
	g_DXGrobj->GetDXDevice()->SetRenderState(D3DRS_LIGHTING, false);

	//�A���t�@�u�����f�B���O��ݒ肷��
	g_DXGrobj->GetDXDevice()->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
	g_DXGrobj->GetDXDevice()->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	g_DXGrobj->GetDXDevice()->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);

	// �e�N�X�`���X�e�[�W�X�e�[�g
	g_DXGrobj->GetDXDevice()->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_MODULATE);
	g_DXGrobj->GetDXDevice()->SetTextureStageState(0, D3DTSS_ALPHAARG1, D3DTA_TEXTURE);
	g_DXGrobj->GetDXDevice()->SetTextureStageState(0, D3DTSS_ALPHAARG2, D3DTA_DIFFUSE);

	// DirectT Input������
	InitInput(hinst, hwnd);

	// �C�x���g�n���h������
	g_hEventHandle = CreateEvent(NULL, false, false, NULL);
	if (g_hEventHandle == NULL) {
		MessageBox(hwnd, L"ERROR!!", L"CreateEvent �G���[", MB_OK);
		return false;
	}

	// �X���b�h����(�Q�[�����C��)
	g_gamemainthread = std::thread(GameMain);

	//g_GameState = SceneTitle;
	g_SceneStage = SceneTitle;



<<<<<<< HEAD
<<<<<<< Updated upstream
=======
<<<<<<< HEAD
>>>>>>> Stashed changes
	g_player.Init(g_DXGrobj->GetDXDevice(), L"heromagic.bmp", D3DXVECTOR3(0, 3, 1), D3DXVECTOR3(0, 0, 0), D3DXVECTOR3(1, 1, 1), true);
=======
	g_player.Init(g_DXGrobj->GetDXDevice(), L"heromagic.bmp", D3DXVECTOR3(0, 3, 1), D3DXVECTOR3(0, 0, 0), D3DXVECTOR3(2, 2, 2), true);
>>>>>>> parent of a2402fe... PhiEngine

	g_player2.Init(g_DXGrobj->GetDXDevice(), L"DX.png", D3DXVECTOR3(0, 3, 0), D3DXVECTOR3(0, 0, 0), D3DXVECTOR3(3, 3, 3), false);
	AnimationClip tmpc[2] = {
		{0,0,0.2f,0.5f,4,50},
		{ 0,0.5f,0.2f,0.5f,5 ,10}
	};
	g_player2.SetAnimation(tmpc, 2);
=======
	g_player.Init(g_DXGrobj->GetDXDevice(), L"heromagic.bmp", D3DXVECTOR3(0, 0, 0), D3DXVECTOR3(0, 0, 0), D3DXVECTOR3(1, 1, 1));
>>>>>>> dev
	return	true;
}

//=============================================================================
//!	@fn		GameInput
//!	@brief	�Q�[�����͌��m����
//!	@param�@	
//!	@retval	�Ȃ�
//=============================================================================
void GameInput() {
	UpdateInput();				// ���͂����m����
<<<<<<< HEAD
<<<<<<< Updated upstream
=======
<<<<<<< HEAD
>>>>>>> Stashed changes
	
=======

>>>>>>> dev
<<<<<<< Updated upstream
=======
=======

>>>>>>> parent of a2402fe... PhiEngine
>>>>>>> Stashed changes
}

//=============================================================================
//!	@fn		GameUpdate
//!	@brief	�Q�[���X�V����
//!	@param�@	
//!	@retval	�Ȃ�
//=============================================================================
void GameUpdate() {
<<<<<<< HEAD
<<<<<<< Updated upstream
=======
<<<<<<< HEAD
>>>>>>> Stashed changes
	if (Collision2D(g_player, g_player2))
	{
		g_player2.m_actionID = 1;
	}
	else
	{
		g_player2.m_actionID = 0;
	}
=======
>>>>>>> parent of a2402fe... PhiEngine
	g_player.Update(g_DXGrobj->GetDXDevice());
	g_player2.Update(g_DXGrobj->GetDXDevice());
=======
	g_player.Update(g_DXGrobj->GetDXDevice());
>>>>>>> dev
}

//=============================================================================
//!	@fn		GameRender
//!	@brief	�Q�[���X�V����
//!	@param�@	
//!	@retval	�Ȃ�
//=============================================================================
void GameRender() {
	HRESULT  hr;
	RECT formatRect;
	formatRect.left = SCREEN_WIDTH / 2.0 - 80;
	formatRect.top = 0;
	// �^�[�Q�b�g�o�b�t�@�̃N���A�A�y�o�b�t�@�̃N���A
	g_DXGrobj->GetDXDevice()->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, D3DCOLOR_XRGB(0, 0, 0), 1.0f, 0);

	// �`��̊J�n���c�h�q�d�b�s�w�ɒʒm
	g_DXGrobj->GetDXDevice()->BeginScene();

	switch (g_SceneStage)
	{
	case SceneTitle:
	{

		break;
	}
	case SceneRun:
	{
		break;
	}
	case SceneEnd:
	{
		break;
	}
	default:
		break;
	}
	g_player.Draw(g_DXGrobj->GetDXDevice());
<<<<<<< HEAD
	g_player2.Draw(g_DXGrobj->GetDXDevice());
=======
>>>>>>> dev
	//DrawTriangle(g_DXGrobj->GetDXDevice(), g_pTex1);
	g_DXGrobj->GetDXDevice()->EndScene();	// �`��̏I����҂�


	hr = g_DXGrobj->GetDXDevice()->Present(NULL, NULL, NULL, NULL);	// �o�b�N�o�b�t�@����v���C�}���o�b�t�@�֓]��
	if (hr != D3D_OK) {
		g_DXGrobj->GetDXDevice()->Reset(&g_DXGrobj->GetDXD3dpp());
	}
}

//=============================================================================
//!	@fn		GameMain
//!	@brief	�Q�[�����[�v����
//!	@param�@	
//!	@retval	�Ȃ�
//=============================================================================
void GameMain()
{
	while (1) {
		DWORD sts = WaitForSingleObject(g_hEventHandle, 1000);	// �C�x���g�t���O���Z�b�g�����̂�҂i1000ms�Ń^�C���A�E�g�j
		if (sts == WAIT_FAILED) {
			break;
		}
		else if (sts == WAIT_TIMEOUT) {
			if (g_EndFlag) {
				break;
			}
			continue;
		}

		GameInput();					// ����
		GameUpdate();					// �X�V
		GameRender();					// �`��
	}
}

//=============================================================================
//!	@fn		GameExit
//!	@brief	�Q�[���I������
//!	@param�@	
//!	@retval	�Ȃ�
//=============================================================================
void GameExit()
{
	g_player.Exit();
<<<<<<< HEAD
	g_player2.Exit();
=======
>>>>>>> dev
	g_gamemainthread.join();					// �Q�[�����C���X���b�h�̏I����҂�

	CloseHandle(g_hEventHandle);				// �C�x���g�n���h���N���[�Y

	if (g_DXGrobj != nullptr) {
		g_DXGrobj->Exit();						// DirectX�̃O���t�B�b�N�I�u�W�F�N�g�̏I������
		delete g_DXGrobj;
		g_DXGrobj = nullptr;
	}

	// DirectT Input�I������
	UninitInput();
}

//=============================================================================
//!	@fn		GameSetEvent
//!	@brief	�Q�[�����[�v���̃C�x���g�I�u�W�F�N�g���Z�b�g����
//!	@param�@	
//!	@retval	�Ȃ�
//=============================================================================
void GameSetEvent() {
	if (!g_EndFlag) {
		SetEvent(g_hEventHandle);	// �I���t���O���Z�b�g����Ă��Ȃ���΃C�x���g���Z�b�g����
	}
}

//=============================================================================
//!	@fn		GameSetEndFlag
//!	@brief	�Q�[�����[�v�̏I���t���O���Z�b�g����
//!	@param�@	
//!	@retval	�Ȃ�
//=============================================================================
void GameSetEndFlag() {
	g_EndFlag = true;				// �I���t���O���I���ɂ���
}

//*****************************************************************************
//	End of file.
//*****************************************************************************