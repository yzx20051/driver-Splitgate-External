#pragma once

#include <string>
#include <sstream>
#include <iostream>
#include "singleton.h"
#include "imgui/imgui.h"

DWORD keys[] = { VK_LMENU, VK_MENU, VK_SHIFT, VK_RSHIFT, VK_CONTROL, VK_RCONTROL, VK_LBUTTON, VK_RBUTTON };
const char* keyItems[] = { "LAlt", "RAlt", "LShift", "RShift", "LControl", "RControl", "LMouse", "RMouse" };

inline namespace Configuration
{
	class Settings : public Singleton<Settings>
	{
	public:

		const char* BoxTypes[3] = { "2D Box","Cornered Box", "3D Box (Broken asf)"};
		const char* LineTypes[3] = { "Bottom To Enemy","Top To Enemy","Crosshair To Enemy" };


		bool b_MenuShow = true;


		bool b_Visual = false;
		bool b_EspBox = false;
		bool debug_b = false;
		bool b_EspSkeleton = false;
		bool b_EspLine = false;
		bool b_EspDistance = false;
		bool b_EspHealth  = false;
		bool b_EspName = false;
		bool b_EspAmmo = false;

		bool b_Aimbot = false;
		bool b_AimbotFOV = false;
		bool b_AimbotSmooth = false;

		bool FOVChanger = true;
		float fov = 120.f;
		bool b_NoRecoil = false;
		bool airstuck = false;

		ImColor VisibleColor = ImColor(255.f / 255, 0.f, 0.f);
		float fl_VisibleColor[3] = { 0.f,255.f / 255,0.f };  //

		ImColor InvisibleColor = ImColor(0.f, 255.f / 255, 0.f);
		float fl_InvisibleColor[3] = { 255.f / 255,0.f,0.f };  //

		ImColor FovColor = ImColor(255.f / 255, 0.f, 0.f);
		float fl_FovColor[3] = { 255.f / 255,0.f,0.f };  //

		int BoxType = 1;
		int LineType = 0;
		int tab_index = 0;
		int AimKey = 0;

		float Smoothing = 2.0f;
		float AimbotFOV = 60.0f;
		float max_distance = 300.0f;
	
	};
#define CFG Configuration::Settings::Get()
}
bool GetAimKey()
{
	return GetAsyncKeyState(keys[CFG.AimKey]);
}
