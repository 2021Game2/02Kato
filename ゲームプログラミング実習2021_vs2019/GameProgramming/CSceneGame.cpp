#include "CSceneGame.h"
//
#include "CCamera.h"
//
#include "CUtil.h"
//
#include "CRes.h"

#include "Ckey.h"
//
#include "CMaterial.h"
//
#include "CCollisionManager.h"
//
#include "CInput.h"

CMatrix Matrix;

CSceneGame::~CSceneGame() {

}

void CSceneGame::Init() {

	CRes::sModelX.Load(MODEL_FILE);
	//キャラクターにモデルを設定
	mPlayer.Init(&CRes::sModelX);

}


void CSceneGame::Update() {

	//プレイヤークラスの更新
	mPlayer.Update();
	
	//衝突処理
	CCollisionManager::Get()->Collision();

	//カメラのパラメータを作成する
	CVector e, c, u;//視点、注視点、上方向
	//視点を求める
	e = mPlayer.mPosition;
	//注視点を求める
	c = mPlayer.mPosition + CVector(0.0f, 0.0f, -1.0f) * mPlayer.mMatrixRotate;
	//上方向を求める
	u = CVector(0.0f, 1.0f, 0.0f) * mPlayer.mMatrixRotate;

	//カメラクラスの設定
	Camera.Set(e, c, u);
	Camera.Render();

	//X軸＋回転
	if (CKey::Push('K')) {
		Matrix = Matrix * CMatrix().RotateX(1);
	}
	if (CKey::Push('I')) {
		Matrix = Matrix * CMatrix().RotateX(-1);
	}
	//Y軸＋回転
	if (CKey::Push('L')) {
		Matrix = Matrix * CMatrix().RotateY(1);
	}
	if (CKey::Push('J')) {
		Matrix = Matrix * CMatrix().RotateY(-1);
	}

	//行列設定
	glMultMatrixf(Matrix.mF);

	//マウスカーソルを非表示
	ShowCursor(false);

	//描画
	mPlayer.Render();
	mFloor.Render();

	//コライダの描画
	CCollisionManager::Get()->Render();

	//マウスカーソルを起動時の座標に移動
	//CInput::SetMousePos(CXPlayer::mpPlayer->mMouseX, CXPlayer::mpPlayer->mMouseY);
	CInput::SetMousePos(mPlayer.mx, mPlayer.my);

	return;
}

