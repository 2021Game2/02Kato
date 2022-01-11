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

void CSceneGame::Update() {
	//マウスカーソルを非表示
	ShowCursor(false);
	CTaskManager::Get()->Update();
	
	//衝突処理
	//CCollisionManager::Get()->Collision();
	CTaskManager::Get()->TaskCollision();

	//カメラのパラメータを作成する
	CVector e, c, u;//視点、注視点、上方向
	//視点を求める
	e = mPlayer.mPosition;
	//注視点を求める
	c = mPlayer.mPosition + CVector(0.0f, 0.0f, 1.0f) * mPlayer.mMatrixRotate;
	//上方向を求める
	u = CVector(0.0f, 1.0f, 0.0f) * mPlayer.mMatrixRotate;

	/*e = mPlayer.mHandgun.mPosition + CVector(0.0f, 0.0f, 1.0f);
	c = mPlayer.mHandgun.mPosition;
	u = CVector(0.0f, 1.0f, 0.0f) * mPlayer.mHandgun.mMatrixRotate;
	*/

	/*e = CVector(0.0f, 4.0f, 5.0f);
	c = mPlayer.mPosition;
	u = CVector(0.0f, 1.0f, 0.0f) * mPlayer.mMatrixRotate;
	*/
	

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

	//描画
	CTaskManager::Get()->Render();

	//コライダの描画
	CCollisionManager::Get()->Render();

	return;
}

