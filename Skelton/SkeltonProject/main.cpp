#include <DxLib.h>
#include <iostream>

struct Vector2
{
	float x, y;
};

using Position2 = Vector2;

struct Rect
{
	Position2 center;		//中心点
	float w;				//幅
	float h;				//高さ
	float Left() const		//左の座標を返す
	{
		return center.x - w;
	}
	float Right() const	//右の座標を返す
	{
		return center.x + w;
	}
	float Top() const		//上の座標を返す
	{
		return center.y - h;
	}
	float Bottom() const	//下の座標を返す
	{
		return center.y + h;
	}
	float Widch() const
	{
		return 2.0f * w;
	}
	float Height() const
	{
		return 2.0f * h;
	}

};

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
	SetGraphMode(640, 480, 32);
	ChangeWindowMode(true);
	SetWindowText("2016200_納富泰暢");
	if (DxLib_Init() == -1)
	{
		return -1;
	}
	SetDrawScreen(DX_SCREEN_BACK);


	Rect rc{{100,100},75,75 };
	char keystate[256];

	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		ClsDrawScreen();
		GetHitKeyStateAll(keystate);
		constexpr float speed = 2.0f;

		if (keystate[KEY_INPUT_LEFT])
		{
			rc.center.x -= speed;
		}
		if (keystate[KEY_INPUT_RIGHT])
		{
			rc.center.x += speed;
		}
		if (keystate[KEY_INPUT_UP])
		{
			rc.center.y -= speed;
		}
		if (keystate[KEY_INPUT_DOWN])
		{
			rc.center.y += speed;
		}

		DrawBox(rc.Left(), rc.Top(), rc.Right(), rc.Bottom(), 0xff0000, true);

		ScreenFlip();
	}
	return 0;
}
