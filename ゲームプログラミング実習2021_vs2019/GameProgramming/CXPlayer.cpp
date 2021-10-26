#include "CXPlayer.h"
#include "CKey.h"
#include <math.h>
#include "CInput.h"

#define GRAVITY -0.03 //重力
#define WINDOW_WIDTH 800 //ウィンドウの横の長さ
#define WINDOW_HEIGHT 600 //ウィンドウの縦の長さ

CXPlayer::CXPlayer()
	:mHP(100), mJump(true)
{
	//起動時のマウスカーソルの座標を覚える
	CInput::GetMousePos(&mMouseX, &mMouseY);

	//タグにプレイヤーを設定します
	mTag = EPLAYER;
}

void CXPlayer::Init(CModelX* model)
{
	CXCharacter::Init(model);
}

void CXPlayer::Update()
{
	CInput::GetMousePos(&mx, &my);
	if (mx < mMouseX) 
	{
		//マウスの移動量の分だけ回転
		mRotation.mY += (mMouseX - mx) / 6.0;
	}
	if (mMouseX < mx) 
	{
		//マウスの移動量の分だけ回転
		mRotation.mY += (mMouseX - mx) / 6.0;
	}
	//カメラの向きが真上でなければ
	if (mRotation.mX<90)
	{
		if (my < mMouseY)
		{
			//マウスの移動量の分だけ回転
			mRotation.mX += (mMouseY - my) / 6.0;
		}
	}
	//カメラの向きが真下でなければ
	if (mRotation.mX>-90)
	{
		if (mMouseY < my)
		{
			//マウスの移動量の分だけ回転
			mRotation.mX += (mMouseY - my) / 6.0;
		}
	}

	//前に移動
	if (CKey::Push('W'))
	{
		mPosition += CVector(0.0f, 0.0f, -0.1f) * mMatrixRotate;

		//走る
		if (CKey::Push(VK_SHIFT)) 
		{
			mPosition += CVector(0.0f, 0.0f, -0.03f) * mMatrixRotate;
		}
	}

	//左に移動
	if (CKey::Push('A'))
	{
		mPosition += CVector(-0.1f, 0.0f, 0.0f) * mMatrixRotate;
	}

	//後ろに移動
	if (CKey::Push('S'))
	{
		mPosition += CVector(0.0f, 0.0f, 0.1f) * mMatrixRotate;
	}

	//右に移動
	if (CKey::Push('D'))
	{
		mPosition += CVector(0.1f, 0.0f, 0.0f) * mMatrixRotate;
	}

	//ジャンプ
	if (CKey::Once(' ') && mJump == true) 
	{
		mVec.mY = 0.5;
		mJump = false;
	}
	//着地したら次のジャンプ可能
	if (mPosition.mY <= 0)
	{
		if (mJump == true) {
			mVec.mY = 0;
		}
		mJump = true;
	}

	//重力による降下
	mPosition += mVec;

	//重力
	mVec.mY += GRAVITY;

	//HPが0以下になるとプレイヤーは消える
	if (mHP <= 0) {
		delete this;
	}

	//マウスカーソルを表示
	if (CKey::Once(VK_ESCAPE))
	{
		ShowCursor(true);
	}

	//以前のカーソル座標を新しい座標に更新
	mMouseX = mx;
	mMouseY = my;

	//カーソルがウィンドウの外に出たらウィンドウ内にカーソルを戻す
	CInput::GetMousePosW(&mMouseXw, &mMouseYw);
	//ウィンドウの右端よりカーソルが右に出たらウィンドウ内にカーソルを戻す
	if (mMouseXw > WINDOW_WIDTH)
	{
		mMouseX -= WINDOW_WIDTH;
		CInput::SetMousePos(mx - WINDOW_WIDTH, my);
	}
	//ウィンドウの左端よりカーソルが左に出たらウィンドウ内にカーソルを戻す
	if (mMouseXw < 0)
	{
		mMouseX += WINDOW_WIDTH;
		CInput::SetMousePos(mx + WINDOW_WIDTH, my);
	}
	//ウィンドウの上端よりカーソルが上に出たらウィンドウ内にカーソルを戻す
	if (mMouseYw < 0)
	{
		mMouseY += WINDOW_HEIGHT;
		CInput::SetMousePos(mx, my + WINDOW_HEIGHT);
	}
	//ウィンドウの下端よりカーソルが下に出たらウィンドウ内にカーソルを戻す
	if (mMouseYw > WINDOW_HEIGHT)
	{
		mMouseY -= WINDOW_HEIGHT;
		CInput::SetMousePos(mx, my - WINDOW_HEIGHT);
	}

	CXCharacter::Update();
}
